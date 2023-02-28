#ifndef _ABILITY_QUADRUPLE_HPP_
#define _ABILITY_QUADRUPLE_HPP_

#include "AbilityCard.hpp"

class Quadruple : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus();
	virtual void setStatus(bool);

	/**** Use ability, different for each card *****/
	virtual void useAbility(const Game&);
};

#endif
