#ifndef NMCS_H
#define NMCS_H
#include <string>
#include <set>
#include <vector>

/**
 * @brief This class represents a single instance of NMCS algorithm.
 * It is *not* thread-safe to run the same instance.
 *
 */
class NMCS {
public:
	typedef std::string State;
	/**
	 * @brief A pair<sequence, score> representing a whole playout til the end of game.
	 *
	 */
	typedef std::pair<State, int> Playout;
	typedef char Move;

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
	int* countBuffer;
	Playout bestPlayout;

	/**
	 * @brief Performs a Nested Monte Carlo Search with parameter level; starting from state s, knowing that there
	 * are n moves to be made before the end of game.
	 */
	Playout nestedSearch(NMCS::State s, const NMCS::Playout& bestAvailable, int level);

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
	Playout samplePlayout(NMCS::State s);
};

#endif // NMCS_H
