#ifndef FUNC_HPP
#define FUNC_HPP
#include <string>

#include "types.hpp"

namespace func {
	int countSquares(const std::string& str, int* pref);

	/**
	 * @brief Returns the state after playing a move.
	 *
	 * @param s The initial state
	 * @param move The move to be made
	 */
	State play(const State& s, const Move move);
};

#endif // FUNC_HPP