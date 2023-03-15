#ifndef _COMBO_HPP_
#define _COMBO_HPP_

#include <map>
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
	// Combo list:
	// 0 = no combo
	// 1 = pair
	// 2 = two pair
	// 3 = three of a kind dst.
	// static const map<int, float> combo_list;
	vector<MainCard> cards;

	string combotype;
	
	bool checkHighCard(vector<MainCard>& cardSublist);
	bool checkPair(vector<MainCard>& cardSublist);
	bool checkTwoPair(vector<MainCard>& cardSublist);
	bool checkThreeOfaKind(vector<MainCard>& cardSublist);
	bool checkStraight(vector<MainCard>& cardSublist); 
	bool checkFlush(vector<MainCard>& cardSublist);
	bool checkFullHouse(vector<MainCard>& cardSublist);
	bool checkFourOfaKind(vector<MainCard>& cardSublist);
	bool checkStraightFlush(vector<MainCard>& cardSublist);
};

#endif
