#include "NMCS.hpp"
#include "func.hpp"

using std::make_pair;

NMCS::NMCS(const size_t n, const int level)
: n{n}
, startingLevel{level}
, countBuffer{new int[n]} {}

NMCS::~NMCS() {
	delete[] countBuffer;
}

NMCS::Playout NMCS::generate() {
	return nestedSearch("", startingLevel);
}

NMCS::Playout NMCS::operator()() {
	return generate();
}

NMCS::Playout NMCS::nestedSearch(State s, int level) {
	Playout res = make_pair(s, -1);

	while (s.length() < n) {
		Move best = MOVES[0];
		int bestScore = -1;

		//find the best move
		for (Move m: MOVES) {
			Playout tmp = (level == 1) ? samplePlayout(play(s, m)) :
					nestedSearch(play(s, m), level - 1);

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


