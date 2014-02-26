#include <algorithm>
#include <cassert>

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
	return NRPAnestedSearch(startingLevel, bestPolicy, numberOfPlayouts);
}

Beam BeamNRPA::nestedSearch(const int level, unordered_map< string, float > pol, const int numberOfPlayouts) {
	if (level == 0) {
		auto tmp = samplePlayout(pol);
		return {make_tuple(tmp.second, tmp.first, pol)};
	}

	assert(level == 1);

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

	if (rememberBest && get<0>(beam.front()) > bestScore) {
		bestScore = get<0>(beam.front());
		bestPolicy = get<2>(beam.front());
	}
	return beam;
}

Playout BeamNRPA::NRPAnestedSearch(const int level, unordered_map<string, float> pol, const int numberOfPlayouts) {
	if (level == 0)
		return samplePlayout(pol);
	else if (level == 1) {
		Beam res = nestedSearch(level, pol, numberOfPlayouts);
		return make_pair(get<1>(res.front()), get<0>(res.front()));
	}

	Playout res = getRoot();
	for (int p = 0; p < numberOfPlayouts; ++p) {
		Playout tmp = NRPAnestedSearch(level - 1, pol, numberOfPlayouts);
		if (tmp.second > res.second)
			res = tmp;
		adapt(res.first, pol);
	}

	if (res.second > bestScore) {
		bestScore = res.second;
		bestPolicy = pol;
	}

	return res;
}