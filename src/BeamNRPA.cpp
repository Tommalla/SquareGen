#include <algorithm>

#include "BeamNRPA.hpp"

using std::vector;
using std::tuple;
using std::string;
using std::unordered_map;
using std::make_tuple;
using std::make_pair;
using std::get;
using std::sort;

BeamNRPA::BeamNRPA(const int n)
: NRPA(n) {}


Playout BeamNRPA::generate(const int level, const int numberOfPlayouts) {
	unordered_map<string, float> startingPolicy;
	startingPolicy = bestPolicy;

	Beam res = nestedSearch(level, startingPolicy, numberOfPlayouts);
	return make_pair(get<1>(res.front()), get<0>(res.front()));
}


Beam BeamNRPA::nestedSearch(const int level, unordered_map< string, float > pol, const int numberOfPlayouts) {
	if (level == 0) {
		auto tmp = samplePlayout(pol);
		return {make_tuple(tmp.second, tmp.first, pol)};
	}

	Beam beam, newBeam;
	beam.push_back(make_tuple(-1, "", pol));

	for (int k = 0; k < numberOfPlayouts; ++k) {
		newBeam.clear();
		for (const auto& t: beam) {
			newBeam.push_back(t);
			Beam tmpBeam = nestedSearch(level - 1, get<2>(t), numberOfPlayouts);
			for (auto& b: tmpBeam) {
				get<2>(b) = pol;
				adapt(get<1>(b), get<2>(b));
				newBeam.push_back(b);
			}
		}

		sort(begin(newBeam), end(newBeam), [](const BeamElem& a, const BeamElem& b) {
			if (get<0>(a) != get<0>(b))
				return get<0>(a) > get<0>(b);
			return get<1>(a) < get<1>(b);
		});

		beam.clear();
		for (int i = 0; i < (int)newBeam.size() && i < B; ++i)
			beam.push_back(newBeam[i]);
	}

	if (get<0>(beam.front()) > bestScore) {
		bestScore = get<0>(beam.front());
		bestPolicy = get<2>(beam.front());
	}
	return beam;
}
