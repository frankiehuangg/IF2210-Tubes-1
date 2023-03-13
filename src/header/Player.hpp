#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "Comparable.hpp"
#include "Inventory.hpp"
#include "MainCard.hpp"
#include "AbilityCard.hpp"
#include "Action.hpp"
#include "Exception.hpp"

using namespace std;

// Forward declaration
class Game;

class Player : public Inventory, public Comparable {
private:
	string name;
	int number;
	int point;

	AbilityCard* ability;
	Action playerAction;

public:
	/***** Constructor dan destructor *****/
	// Buat sebuah player dengan parameter name dan point awal 0. Lalu inisialisasikan cards dan ability
	Player(string, int);	

	// Destruct cards dan ability ke memori
	~Player();

	// Kembalikan nilai number pemain
	int getPlayerNumber() const;
	// Kembalikan nama player
	string getPlayerName() const;

	float getValue() const;
	void setValue(float);
	
	// Kembalikan nilai point pemain
	int getPlayerPoint() const;
	// tambah point pemain
	void addPlayerPoint(int);

	bool doesAbilityCardExist() const;

	bool getAbilityCardStatus() const;

	void setAbilityCardStatus(bool);

	void returnAbilityToDeck(Inventory&);

	void takeAbilityFromDeck(Inventory&);

	void doAction(Game&);

	/**** Use ability, different for each card *****/
	void useAbility(Game&);

	/***** Print *****/
	// Cetak cards dan ability; cards dicetak dengan memanggil fungsi printCard dari kelas MainCard
	void printCards();

	friend ostream& operator<<(ostream&, Player&);

	// Cek apakah nilai kombo player > player lain
	bool operator< (Comparable&);

	// Cek apakah nilai kombo player < player lain
	bool operator> (Comparable&);

	// Cek apakah nilai kombo player = player lain
	bool operator== (Comparable&);
};

#endif
