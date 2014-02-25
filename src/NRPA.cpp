#include <cmath>

#include "NRPA.hpp"
#include "func.hpp"

using std::make_pair;
using std::unordered_map;
using std::vector;
using std::string;
using namespace func;

NRPA::NRPA(const size_t n)
: bestScore{-1}
, n{n}
, countBuffer{new unsigned int[n]} {}

NRPA::~NRPA() {
	delete[] countBuffer;
}

Playout NRPA::generate(const int level, const int numberOfPlayouts) {
	unordered_map<string, float> startingPolicy;
	startingPolicy = bestPolicy;

	Playout res = nestedSearch(level, startingPolicy, numberOfPlayouts);
	int realScore = deterministicCountSquares(res.first);
	if (realScore != res.second) {
		puts("Error in countSquares!");
		res.second = realScore;
	}
	return res;
}

Playout NRPA::operator()(const int level, const int numberOfPlayouts) {
	return generate(level, numberOfPlayouts);
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

	if (res.second > bestScore) {
		bestScore = res.second;
		bestPolicy = pol;
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
		s = play(s, chosen);
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

		changed[play(cur, m)] += ALPHA;
		float z = 0.0f;
		for (Move next: MOVES) {
			states.push_back(play(cur, next));
			exps.push_back(exp(pol[states.back()]));
			z += exps.back();
		}

		for (size_t i = 0; i < exps.size(); ++i)
			changed[states[i]] -= ALPHA * exps[i] / z;

		cur = play(cur, m);
	}

	for (auto c: changed)
		pol[c.first] += c.second;
}

