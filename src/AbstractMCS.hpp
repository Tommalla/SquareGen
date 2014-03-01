#ifndef ABSTRACT_MCS_HPP
#define ABSTRACT_MCS_HPP
#include <vector>

#include "types.hpp"

class AbstractMCS {
public:
	AbstractMCS(const size_t n, const int startingLevel, const bool rememberBest = true);
	virtual ~AbstractMCS();

	Playout operator()();
	virtual void resetMemory() = 0;

        /**
         * @brief This method randomly mutates the best solution stored.
         * It's purpose is to be used to escape local maxima.
         */
        /**
         * @brief Sets the best result to s.
         * It's designed to be used when we're starting the generation with a aim of improving an already existing solution.
         */
        virtual void mutateBestSolution() = 0;
	void setBestResult(const State& s);
protected:
	virtual Playout generate() = 0;
	virtual void setBest(Playout&& p) = 0;
	bool randomTest(const float prob) const;

	const float MUTATION_PROBABILITY = 0.2f;
	const std::vector<char> MOVES = {'0', '1'};
	const size_t n;
	int startingLevel;
	bool rememberBest;
	bool mutated;
	unsigned int* countBuffer;
};

#endif // ABSTRACT_MCS_HPP