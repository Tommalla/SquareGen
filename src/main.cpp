#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "NMCS.hpp"

using namespace NMCS;

int main(int argc, char** argv) {
	if (argc != 3) {
		puts("Wrong number of arguments!\nThe correct usage is SquareGen <word length> <level>");
		return 1;
	}

	const int n = atoi(argv[1]);
	const int level = atoi(argv[2]);
	unsigned int seed = time(NULL);
	srand(seed);
	printf("Starting string creation for n = %d, level = %d and seed = %u\n", n, level, seed);

	while(true) {
		Playout res = generate(n, level);
		printf("\nResult: %d\nString: %s\n", res.second, res.first.c_str());
	}
	return 0;
}
