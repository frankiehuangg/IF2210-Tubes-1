#ifndef _ABILITY_ABILITYLESS_HPP_
#define _ABILITY_ABILITYLESS_HPP_

#include "AbilityCard.hpp"

class Abilityless : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus();
	virtual void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Ubah status abilityCard pemain lain menjadi false 
	virtual void useAbility(const Player&);
};

#endif
