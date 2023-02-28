#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include "Game.hpp"

class AbilityCard {
protected:
	bool status;

public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus() = 0;
	virtual void setStatus(bool) = 0;
};

#endif
