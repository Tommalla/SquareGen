#ifndef NMCS_H
#define NMCS_H
#include <string>
#include <set>

namespace NMCS {
	typedef std::string State;
	typedef std::pair<State, int> Playout;
	typedef char Move;

	/**
	 * @brief This function generates the best string of length n.
	 */
	Playout generate(const int n, const int level);

	//FIXME add docstrings and reorder
	Playout nestedSearch(const NMCS::State& s, const int n, int level);
	State play(const State& s, const Move move);
	Playout samplePlayout(State s);
};

#endif // NMCS_H
