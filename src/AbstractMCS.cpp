#include "AbstractMCS.hpp"
#include "func.hpp"

AbstractMCS::AbstractMCS(const size_t n, const int startingLevel, const bool rememberBest)
: n{n}
, startingLevel{startingLevel}
, rememberBest{rememberBest}
, countBuffer{new unsigned int[n]} {}


AbstractMCS::~AbstractMCS() {
	delete[] countBuffer;
}

Playout AbstractMCS::operator()() {
	Playout res = generate();
	int realCount = func::deterministicCountSquares(res.first);
	if (realCount != res.second) {
		puts("Error in countSquares!");
		res.second = realCount;
	}
	return res;
}

