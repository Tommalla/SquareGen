#ifndef NMCS_H
#define NMCS_H
#include <string>
#include <set>
#include <vector>

namespace NMCS {
	typedef std::string State;
	/**
	 * @brief A pair<sequence, score> representing a whole playout til the end of game.
	 *
	 */
	typedef std::pair<State, int> Playout;
	typedef char Move;

	const std::vector<char> MOVES = {'0', '1'};

	/**
	 * @brief This function generates the best string of length n.
	 */
	Playout generate(const size_t n, const int level, int* countBuffer);


	/**
	 * @brief Performs a Nested Monte Carlo Search with parameter level; starting from state s, knowing that there
	 * are n moves to be made before the end of game.
	 */
	Playout nestedSearch(NMCS::State s, const size_t n, int level, int* countBuffer);

	/**
	 * @brief Returns the state after playing a move.
	 *
	 * @param s The initial state
	 * @param move The move to be made
	 */
	State play(const NMCS::State& s, const NMCS::Move move);

	/**
	 * @brief Performs a random playout starting from state s.
	 */
	Playout samplePlayout(NMCS::State s, const size_t n, int* countBuffer);
};

#endif // NMCS_H
