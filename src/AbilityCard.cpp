#include "header/AbilityCard.hpp"

AbilityCard::AbilityCard() {
	status = true;
	isdisabled = false;
}

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

bool AbilityCard::disabled() {
	return this->isdisabled;
}

void AbilityCard::disable() {
	this->isdisabled = true;
}

void AbilityCard::enable() {
	this->isdisabled = false;
}

string AbilityCard::getType() const
{
	return this->type;
}

void AbilityCard::useAbility(Game&){}

void AbilityCard::printCard(){}
