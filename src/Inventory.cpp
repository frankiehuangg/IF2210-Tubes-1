#include "header/Inventory.hpp"

Inventory::Inventory(int amount)
{
	this->amount = amount;
}

int Inventory::getAmount() const
{
	return this->amount;
}

void Inventory::setAmount(int amount)
{
	this->amount = amount;
}

MainCard Inventory::getCard(int index) const
{
	return this->cards[index];
}

void Inventory::setCard(int index, MainCard card)
{
	this->cards[index] = card;
}

Inventory& Inventory::operator+(Inventory& other)
{
	this->amount = other.amount;
	this->cards = other.cards;

	return *this;
}

Inventory Inventory::operator-(int num)
{
	Inventory inventory(num);
	
	vector<MainCard>::iterator it = this->cards.begin();
	for (int i = 0; i < num; i++)
	{
		inventory.cards[i] = this->cards[i];
		this->cards.erase(it);
		it++;
	}

	return inventory;
}
