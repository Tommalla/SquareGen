#include "NMCS.hpp"
#include "func.hpp"

using namespace NMCS;
using std::make_pair;

Playout NMCS::generate(const int n, const int level) {
	return nestedSearch("", n, level);
}

Playout NMCS::nestedSearch(const State& s, const int n, int level) {
	Playout res = make_pair(s, -1);
	//TODO

	return res;
}

State NMCS::play(const State& s, const Move move) {
	State res = s;

	//TODO

	return res;
}


