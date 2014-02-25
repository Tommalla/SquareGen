#ifndef ABSTRACT_MCS_HPP
#define ABSTRACT_MCS_HPP
#include "types.hpp"

class AbstractMCS {
public:
	AbstractMCS(const size_t n, const bool rememberBest = true);
	virtual ~AbstractMCS();

	Playout operator()();
	virtual Playout generate() = 0;
protected:
	const size_t n;
	unsigned int* countBuffer;
	bool rememberBest;
	Playout bestPlayout;
};

#endif // ABSTRACT_MCS_HPP