#ifndef _ABILITY_QUARTER_HPP_
#define _ABILITY_QUARTER_HPP_

#include "AbilityCard.hpp"

class Quarter : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	bool getStatus();
	void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Ubah nilai point pada Game menjadi 1/4 nilai semula
	void useAbility(const Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	void printCard();
};

#endif
