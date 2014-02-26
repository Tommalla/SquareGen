#include <algorithm>
#include <unordered_set>

#include "func.hpp"

using std::string;
using std::fill;
using std::unordered_set;

int func::countSquares(const string& str, unsigned int* hashTab) {
	int res = 0;
	int length = str.length();
	unordered_set<unsigned int> s;
	bool toDelete = false;

	if (hashTab == nullptr) {
		hashTab = new unsigned int[length];
		toDelete = true;
	}


	for (int i = 0; i < length; ++i) {
		for (int j = i + 1; j < length; j += 2) {
			for (int k = j - 1; k <= j; ++k)
				hashTab[k] = ((k > i) ? hashTab[k - 1] : 0) * X + str[k] - '0' + 1;

			int half = (j - i) / 2 + i;
			unsigned int h = hashTab[j] - hashTab[half] * powX(half - i + 1);

			if (h == hashTab[half] && s.count(h) == 0) {
				++res;
				s.insert(h);
			}
		}
	}

	if (toDelete)
		delete[] hashTab;
	return res;
}

int func::deterministicCountSquares(const string& str) {
	unordered_set<string> s;
	string tmp;
	int length = str.length();
	int res = 0;

	for (int i = 0; i < length; ++i) {
		tmp.clear();
		for (int j = i + 1; j < length; j += 2) {
			int half = (j - i) / 2 + i;
			tmp.push_back(str[half]);

			if (isEqual(tmp, str, half + 1, j) && s.count(tmp) == 0) {
				s.insert(tmp);
				++res;
			}
		}
	}

	return res;
}


unsigned int func::powX(const int n) {
	static unsigned int powers[1000];
	static int id = -1;

	if (id == -1)
		powers[++id] = 1;

	while (id < n) {
		++id;
		powers[id] = powers[id - 1] * X;
	}

	return powers[n];
}

bool func::isEqual(const string& a, const string& bWhole, const int& begin, const int& end) {
	for (int i = begin; i <= end; ++i)
		if (a[i - begin] != bWhole[i])
			return false;
	return true;
}


State func::play(const State& s, const Move move) {
	State res = s;
	res.push_back(move);
	return res;
}

void func::makeMove(State& s, const Move move) {
    s.push_back(move);
}

