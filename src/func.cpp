#include <algorithm>
#include <unordered_set>

#include "func.hpp"

using std::string;
using std::fill;
using std::unordered_set;

int countSquares(const string& str) {
	int* pref = new int[str.length()];
	int res = 0;
	int length = str.length();
	unordered_set<string> s;
	string tmp;

	fill(pref, pref + length, 0);

	for (int i = 0; i < length; ++i) {
		tmp.clear();
		for (int j = i + 1, t = i - 1; j < length; j += 2) {

			//update preftab
			for (int k = j - 1; k <= j; ++k) {
				while (t >= i && str[t] != str[k])
					t = (t == i) ? i - 1 : pref[t - 1];
				pref[k] = ++t - i;
			}

			int half = (j - i + 1) / 2;
			tmp.push_back(str[j - half]);
			//check if half of our string forms a square
			if (pref[j] == half && s.count(tmp) == 0) {
				s.insert(tmp);
				res++;
			}
		}
	}

	delete[] pref;
	return res;
}
