#include <utility>

#include "AbstractMCS.hpp"
#include "func.hpp"

using std::make_pair;
using namespace func;

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
	int realCount = deterministicCountSquares(res.first);
	if (realCount != res.second) {
		puts("Error in countSquares!");
		res.second = realCount;
	}
	return res;
}

void AbstractMCS::setBestResult(const State& s) {
	Playout res = std::make_pair(s, deterministicCountSquares(s));
	setBest(std::move(res));
}


