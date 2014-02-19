#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv) {
	if (argc != 2) {
		puts("Wrong number of arguments!\nThe correct usage is SquareGen <word length>");
		return 1;
	}

	const int n = atoi(argv[1]);
	printf("Starting string creation for n = %d\n", n);

	while(true) {
		//TODO
		//use NMCS to create the best string,
		//return it and print it
	}
	return 0;
}
