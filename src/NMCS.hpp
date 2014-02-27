#ifndef NMCS_HPP
#define NMCS_HPP
#include <string>
#include <utility>
#include <vector>

#include "AbstractMCS.hpp"
#include "types.hpp"

/**
 * @brief This class represents a single instance of NMCS algorithm.
 * It is *not* thread-safe to run the same instance.
 *
 */
class NMCS : public AbstractMCS {
public:
	NMCS(const size_t n, const int startingLevel, const bool rememberBest = true);

protected:
	/**
	 * @brief This function generates the best string of length n.
	 */
	virtual Playout generate();
	virtual void resetMemory();
	virtual void setBest(Playout&& p);

private:
	/**
	 * @brief Performs a Nested Monte Carlo Search with parameter level; starting from state s, knowing that there
	 * are n moves to be made before the end of game.
	 */
	Playout nestedSearch(State s, const Playout& bestAvailable, int level);

	/**
	 * @brief Performs a random playout starting from state s.
	 */
	Playout samplePlayout(State s);

	Playout bestPlayout;
};

#endif // NMCS_HPP
