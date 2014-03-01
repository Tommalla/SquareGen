#include <cstdio>
#include <string>

#include "func.hpp"

using namespace std;

int main() {
	size_t n;
	string str;
	scanf("%lu", &n);

	int qty = 1;
	while (str.length() < n) {
		for (int i = 0; i < qty && str.length() < n; ++i)
			str.push_back('0');
		++qty;
		if (str.length() >= n)
			break;
		str.push_back('1');
	}


	while (str.back() == '0')
		str.pop_back();
	int len = n - str.length();
	for (int i = 0; i < len; ++i)
		str.push_back((i % 2) + '0');

	printf("Result %d\nString: %s\n", func::deterministicCountSquares(str), str.c_str());
	return 0;
}
