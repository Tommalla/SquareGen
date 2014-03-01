#ifndef NRPA_HPP
#define NRPA_HPP
#include <string>
#include <set>
#include <vector>
#include <unordered_map>

#include "AbstractMCS.hpp"
#include "types.hpp"

/**
 * @brief This class represents a single instance of NRPA algorithm.
 * It is *not* thread-safe to run the same instance.
 */
class NRPA : public AbstractMCS {
public:
	NRPA(const size_t n, const int startingLevel, const int numberOfPlayouts = 100,
	     const float alpha = 1.0f, const bool rememberBest = true);

	virtual void resetMemory();
	virtual void mutateBestSolution();

	float getAlpha() const;
protected:
	void combinePolicies(const std::unordered_map<std::string, float>& toAdd);
	virtual void setBest(Playout&& p);
	/**
	 * @brief This function generates the best string of length n.
	 */
	virtual Playout generate();

	/**
	 * @brief Performs a Nested Rollout Policy Adaptation with parameter level
	 */
	virtual Playout nestedSearch(const int level, std::unordered_map<std::string, float> pol, const int numberOfPlayouts);

	/**
	 * @brief Performs a random playout starting from the root.
	 */
	Playout samplePlayout(std::unordered_map< std::string, float >& pol);

	void adapt(const State& s, std::unordered_map<std::string, float>& pol);

	Playout getRoot() const;

	std::unordered_map<std::string, float> bestPolicy;	//std::string so that it compiles
							//without having to implement hash for Playout 'type'

	int bestScore;
	int numberOfPlayouts;
	const int ADAPTS_OF_BEST = 6;
	bool mutated;
private:
	float alpha;
};

#endif // NRPA_HPP
