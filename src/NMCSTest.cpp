#include <cassert>

#include "NMCS.hpp"
#include "func.hpp"


int main() {
	//NO srand on purpose
	int buffer[100];

	for (int i = 1; i < 50; ++i) {
		NMCS gen(i, (rand() % i) % 2 + 1);
		auto p = gen.generate();
		assert(p.second == countSquares(p.first, buffer));
	}

	puts("OK");
	return 0;
}