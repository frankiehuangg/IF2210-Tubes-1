#include "header/AbilityCard.hpp"

bool AbilityCard::getStatus() const
{
	return this->status;
}

void AbilityCard::setStatus(bool status)
{
	this->status = status;
}
