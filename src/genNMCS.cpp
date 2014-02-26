#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "NMCS.hpp"

using std::make_pair;

int main(int argc, char** argv) {
	if (argc != 2) {
		puts("Wrong number of arguments!\nThe correct usage is SquareGen <word length>");
		return 1;
	}

	const int n = atoi(argv[1]);
	unsigned int seed = time(NULL);
	srand(seed);
	printf("Starting string creation for n = %d and seed = %u\n", n, seed);
	Playout bestRes, res;
	res = bestRes = make_pair("", -1);
	NMCS gen(n, 2);

	do {
		res = gen();

		if (res.second > bestRes.second) {
			printf("\nNew best result: %d\nString: %s\n", res.second, res.first.c_str());
			bestRes = res;
		} else {
			printf(".");
			fflush(stdout);
		}
	} while (true);
	return 0;
}
