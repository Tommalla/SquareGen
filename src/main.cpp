#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "NMCS.hpp"

using namespace NMCS;
using std::make_pair;

int buffer[1000];

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
	Playout bestRes = make_pair("", -1);

	while(true) {
		Playout res = generate(n, level, buffer);
		if (res.second > bestRes.second) {
			printf("\nNew best result: %d\nString: %s\n", res.second, res.first.c_str());
			bestRes = res;
		}
	}
	return 0;
}
