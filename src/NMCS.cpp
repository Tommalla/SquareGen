#include "NMCS.hpp"
#include "func.hpp"

using namespace NMCS;
using std::make_pair;

Playout NMCS::generate(const size_t n, const int level, int* countBuffer) {
	return nestedSearch("", n, level, countBuffer);
}

Playout NMCS::nestedSearch(State s, const size_t n, int level, int* countBuffer) {
	Playout res = make_pair(s, -1);

	while (s.length() < n) {
		Move best = MOVES[0];
		int bestScore = -1;

		//find the best move
		for (Move m: MOVES) {
			Playout tmp = (level == 1) ? samplePlayout(play(s, m), n, countBuffer) :
					nestedSearch(play(s, m), n, level - 1, countBuffer);

			if (bestScore < tmp.second) {
				best = m;
				bestScore = tmp.second;
			}

			if (res.second < tmp.second)
				res = tmp;
		}

		s = play(s, best);
	}

	return res;
}

State NMCS::play(const State& s, const Move move) {
	State res = s;
	res.push_back(move);
	return res;
}

Playout NMCS::samplePlayout(State s, const size_t n, int* countBuffer) {
	while (s.length() < n)
		s = play(s, MOVES[random() % MOVES.size()]);
	return make_pair(s, countSquares(s, countBuffer));
}


