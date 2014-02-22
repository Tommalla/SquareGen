#ifndef NMCS_HPP
#define NMCS_HPP
#include <string>
#include <utility>
#include <vector>

#include "types.hpp"

/**
 * @brief This class represents a single instance of NMCS algorithm.
 * It is *not* thread-safe to run the same instance.
 *
 */
class NMCS {
public:
	NMCS(const size_t n);
	~NMCS();

	/**
	 * @brief This function generates the best string of length n.
	 */
	Playout generate(const int level);

	Playout operator()(const int level);

private:
	const std::vector<char> MOVES = {'0', '1'};
	const size_t n;
	unsigned int* countBuffer;
	Playout bestPlayout;

	/**
	 * @brief Performs a Nested Monte Carlo Search with parameter level; starting from state s, knowing that there
	 * are n moves to be made before the end of game.
	 */
	Playout nestedSearch(State s, const Playout& bestAvailable, int level);


	/**
	 * @brief Performs a random playout starting from state s.
	 */
	Playout samplePlayout(State s);
};

#endif // NMCS_HPP
