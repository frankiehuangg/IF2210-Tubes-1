#ifndef _CARD_HPP_
#define _CARD_HPP_

#include "Comparable.hpp"

class MainCard : public Comparable {
private:
	int number;
	int color;

public:
	/* Constructor & destructor */
	MainCard(int, int);

	/***** Getter & Setter *****/
	// Value
	float getValue();
	void setValue(float);

	// Number
	int getNumber();
	void setNumber(int);

	// Color
	int getColor();
	void setColor(int);

	/***** Comparison *****/
	// Cek apakah nilai kartu > kartu lain
	bool operator< (Comparable*);

	// Cek apakah nilai kartu < kartu lain
	bool operator> (Comparable*);
	
	// Cek apakah nilai kartu = kartu lain
	bool operator== (Comparable*);
};

#endif
