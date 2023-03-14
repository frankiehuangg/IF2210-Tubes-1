#ifndef _DECK_HPP_
#define _DECK_HPP_

#include <iostream>
#include <fstream>	// file processing
#include <cstdlib>	// random shuffle
#include <time.h>	// random initial seed
#include <vector>
#include <map>		// ensure card table
#include <deque>	// deck shuffle
#include "Inventory.hpp"
#include "MainCard.hpp"
#include "Exception.hpp"

// include cards for initialization in deck
#include "AbilityCard.hpp"
#include "Ability_Abilityless.hpp"
#include "Ability_Quadruple.hpp"
#include "Ability_Quarter.hpp"
#include "Ability_ReRoll.hpp"
#include "Ability_Reverse.hpp"
#include "Ability_Swap.hpp"
#include "Ability_Switch.hpp"

using namespace std;

class AbilityCard;

class Deck : public Inventory {
public:
	
	/***** Constructor and destructor *****/
	// Construct sebuah deck dengan nilai amount = 52 serta inisialisasikan attribute cards dengan panjang 52 dan abilities dengan panjang 7
	Deck();

	// Acak MainCard
	void shuffleMainCards();

	// Baca urutan deck dari file
	void getDeckFromInput();

	// Acak AbilityCard
	void shuffleAbilityCards();

	// Cetak kartu
	void printCards();

	// Ambil kartu ability dari atas tumpukan kartu ability
	AbilityCard* takeAbilityFromDeck();

private:
	vector<AbilityCard> abilities;
	int abilityCardTop;	// indeks top dari tumpukan ability card
};

#endif
