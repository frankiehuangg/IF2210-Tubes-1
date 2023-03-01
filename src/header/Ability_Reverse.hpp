#ifndef _ABILITY_REVERSE_HPP_
#define _ABILITY_REVERSE_HPP_

#include "AbilityCard.hpp"

class Reverse : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus();
	virtual void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Reverse player's turn RoundRobin (baca specc)
	void useAbility(const Game&);
};

#define
