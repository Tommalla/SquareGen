#include <cassert>

#include "NRPA.hpp"
#include "func.hpp"

using namespace func;

int main() {
	//NO srand on purpose

	for (int i = 1; i < 50; ++i) {
		NRPA gen(i);
		auto p = gen((rand() % i) % 2 + 1, rand() % 50 + 1);
		assert(p.second == deterministicCountSquares(p.first));
		assert((int)p.first.length() == i);
	}

	puts("OK");
	return 0;
}
