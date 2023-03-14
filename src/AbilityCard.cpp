#include "header/AbilityCard.hpp"

AbilityCard::~AbilityCard()
{

}

bool AbilityCard::getStatus() const
{
	return this->status;
}

void AbilityCard::setStatus(bool status)
{
	this->status = status;
}

string AbilityCard::getType() const
{
	return this->type;
}

void AbilityCard::useAbility(Game&){}

void AbilityCard::printCard(){}
