#include <cstdio>
#include <string>

#include "func.hpp"

using namespace std;

int main() {
	size_t n;
	string str = "11";
	scanf("%lu", &n);

	int qty = 2;
	while (str.length() < n) {
		for (int i = 0; i < qty && str.length() < n; ++i)
			str.push_back('0');
		++qty;
		if (str.length() >= n)
			break;
		str.push_back('1');
	}

	printf("Result %d\nString: %s\n", func::deterministicCountSquares(str), str.c_str());
	return 0;
}
