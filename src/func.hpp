#ifndef FUNC_HPP
#define FUNC_HPP
#include <string>

#include "types.hpp"

namespace func {
	const unsigned int X = 41;	//hash const

	/**
	 * @brief Returns the count of squares in str.
	 * This method can be non-deterministic as it uses hashes. The complexity is O(n^2),
	 * where n is the length of str.
	 *
	 * @param hashTab Defaults to nullptr. An optional argument. It's a buffer used for the calculation.
	 * If not passed, it will be created on heap.
	 */
	int countSquares(const std::string& str, unsigned int* hashTab = nullptr);

	/**
	 * @brief The deterministic version of countSquares. It runs in O(n^3) time.
	 */
	int deterministicCountSquares(const std::string& str);

	/**
	 * @brief A helper method used by countSquares. It calculates the n-th power of X in average constant time.
	 *
	 * @param n Maximum value is 999.
	 */
	unsigned int powX(const int n);

	/**
	 * @brief Checks if strint a is the same as the substring [begin; end] of the string bWhole.
	 * This method assumes that end - begin + 1 == a.length().
	 *
	 * @return bool True if the strings are equal. Otherwise false.
	 */
	bool isEqual(const std::string& a, const std::string& bWhole, const int& begin, const int& end);

	/**
	 * @brief Returns the state after playing a move.
	 *
	 * @param s The initial state
	 * @param move The move to be made
	 */
	State play(const State& s, const Move move);

    inline void makeMove(State& s, const Move move);
};

#endif // FUNC_HPP