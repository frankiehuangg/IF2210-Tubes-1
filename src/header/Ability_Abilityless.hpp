#ifndef _ABILITY_ABILITYLESS_HPP_
#define _ABILITY_ABILITYLESS_HPP_

#include "AbilityCard.hpp"

class Abilityless : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus();
	virtual void setStatus(bool);

	// Set other player ability card status = false
	virtual void useAbility(const Player&);
};

#endif
