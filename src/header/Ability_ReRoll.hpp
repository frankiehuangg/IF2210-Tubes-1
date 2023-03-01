#ifndef _ABILITY_REROLL_HPP_
#define _ABILITY_REROLL_HPP_

#include "AbilityCard.hpp"

class ReRoll : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus();
	virtual void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Buang 2 kartu milik player sekarang, ambil ulang kartu dari deck
	void useAbility(const Game&);
};

#endif
