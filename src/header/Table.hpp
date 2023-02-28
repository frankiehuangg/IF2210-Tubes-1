#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include "Inventory.hpp"
#include "MainCard.hpp"

class Table : public Inventory {
private:
	int opened;
	MainCard *cards;

public:

	/***** Constructor and destructor *****/
	// Construct sebuah table dengan amount = 5, opened = 0, serta inisialisasikan atribut cards dengan panjang amount 
	Table(int);

	// Destruct cards dari memori
	~Table();

	// Tambahkan nilai opened dengan 1, kemudian panggil fungsi operator +
	void openCard();

	// Print semua kartu yang terdapat pada table (yang sudah terbuka)
	void printCards();

	// Ambil n-buah kartu dari deck dari index teratas (amount -1)
	Inventory& operator+ (Inventory&);
};

#endif
