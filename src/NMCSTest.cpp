#include <cassert>

#include "NMCS.hpp"
#include "func.hpp"

using namespace func;

int main() {
	//NO srand on purpose
	for (int i = 1; i < 50; ++i) {
        NMCS gen(i, (rand() % i) % 2 + 1);
		auto p = gen();
		assert(p.second == deterministicCountSquares(p.first));
		assert((int)p.first.length() == i);
	}

	puts("OK");
	return 0;
}