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

vector<MainCard> Inventory::getInventoryCards() const
{	
	return this->cards;
}

MainCard Inventory::getCard(int index) const
{
	return this->cards[index];
}

void Inventory::setCard(int index, MainCard card)
{
	this->cards[index] = card;
}

bool Inventory::isInventoryEmpty()
{
	if (this->cards.empty())
		return true;
	return false;
}

bool Inventory::isColorExists(int color)
{
	int size = this->cards.size();
	for(unsigned i=0; i<size; i++)
	{
		if(this->cards[i].getColor()==color)
			return true;
	}	
	return false;
}

void Inventory::returnCardToDeck(Inventory& deck)
{
	int size = this->cards.size();

	vector<MainCard> temp = *this - size;
	deck = deck + temp;
}

void Inventory::returnOneCardToDeck(Inventory& deck, int index)
{
	vector<MainCard> temp;
	temp.push_back((*this).cards[index]);
	vector<MainCard>::iterator it = this->cards.begin() + index;
	deck = deck + temp;
	this->cards.erase(it);
	this->amount-=1;
}

void Inventory::takeCardFromDeck(Inventory& deck, int amount)
{
	vector<MainCard> temp = deck - amount;
	*this = *this + temp;
}

Inventory& Inventory::operator+(vector<MainCard> vector)
{
	for (unsigned i = 0; i < vector.size(); i++)
		this->cards.push_back(vector[i]);
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
