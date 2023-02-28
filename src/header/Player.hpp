#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <iostream>

#include "Comparable.hpp"
#include "Inventory.hpp"
#include "Action.hpp"
#include "MainCard.hpp"
#include "AbilityCard.hpp"

using namespace std;

class Player : public Comparable, public Inventory, public Action {
private:
	string name;
	int point;

	MainCard* cards;
	AbilityCard* ability;

public:
	/***** Constructor dan destructor *****/
	// Buat sebuah player dengan parameter name dan point awal 0. Lalu inisialisasikan cards dan ability
	Player(string);	

	// Destruct cards dan ability ke memori
	~Player();


	/***** Player actions *****/
	// Giliran player selesai, tidak ada implementasi
	void actionDoNext();

	// Ubah nilai point pada game menjadi 2x lipat
	void actionDoDouble(const Game&);

	// Ubah nilai point pada game menjadi 1/2 nya
	void actionDoHalf(const Game&);

	// Gunakan ability dari abilitycard, lakukan pengecekan apakah card sudah bisa digunakan.

	/**** Use ability, different for each card *****/
	void useAbility();

	/***** Print *****/
	// Cetak cards dan ability
	void printCards();

	/***** Operator overloading *****/
	// Ambil n-buah kartu dari deck, player lain, atau table
	Inventory& operator+ (Inventory&);

	// Tarik n-buah kartu dari player
	Inventory& operator- (Inventory&);

	// Cek apakah nilai kombo player > player lain
	bool operator< (Comparable* other);

	// Cek apakah nilai kombo player < player lain
	bool operator> (Comparable* other);

	// Cek apakah nilai kombo player = player lain
	bool operator== (Comparable* other);
};

#endif
