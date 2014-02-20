#include <cassert>

#include "NMCS.hpp"
#include "func.hpp"

using namespace NMCS;

int main() {
	//NO srand on purpose
	int buffer[100];

	for (int i = 1; i < 50; ++i) {
		Playout p = generate(i, (rand() % i) % 2 + 1, buffer);
		assert(p.second == countSquares(p.first, buffer));
	}

	puts("OK");
	return 0;
}