#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <sstream>

#include "func.hpp"
#include "types.hpp"
#include "NMCS.hpp"
#include "NRPA.hpp"
#include "BeamNRPA.hpp"

using std::string;
using std::shared_ptr;
using std::stringstream;
using std::cout;

const int MAX_SAME = 5;
const string use = string{"Wrong usage!\nThe correct usage is: ./squareGen <method> <n> <level> <options>\nPossible <method> "} +
		string{"can be NMCS, NRPA or BeamNRPA\n<options> are:\n\t-for NMCS: none\n\t-for NRPA: <number_of_playouts>\n\t"} +
		string{"-for BeamNRPA: <number_of_playouts> <size_of_beam>\n"};


int main(int argc, char** argv) {
	if (argc < 4) {
		cout << use;
		return 1;
	}

	size_t n = atoi(argv[2]);
	int level = atoi(argv[3]);
	string method = argv[1];

	unsigned int seed = time(NULL);
	srand(seed);

	shared_ptr<AbstractMCS> gen;

	stringstream ss;
	ss << "Starting squareGen with seed = " << seed << ", method: " << method << ", n = " << n << ", level = " << level;

	if (method == "NMCS") {
		gen = shared_ptr<AbstractMCS>{new NMCS{n, level}};
	} else {
		if (argc < 5) {
			cout << use;
			return 1;
		}

		int no = atoi(argv[4]);
		ss << ", number_of_playouts = " << no;

		if (method == "BeamNRPA") {
			if (argc < 6) {
				cout << use;
				return 1;
			}

			int beam = atoi(argv[5]);
			ss << ", beam_size = " << beam;

			gen = shared_ptr<AbstractMCS>{new BeamNRPA{n, level, no, beam}};
		} else
			gen = shared_ptr<AbstractMCS>{new NRPA{n, level, no}};
	}

	ss << "\n";
	cout << ss.str();

	Playout best = {"", -1};
	int sameCount = 0;

	while (true) {
		Playout tmp = (*gen)();
		if (tmp.second > best.second) {
			best = tmp;
			cout << "\nNew best Result: " << best.second << "\nString: " << best.first << "\n";
		} else if (tmp.second == best.second) {
			if (tmp.first != best.first) {
				cout << "Same as max, different string!\nString: " << tmp.first << "\n";
				best = tmp;
			} else {
				cout << "Same as max.\n";
				if (++sameCount >= MAX_SAME) {
					sameCount = 0;
					gen->resetMemory();
				}
			}
		} else
			cout << "Score: " << tmp.second << "\n";
	}
	return 0;
}