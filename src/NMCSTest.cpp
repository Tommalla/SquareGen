#include <cassert>

#include "NMCS.hpp"
#include "func.hpp"


int main() {
	//NO srand on purpose
	int buffer[100];

	for (int i = 1; i < 50; ++i) {
		NMCS gen(i);
		auto p = gen((rand() % i) % 2 + 1);
		assert(p.second == countSquares(p.first, buffer));
	}

	puts("OK");
	return 0;
}