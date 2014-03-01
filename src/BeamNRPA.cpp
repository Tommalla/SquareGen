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

BeamNRPA::BeamNRPA(const size_t n, const int startingLevel, const int numberOfPlayouts,
		   const int beamSize, const float alpha, const bool rememberBest)
: NRPA{n, startingLevel, numberOfPlayouts, alpha, rememberBest}
, B{beamSize}
{}

Playout BeamNRPA::generate() {
	return nestedSearch(startingLevel, bestPolicy, numberOfPlayouts);
}

Playout BeamNRPA::nestedSearch(const int level, unordered_map< string, float > pol, const int numberOfPlayouts) {
	if (level > 1)
		return NRPA::nestedSearch(level, pol, numberOfPlayouts);

	BeamElem f = beamNestedSearch(level, pol, numberOfPlayouts).front();
	return make_pair(get<1>(f), get<0>(f));
}

Beam BeamNRPA::beamNestedSearch(const int level, unordered_map< string, float > pol, const int numberOfPlayouts) {
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
			Beam tmpBeam = beamNestedSearch(level - 1, get<2>(t), numberOfPlayouts);
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

	if (rememberBest && (mutated || get<0>(beam.front()) > bestScore)) {
		mutated = false;
		bestScore = get<0>(beam.front());
		bestPolicy = get<2>(beam.front());
	}
	return beam;
}