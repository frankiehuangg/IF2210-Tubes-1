#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>
#include "Comparable.hpp"
#include "Inventory.hpp"
#include "MainCard.hpp"
#include "Table.hpp"
#include "AbilityCard.hpp"
#include "Action.hpp"
#include "Exception.hpp"

#define C00 "\x1B[0m"
#define C01 "\x1B[31m"
#define C02 "\033[0;33m"
#define C03 "\x1B[32m"
#define C04 "\x1B[34m"
#define C05 "\x1b[38;5;238m"

using namespace std;

// Forward declaration
class Game;

class Player : public Inventory, public Comparable {
private:
	string name;
	int number;
	long long point;

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

	void returnAbilityToDeck();

	void takeAbilityFromDeck(AbilityCard*);

	void doAction(Game&);

	/**** Use ability, different for each card *****/
	void useAbility(Game&);

	/***** Print *****/
	// Cetak cards dan ability; cards dicetak dengan memanggil fungsi printCard dari kelas MainCard
	void printCards();

	friend ostream& operator<<(ostream&, Player);

	// Cek apakah poin player > player lain
	bool operator< (Comparable&);

	// Cek apakah poin player < player lain
	bool operator> (Comparable&);

	// Cek apakah poin player = player lain
	bool operator== (Comparable&);
};

#endif
