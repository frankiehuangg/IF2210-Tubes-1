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
	/* MainCard constructor
	 * @param int number	Card number (1...13)
	 * @param int Color		Card color  ENUM(RED, YELLOW, GREEN, BLUE) */
	MainCard(int, int);

	/***** Getter & Setter *****/
	/* Returns the card number */
	int getNumber() const;

	/* Set the current card value
	 * @param int number	New card number */
	void setNumber(int);

	/* Returns the card color */
	int getColor() const;

	/* Set the current card color
	 * @param int color		New card color */
	void setColor(int);

	/***** Print *****/
	/* Prints the card number and color */
	void printCard();

	/***** Comparison *****/
	/* Checks whether the current card value < the other card value
	 * @param const MainCard m1		The first card
	 * @param const MainCard m2		The second card */
	friend bool operator< (const MainCard, const MainCard);

	/* Checks whether the current card value > the other card value
	 * @param Comparable& other		The other card */
	bool operator< (Comparable&);

	/* Checks whether the current card value < the other card value
	 * @param Comparable& other		The other card */
	bool operator> (Comparable&);
	
	/* Checks whether the current card value == the other card value
	 * @param Comparable& other		The other card */
	bool operator== (Comparable&);

	/* Ostream operator used for cout
	 * @param ostream& os	ostream
	 * @param const vector<MainCard>& cards	container */
	friend ostream& operator<<(ostream&, const vector<MainCard>&);
};

#endif
