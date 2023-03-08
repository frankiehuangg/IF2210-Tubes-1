#ifndef _TABLE_HPP_
#define _TABLE_HPP_

#include "Inventory.hpp"
#include "MainCard.hpp"

using namespace std;

class Table : public Inventory {
private:
	int opened;

public:

	/***** Constructor and destructor *****/
	// Construct sebuah table dengan amount = 5, opened = 0, serta inisialisasikan atribut cards dengan panjang amount 
	Table(Inventory&);

	// Tambahkan nilai opened dengan 1
	void openCard();

	// Print semua kartu yang terdapat pada table (yang sudah terbuka), panggil fungsi printCard dari kelas MainCard untuk masing-masing card.
	void printCards();

	/***** Operator overloading *****/
	// Menambahkan kartu yang ditarik dari Deck ke dalam Table. Asumsi semua kartu deck pasti berukuran 5.
	Inventory& operator+(Inventory&);
	Inventory operator-(int x);
};

#endif
