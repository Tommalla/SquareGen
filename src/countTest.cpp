#include <cassert>

#include "func.hpp"

using namespace std;

int main() {
	int pref[30];
	assert(countSquares("1100", pref) == 2);
	assert(countSquares("110101011", pref) == 3);
	assert(countSquares("00000000000", pref) == 1);
	assert(countSquares("1101001011", pref) == 4);
	puts("OK");
	return 0;
}