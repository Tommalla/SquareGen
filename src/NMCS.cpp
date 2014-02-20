#include "NMCS.hpp"
#include "func.hpp"

using std::make_pair;

NMCS::NMCS(const size_t n)
: n{n}
, countBuffer{new int[n]}
, bestPlayout("", -1) {}

NMCS::~NMCS() {
	delete[] countBuffer;
}

NMCS::Playout NMCS::generate(const int level) {
// 	bestPlayout = make_pair("", -1);
	Playout res = nestedSearch("", bestPlayout, level);
	if (res.second > bestPlayout.second)
		bestPlayout = res;
	return res;
}

NMCS::Playout NMCS::operator()(const int level) {
	return generate(level);
}

NMCS::Playout NMCS::nestedSearch(NMCS::State s, const Playout& bestAvailable, int level) {
	Playout res = bestAvailable;

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

	return res;
}

NMCS::State NMCS::play(const State& s, const Move move) {
	State res = s;
	res.push_back(move);
	return res;
}

NMCS::Playout NMCS::samplePlayout(NMCS::State s) {
	while (s.length() < n)
		s = play(s, MOVES[random() % MOVES.size()]);
	return make_pair(s, countSquares(s, countBuffer));
}


