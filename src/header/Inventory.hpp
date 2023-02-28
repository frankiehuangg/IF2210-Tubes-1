#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include "MainCard.hpp"

class Inventory {
protected:
	int amount;

public:
	/***** Getter & Setter *****/
	virtual void printCards() = 0;

	/***** Operator overloading *****/
	virtual Inventory& operator+ (Inventory&) = 0;
	virtual Inventory& operator- (Inventory&) = 0;
};

#endif
