#ifndef _DECK_HPP_
#define _DECK_HPP_

#include "Inventory.hpp"
#include "MainCard.hpp"
#include "AbilityCard.hpp"

class Deck : public Inventory {
private:
	MainCard* cards;
	AbilityCard* abilities;

public:
	
	/***** Constructor and destructor *****/
	// Construct sebuah deck dengan nilai amount = 52 serta inisialisasikan attribute cards dengan panjang 52 dan abilities dengan panjang 7
	Deck(int);

	// Destruct cards dan abilities dari memori
	~Deck();

	// Acak MainCard dan AbilityCard
	void shuffleDeck();

	// Baca urutan deck dari file
	void getDeckFromInput();

	// Tarik n-buah kartu dari deck dimulai dari index teratas (amount-1)
	Inventory& operator- (Inventory&);
};

#endif
