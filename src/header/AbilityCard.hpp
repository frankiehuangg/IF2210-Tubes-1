#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include "Game.hpp"

class Game;
#include "Player.hpp" //idk kalo w make ini erornya ilang

class AbilityCard {
protected:
	bool status;

public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	bool getStatus() const;
	void setStatus(bool);

	/**** Use ability, different for each card *****/
	virtual void useAbility(Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	virtual void printCard();

	// dia aku ubah virtual karena kita ada make stl (deque) dengan class AbilityCard
	// antara ini gajadi virtual ATO make stlnya sama reference/pointer
};

#endif
