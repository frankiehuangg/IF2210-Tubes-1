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
