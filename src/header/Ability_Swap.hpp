#ifndef _ABILITY_SWAP_HPP_
#define _ABILITY_SWAP_HPP_

#include "AbilityCard.hpp"

class Swap : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	virtual bool getStatus();
	virtual void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Swap 1 kartu pemain lain dengan 1 kartu pemain lain
	void useAbility(const Game&);
};

#endif
