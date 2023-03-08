#ifndef _CARD_HPP_
#define _CARD_HPP_

#include <iostream>
#include "Comparable.hpp"

using namespace std;

class MainCard : public Comparable {
private:
	pair<int, int> card;

public:
	/* Constructor & destructor */
	MainCard(int, int);

	/***** Getter & Setter *****/
	// Value
	float getValue() const;
	void setValue(float);

	// Number
	int getNumber() const;
	void setNumber(int);

	// Color
	int getColor() const;
	void setColor(int);

	/***** Print *****/
	// Print card number and color, ends with endl
	void printCard();

	/***** Comparison *****/
	// Cek apakah nilai kartu > kartu lain
	bool operator< (Comparable&);

	// Cek apakah nilai kartu < kartu lain
	bool operator> (Comparable&);
	
	// Cek apakah nilai kartu = kartu lain
	bool operator== (Comparable&);
};

#endif
