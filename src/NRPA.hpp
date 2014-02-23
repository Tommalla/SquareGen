#ifndef NMCS_H
#define NMCS_H
#include <string>
#include <set>
#include <vector>
#include <unordered_map>

#include "types.hpp"

/**
 * @brief This class represents a single instance of NRPA algorithm.
 * It is *not* thread-safe to run the same instance.
 */
class NRPA {
public:
	NRPA(const size_t n);
	~NRPA();

	/**
	 * @brief This function generates the best string of length n.
	 */
	Playout generate(const int level, const int numberOfPlayouts);

	Playout operator()(const int level, const int numberOfPlayouts);

	const float ALPHA = 1.0f;

private:
	const std::vector<Move> MOVES = {'0', '1'};
	const size_t n;
	unsigned int* countBuffer;
 	std::unordered_map<std::string, float> bestPolicy;	//std::string so that it compiles
							//without having to implement hash for Playout 'type'
	int bestScore;

	/**
	 * @brief Performs a Nested Rollout Policy Adaptation with parameter level;
	 */
	Playout nestedSearch(const int level, std::unordered_map<std::string, float> pol, const int numberOfPlayouts);

	/**
	 * @brief Performs a random playout starting from the root.
	 */
	Playout samplePlayout(std::unordered_map< std::string, float >& pol);

	Playout getRoot() const;

	void adapt(const State& s, std::unordered_map<std::string, float>& pol);
};

#endif // NMCS_H
