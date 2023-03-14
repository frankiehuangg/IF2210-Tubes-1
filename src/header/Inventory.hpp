#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include <vector>
#include "MainCard.hpp"

class Inventory {
protected:
	int amount;
	vector<MainCard> cards;
	
public:
	/***** Constructor *****/
	/* Inventory constructor
	 * @param int amount	Amount of cards in the inventory */
	Inventory(int);

	/***** Getter & Setter *****/
	/* Returns the value of amount */
	int getAmount() const;

	/* Set the value of amount
	 * @param int value		New amount value */
	void setAmount(int);

	/* Returns the vector of cards */
	vector<MainCard> getInventoryCards() const;

	/* Returns a vard with the corresponding index
	 * @param int index		Card index */
	MainCard getCard(int) const;

	/* Set the value of cards at the corresponding index
	 * @param int index		Card index
	 * @param MainCard		New card value */
	void setCard(int, MainCard);

	/* Check whether the inventory is empty */
	bool isInventoryEmpty();

	/* Returns all cards to deck
	 * @param Inventory& deck	Deck */
	void returnCardToDeck(Inventory&);

	/* Returns one card to deck
	 * @param Inventory& deck	Deck 
	 * @param index				The index of card returned */
	
	void returnOneCardToDeck(Inventory&, int);

	/* Takes an amount of card from deck
	 * @param Inventory& deck	Deck
	 * @param int amount		The amount of cards taken */
	void takeCardFromDeck(Inventory&, int);

	/***** Print value *****/
	/* Prints the inventory */
	virtual void printCards() = 0;

	/***** Operator overloading *****/
	/* Adds the cards from the vector to the inventory
	 * @param vector<MainCard> vector	Vector of cards */
	Inventory& operator+(vector<MainCard>);

	/* Removes an amount of cards from inventory
	 * @param int num	The amount of cards taken */
	vector<MainCard> operator-(int);
};

#endif
