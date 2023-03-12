#ifndef _ABILITY_SWITCH_HPP_
#define _ABILITY_SWITCH_HPP_

#include "AbilityCard.hpp"

class Switch : public AbilityCard {
public:
	/**** Use ability, different for each card *****/
	// Tukar 2 kartu milik sendiri dengan 2 kartu milik pemain lain 
	// Minta input nama pemain yang ingin ditukarkan kartunya, lalu tukar
	void useAbility(Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	void printCard();
};

#endif
