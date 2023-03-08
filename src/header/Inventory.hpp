#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include <vector>
#include "MainCard.hpp"

class Inventory {
protected:
	int amount;
	vector<MainCard> cards;
	
public:
	Inventory(int);

	/***** Getter & Setter *****/
	int getAmount() const;
	void setAmount(int);

	MainCard getCard(int) const;
	void setCard(int, MainCard);

	/***** Print value *****/
	virtual void printCards();

	/***** Operator overloading *****/
	virtual Inventory& operator+(Inventory&);
	virtual Inventory operator-(int);
};

#endif
