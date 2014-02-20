#include <cassert>

#include "NMCS.hpp"
#include "func.hpp"

using namespace NMCS;

int main() {
	//NO srand on purpose
	for (int i = 1; i < 50; ++i) {
		Playout p = generate(i, (rand() % i) % 2 + 1);
		assert(p.second == countSquares(p.first));
	}

	puts("OK");
	return 0;
}