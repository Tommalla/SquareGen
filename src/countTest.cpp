#include <cassert>

#include "func.hpp"

using namespace std;
using namespace func;

int main() {
 	assert(countSquares("1100") == 2);
	assert(countSquares("110101011") == 3);
	assert(countSquares("00000000000") == 5);
	assert(countSquares("1101001011") == 5);

	assert(deterministicCountSquares("1100") == 2);
	assert(deterministicCountSquares("110101011") == 3);
	assert(deterministicCountSquares("00000000000") == 5);
	assert(deterministicCountSquares("1101001011") == 5);
	puts("OK");
	return 0;
}