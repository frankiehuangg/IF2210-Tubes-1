#ifndef _ABILITY_HPP_
#define _ABILITY_HPP_

#include <string>

using std::string;

class Game;

class AbilityCard {
protected:
	bool status;
	bool isdisabled;
	string type;

public:
	AbilityCard();
	virtual ~AbilityCard();
	/***** Getter & Setter *****/
	// If available to use, then status is true, else status is false;
	bool getStatus() const;
	void setStatus(bool);

	// if card is disabled, return true
	bool disabled();
	// set isdisabled to true
	void disable();
	// set isdisabled to false
	void enable();

	// return card type
	string getType() const;

	/**** Use ability, different for each card *****/
	virtual void useAbility(Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	virtual void printCard();

	// dia aku ubah non pure virtual karena kita ada make stl (deque) dengan class AbilityCard
	// antara ini gajadi virtual ATO make stlnya sama reference/pointer

};

#endif
