#include <iostream>
#include <string>

#include "func.hpp"

using namespace std;

int main() {
	string str;
	cin >> str;

	cout << func::deterministicCountSquares(str) << endl;
	return 0;
}