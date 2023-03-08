#ifndef _DECK_HPP_
#define _DECK_HPP_

#include <vector>
#include "Inventory.hpp"
#include "MainCard.hpp"

using namespace std;

class Deck : public Inventory {
public:
	
	/***** Constructor and destructor *****/
	// Construct sebuah deck dengan nilai amount = 52 serta inisialisasikan attribute cards dengan panjang 52 dan abilities dengan panjang 7
	Deck();

	// Acak MainCard dan AbilityCard
	void shuffleDeck();

	// Baca urutan deck dari file
	void getDeckFromInput();

	void printCards();
};

#endif
