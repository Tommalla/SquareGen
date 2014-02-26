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
protected:
	virtual Playout generate() = 0;

	const std::vector<char> MOVES = {'0', '1'};
	const size_t n;
	int startingLevel;
	bool rememberBest;
	unsigned int* countBuffer;
};

#endif // ABSTRACT_MCS_HPP