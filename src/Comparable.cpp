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
T &maxElmt(const vector<T> &container)
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

template <class T>
int maxElmtidx(const vector<T> &container)
{
	int maxidx = 0;

	for (int i = 1; i < container.size(); i++)
	{
		if (container[i] > container[maxidx])
		{
			maxidx = i;
		}
	}
	return maxidx;
}