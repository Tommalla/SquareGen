#ifndef ABSTRACT_MCS_HPP
#define ABSTRACT_MCS_HPP
#include <vector>

#include "types.hpp"

class AbstractMCS {
public:
	AbstractMCS(const size_t n, const bool rememberBest = true);
	virtual ~AbstractMCS();

	Playout operator()();
protected:
	virtual Playout generate() = 0;

	const std::vector<char> MOVES = {'0', '1'};
	const size_t n;
	unsigned int* countBuffer;
	bool rememberBest;
	Playout bestPlayout;
};

#endif // ABSTRACT_MCS_HPP