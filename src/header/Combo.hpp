#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include <algorithm>	// sort
#include <string>
#include "Comparable.hpp"
#include "MainCard.hpp"
#include "Player.hpp"
#include "Table.hpp"

class Combo : public Comparable {
public:
	/***** Constructor *****/
	Combo();
	// Inisialisasi map berisi combo-combo yang ada
	Combo(const Player&, const Table&);

	/****** Getter & Setter *****/
	float getValue() const;
	void setValue(float);

	/***** Comparison *****/
	// Implementasi combo pakai map
	// Cek apakah nilai kombo > kombo lain
	bool operator> (Comparable&);

	// Cek apakah nilai kombo < kombo lain
	bool operator< (Comparable&);

	// Cek apakah nilai kombo == kombo lain
	bool operator== (Comparable&);

	// Return tipe combo yang dihasilkan
	string what();
	
	/* Ostream operator used for cout
	 * @param ostream& os	ostream
	 * @param const Combo& combo	combo */
	friend ostream& operator<<(ostream&, const Combo&);

private:
	vector<MainCard> cards;
	string combotype;
	
	/* Utility methods for checking combination types
	 * @param vector<MainCard>& cardSublist	subset dari kartu pemain dan kartu table */
	
	// High card: Nilai kartu tertinggi yang dimiliki player jika tidak ada kombinasi lain.
	bool checkHighCard(vector<MainCard>& cardSublist);

	// Pair: Jika terdapat dua kartu yang memiliki angka yang sama.
	bool checkPair(vector<MainCard>& cardSublist);

	// Two pair: Jika terdapat dua pair
	bool checkTwoPair(vector<MainCard>& cardSublist);

	// Three of a kind: Jika terdapat tiga kartu yang memiliki angka yang sama.
	bool checkThreeOfaKind(vector<MainCard>& cardSublist);

	// Straight: Jika terdapat lima kartu yang berurutan. Misalnya 3 4 5 6 7
	bool checkStraight(vector<MainCard>& cardSublist); 
	
	// Flush: Jika terdapat lima kartu dengan warna yang sama. 
	bool checkFlush(vector<MainCard>& cardSublist);

	// Full house: Jika terdapat tiga kartu dengan warna yang sama dan dua kartu lainnya dengan warna yang sama
	bool checkFullHouse(vector<MainCard>& cardSublist);

	// Four of a kind: Jika terdapat empat kartu yang memiliki angka yang sama
	bool checkFourOfaKind(vector<MainCard>& cardSublist);

	// Straight flush: Jika terdapat lima kartu berurutan dengan warna yang sama
	bool checkStraightFlush(vector<MainCard>& cardSublist);
};

#endif
