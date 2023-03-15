#include "header/Comparable.hpp"

float Comparable::getValue() const
{
	return this->value;
}

void Comparable::setValue(float value)
{
	this->value = value;
}

template <class T>
T &maxElmt(vector<T> &container)
{
	T maxs = container[0];

	for (T element : container)
	{
		if (element > maxs)
		{
			maxs = element;
		}
	}
	return maxs;
}