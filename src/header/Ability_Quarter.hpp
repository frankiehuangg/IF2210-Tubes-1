#ifndef _ABILITY_QUARTER_HPP_
#define _ABILITY_QUARTER_HPP_

#include "AbilityCard.hpp"

class Quarter : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus();
	virtual void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Ubah nilai point pada Game menjadi 1/4 nilai semula
	virtual void useAbility(const Game&);
};

#endif
