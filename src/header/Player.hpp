#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "Comparable.hpp"
#include "Inventory.hpp"
#include "Action.hpp"
#include "MainCard.hpp"

using namespace std;

// Forward declaration
class AbilityCard;

class Player : public Comparable, public Inventory {
private:
	string name;
	int point;

	AbilityCard* ability;
	Action playerAction;

public:
	/***** Constructor dan destructor *****/
	// Buat sebuah player dengan parameter name dan point awal 0. Lalu inisialisasikan cards dan ability
	Player(string);	

	// Destruct cards dan ability ke memori
	~Player();


	/***** Getter & Setter *****/
	// Kembalikan nilai kartu
	const pair<MainCard, MainCard> getCards();
	// Ubah nilai kartu
	void setCards(pair<MainCard, MainCard>);

	/**** Use ability, different for each card *****/
	void useAbility();

	/***** Print *****/
	// Cetak cards dan ability; cards dicetak dengan memanggil fungsi printCard dari kelas MainCard
	void printCards();

	// Cek apakah nilai kombo player > player lain
	bool operator< (Comparable& other);

	// Cek apakah nilai kombo player < player lain
	bool operator> (Comparable& other);

	// Cek apakah nilai kombo player = player lain
	bool operator== (Comparable& other);
};

#endif
