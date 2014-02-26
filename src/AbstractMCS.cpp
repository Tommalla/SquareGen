#include "AbstractMCS.hpp"
#include "func.hpp"

AbstractMCS::AbstractMCS(const size_t n, const bool rememberBest)
: n{n}
, countBuffer{new unsigned int[n]}
, rememberBest{rememberBest}
, bestPlayout{"", -1} {}


AbstractMCS::~AbstractMCS() {
	delete[] countBuffer;
}

Playout AbstractMCS::operator()() {
	Playout res = generate();
	int realCount = func::deterministicCountSquares(res.first);
	if (realCount != res.second)
		puts("Error in countSquares!");
	return res;
}

