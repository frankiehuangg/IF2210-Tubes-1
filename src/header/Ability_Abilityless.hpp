#ifndef _ABILITY_ABILITYLESS_HPP_
#define _ABILITY_ABILITYLESS_HPP_

#include "AbilityCard.hpp"

class Abilityless : public AbilityCard {
public:
	/**** Use ability, different for each card *****/
	// Ubah status abilityCard pemain lain menjadi false 
	void useAbility(const Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	void printCard();
};

#endif
