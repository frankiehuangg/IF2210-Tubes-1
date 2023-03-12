#ifndef _ABILITY_REVERSE_HPP_
#define _ABILITY_REVERSE_HPP_

#include "AbilityCard.hpp"

class Reverse : public AbilityCard {
public:
	/**** Use ability, different for each card *****/
	// Reverse player's turn RoundRobin (baca specc)
	void useAbility(Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	void printCard();
};

#endif
