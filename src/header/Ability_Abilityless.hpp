#ifndef _ABILITY_ABILITYLESS_HPP_
#define _ABILITY_ABILITYLESS_HPP_

#include "AbilityCard.hpp"

class Abilityless : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	bool getStatus();
	void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Ubah status abilityCard pemain lain menjadi false 
	void useAbility(const Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	void printCard();
};

#endif
