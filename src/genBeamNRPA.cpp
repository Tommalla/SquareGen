#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "BeamNRPA.hpp"

using std::make_pair;

int main(int argc, char** argv) {
	if (argc != 3) {
		puts("Wrong number of arguments!\nThe correct usage is genBeamNRPA <word length> <numberOfPlayouts>");
		return 1;
	}

	const int n = atoi(argv[1]);
	const int no = atoi(argv[2]);
	unsigned int seed = time(NULL);
	srand(seed);
	BeamNRPA gen(n, 2, no, 8);
	printf("Starting string creation with BeamNRPA for n = %d, ALPHA = %.3f and seed = %u\n", n, gen.getAlpha(), seed);
	Playout bestRes, res;
	res = bestRes = make_pair("", -1);

	do {
		res = gen();
		if (res.second > bestRes.second) {
			printf("\nNew best result: %d\nString: %s\n", res.second, res.first.c_str());
			bestRes = res;
		} else {
			printf("score: %d\n", res.second);
			fflush(stdout);
		}

	} while (true);
	return 0;
}
