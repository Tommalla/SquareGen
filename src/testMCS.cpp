#include <cassert>
#include <string>
#include <memory>

#include "AbstractMCS.hpp"
#include "NMCS.hpp"
#include "NRPA.hpp"
#include "BeamNRPA.hpp"
#include "func.hpp"

using namespace func;
using namespace std;

Playout getTestResFor(const string& method, const int i) {
	shared_ptr<AbstractMCS> gen;

	if (method == "NMCS")
		gen = shared_ptr<AbstractMCS>{new NMCS{(size_t)i, (rand() % i) % 2 + 1}};
	else if (method == "NRPA")
		gen = shared_ptr<AbstractMCS>{new BeamNRPA{(size_t)i, (rand() % i) % 2 + 1, rand() % 50 + 1}};
	else
		gen = shared_ptr<AbstractMCS>{new NRPA{(size_t)i, (rand() % i) % 2 + 1, rand() % 50 + 1}};

	return (*gen)();
}

int main() {
	//NO srand on purpose
	vector<string> methods = {"NMCS", "NRPA", "BeamNRPA"};

	for (string m: methods) {
		printf("%s...", m.c_str());
		for (int i = 1; i < 50; ++i) {
			auto p = getTestResFor(m, i);
			assert(p.second == deterministicCountSquares(p.first));
			assert((int)p.first.length() == i);
		}
		puts("OK");
	}

	return 0;
}