#ifndef NRPA_HPP
#define NRPA_HPP
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
	virtual Playout generate(const int level, const int numberOfPlayouts);

	Playout operator()(const int level, const int numberOfPlayouts);

	const float ALPHA = 1.0f;

protected:
	/**
	 * @brief Performs a Nested Rollout Policy Adaptation with parameter level;
	 */
	Playout nestedSearch(const int level, std::unordered_map<std::string, float> pol, const int numberOfPlayouts);

	/**
	 * @brief Performs a random playout starting from the root.
	 */
	Playout samplePlayout(std::unordered_map< std::string, float >& pol);

	void adapt(const State& s, std::unordered_map<std::string, float>& pol);

 	std::unordered_map<std::string, float> bestPolicy;	//std::string so that it compiles
							//without having to implement hash for Playout 'type'

	
	Playout getRoot() const;
	int bestScore;
	
private:
	const std::vector<Move> MOVES = {'0', '1'};
	const size_t n;
	unsigned int* countBuffer;
};

#endif // NRPA_HPP
