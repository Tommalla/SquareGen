#include "AbstractMCS.hpp"

AbstractMCS::AbstractMCS(const size_t n, const bool rememberBest)
: n{n}
, countBuffer{new unsigned int[n]}
, rememberBest{rememberBest}
, bestPlayout{"", -1} {}


AbstractMCS::~AbstractMCS() {
	delete[] countBuffer;
}

Playout AbstractMCS::operator()() {
	return generate();
}

