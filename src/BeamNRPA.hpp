#ifndef BEAM_NRPA_HPP
#define BEAM_NRPA_HPP
#include <tuple>

#include "NRPA.hpp"

typedef std::tuple<int, std::string, std::unordered_map<std::string, float>> BeamElem;
typedef std::vector<BeamElem> Beam;

class BeamNRPA: public NRPA {
public:
	BeamNRPA(const int n);
	virtual Playout generate(const int level, const int numberOfPlayouts);
protected:
	const int B = 2;	//Beam size

	Beam nestedSearch(const int level, std::unordered_map< std::string, float > pol, const int numberOfPlayouts);
private:
	/**
	 * @brief Performs a Nested Rollout Policy Adaptation with parameter level;
	 */
	Playout NRPAnestedSearch(const int level, std::unordered_map<std::string, float> pol, const int numberOfPlayouts);
};

#endif // BEAM_NRPA_HPP