#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include "Game.hpp"
#include "Player.hpp"

class AbilityCard {
protected:
	bool status;

public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	bool getStatus() const;
	void setStatus(bool);

	/**** Use ability, different for each card *****/
	virtual void useAbility(const Game&) = 0;

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	virtual void printCard() = 0;
};

#endif
