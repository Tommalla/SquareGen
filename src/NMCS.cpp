#include "NMCS.hpp"
#include "func.hpp"

using std::make_pair;
using namespace func;

NMCS::NMCS(const size_t n, const int startingLevel, const bool rememberBest)
: AbstractMCS::AbstractMCS{n, startingLevel, rememberBest}
, bestPlayout{"", -1} {}

Playout NMCS::generate() {
	Playout res = nestedSearch("", bestPlayout, startingLevel);

	if (rememberBest && res.second > bestPlayout.second)
		bestPlayout = res;
	return res;
}

Playout NMCS::nestedSearch(State s, const Playout& bestAvailable, int level) {
	Playout res = (bestAvailable.first.length() < n) ? make_pair(s, -1) : bestAvailable;

	while (s.length() < n) {
		Move best = MOVES[0];
		int bestScore = -1;

		//find the best move
		for (Move m: MOVES) {
			Playout tmp = (level == 0) ? samplePlayout(play(s, m)) :
					nestedSearch(play(s, m), res, level - 1);

			if (bestScore < tmp.second) {
				best = m;
				bestScore = tmp.second;
			}

			if (res.second < tmp.second)
				res = tmp;
		}

		if (bestScore < bestAvailable.second)
			best = bestAvailable.first[s.length()];

		s = play(s, best);
	}

	if (res.second == bestAvailable.second && res.first != bestAvailable.first)
		res.second = countSquares(res.first, countBuffer);

	return res;
}

Playout NMCS::samplePlayout(State s) {
	while (s.length() < n)
		s = play(s, MOVES[random() % MOVES.size()]);
	return make_pair(s, countSquares(s, countBuffer));
}
