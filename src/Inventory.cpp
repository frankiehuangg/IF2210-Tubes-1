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

Inventory& Inventory::operator+(vector<MainCard> vector)
{
	this->cards = vector;
	this->amount += vector.size();
	return *this;
}

vector<MainCard> Inventory::operator-(int num)
{
	vector<MainCard> vec;
	vector<MainCard>::iterator it = this->cards.begin();
	vector<MainCard>::iterator it2 = this->cards.begin()+num;

	for (int i = 0; i < num; i++)
	{
		MainCard m = this->cards[i];
		vec.push_back(m);
	}
	this->cards.erase(it,it2);
	this->amount-=num;
	return vec;
}
