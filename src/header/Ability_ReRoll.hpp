#ifndef _ABILITY_REROLL_HPP_
#define _ABILITY_REROLL_HPP_

#include "AbilityCard.hpp"

class ReRoll : public AbilityCard {
public:
	/***** Getter & Setter *****/
	// If used, then status is true, else status is false;
	bool getStatus();
	void setStatus(bool);

	/**** Use ability, different for each card *****/
	// Buang 2 kartu milik player sekarang, ambil ulang kartu dari deck
	// sementara belum bisa, tunggu yang operator + sama - selesai dulu
	void useAbility(const Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	void printCard();
};

#endif
