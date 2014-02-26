#ifndef BEAM_NRPA_HPP
#define BEAM_NRPA_HPP
#include <tuple>

#include "NRPA.hpp"

typedef std::tuple<int, std::string, std::unordered_map<std::string, float>> BeamElem;
typedef std::vector<BeamElem> Beam;

class BeamNRPA: public NRPA {
public:
	BeamNRPA(const size_t n, const int startingLevel, const int numberOfPlayouts = 100,
		 const int beamSize = 4, const float alpha = 1.0f, const bool rememberBest = true);
	virtual Playout generate();
protected:
	const int B;	//Beam size

	virtual Playout nestedSearch(const int level, std::unordered_map< std::string, float > pol, const int numberOfPlayouts);
private:
	/**
	 * @brief Performs a Nested Rollout Policy Adaptation with parameter level;
	 */
	Beam beamNestedSearch(const int level, std::unordered_map<std::string, float> pol, const int numberOfPlayouts);
};

#endif // BEAM_NRPA_HPP