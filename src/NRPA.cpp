#include <cmath>

#include "NRPA.hpp"
#include "func.hpp"

using std::make_pair;
using std::unordered_map;
using std::vector;
using std::string;
using namespace func;

NRPA::NRPA(const size_t n, const int startingLevel, const int numberOfPlayouts,
	   const float alpha, const bool rememberBest)
: AbstractMCS{n, startingLevel, rememberBest}
, bestScore{-1}
, numberOfPlayouts{numberOfPlayouts}
, mutated{false}
, alpha{alpha} {}


void NRPA::resetMemory() {
	bestScore = -1;
	bestPolicy.clear();
}

void NRPA::combinePolicies(const unordered_map< string, float >& toAdd) {
	for (auto k: toAdd)
		bestPolicy[k.first] = (bestPolicy[k.first] + k.second) / 2;
}


void NRPA::setBest(Playout&& p) {
	bestScore = p.second;

	for (int i = 0; i < ADAPTS_OF_BEST; ++i)
		adapt(p.first, bestPolicy);
}

void NRPA::mutateBestSolution() {
	for (auto& k: bestPolicy)
		if (randomTest(MUTATION_PROBABILITY)) {
			bestPolicy[k.first]  += alpha;
		}
	mutated = true;
}


float NRPA::getAlpha() const {
	return alpha;
}

Playout NRPA::generate() {
	return nestedSearch(startingLevel, bestPolicy, numberOfPlayouts);
}

Playout NRPA::nestedSearch(const int level, unordered_map<string, float> pol, const int numberOfPlayouts) {
	if (level == 0)
		return samplePlayout(pol);

	Playout res = getRoot();
	for (int p = 0; p < numberOfPlayouts; ++p) {
		Playout tmp = nestedSearch(level - 1, pol, numberOfPlayouts);
		if (tmp.second > res.second)
			res = tmp;
		adapt(res.first, pol);
	}

	if (rememberBest) {
		if (mutated || res.second > bestScore) {
			mutated = false;
			bestScore = res.second;
			bestPolicy = pol;
		}
	}

	return res;
}

Playout NRPA::samplePlayout(unordered_map<string, float>& pol) {
	State s = "";	//start from the root

	while (s.length() < n) {
		//calculate the base of our probability
		float sum = 0.0f;
		for (Move m: MOVES)
			sum += exp(pol[play(s, m)]);

		//find the proper random move
		int id = random() % (int)ceil(sum);
		sum = 0.0f;
		Move chosen = MOVES[0];
		for (Move m: MOVES) {
			sum += exp(pol[play(s, m)]);
			if (sum >= id) {
				chosen = m;
				break;
			}
		}

		//perform the move
		makeMove(s, chosen);
	}

	return make_pair(s, countSquares(s, countBuffer));
}

Playout NRPA::getRoot() const {
	return make_pair("", -1);
}

void NRPA::adapt(const State& s, unordered_map<string, float>& pol) {
	unordered_map<std::string, float> changed;
	State cur = "";
	vector<float> exps;
	vector<State> states;

	for(Move m: s) {
		exps.clear();
		states.clear();

		changed[play(cur, m)] += alpha;
		float z = 0.0f;
		for (Move next: MOVES) {
			states.push_back(play(cur, next));
			exps.push_back(exp(pol[states.back()]));
			z += exps.back();
		}

		for (size_t i = 0; i < exps.size(); ++i)
			changed[states[i]] -= alpha * exps[i] / z;

		makeMove(cur, m);
	}

	for (auto c: changed)
		pol[c.first] += c.second;
}

