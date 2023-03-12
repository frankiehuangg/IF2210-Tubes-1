#ifndef _ABILITY_SWAP_HPP_
#define _ABILITY_SWAP_HPP_

#include "AbilityCard.hpp"

class Swap : public AbilityCard {
public:
	/**** Use ability, different for each card *****/
	// Swap 1 kartu pemain lain dengan 1 kartu pemain lain
	// Minta input nama pemain yang ingin ditukar, lalu tanya kartu yang mana (1 atau 2)
	void useAbility(Game&);

	/***** Print card *****/
	// Print card info and status, if round = 1 print "NOT AVAILABLE or sum other shit idk"
	void printCard();
};

#endif
