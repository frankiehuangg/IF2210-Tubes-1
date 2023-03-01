#ifndef _ABILITY_SWITCH_HPP_
#define _ABILITY_SWITCH_HPP_

#include "AbilityCard.hpp"

class Switch : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus();
	virtual void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Tukar 2 kartu milik sendiri dengan 2 kartu milik pemain lain 
	void useAbility(const Game&);};

#endif
