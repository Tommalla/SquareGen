#include <cassert>

#include "func.hpp"

using namespace std;

int main() {
	assert(countSquares("1100") == 2);
	assert(countSquares("110101011") == 3);
	assert(countSquares("00000000000") == 1);
	assert(countSquares("1101001011") == 4);
	puts("OK");
	return 0;
}