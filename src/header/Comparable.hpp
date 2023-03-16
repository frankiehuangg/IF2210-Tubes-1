#ifndef _COMPARABLE_HPP_
#define _COMPARABLE_HPP_

#include <vector>

using namespace std;

class Comparable
{
protected:
	float value;

public:
	/***** Getter & Setter *****/
	/* Returns the current card value */
	float getValue() const;
	/* Set the current card value
	 * @param float value	New card value */
	void setValue(float);

	/***** Comparison operator *****/
	virtual bool operator<(Comparable &) = 0;
	virtual bool operator>(Comparable &) = 0;
	virtual bool operator==(Comparable &) = 0;
};

/* Return maximum element of a vector, must contain at least one element */
template <class T>
T maxElmt(const vector<T> &container)
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

/* Return index of maximum element of a vector, must contain at least one element */
template <class T>
int maxElmtidx(const vector<T> &container)
{
	int maxidx = 0;

	for (int i = 1; i < container.size(); i++)
	{
		T temp=container[i];
		T temp2=container[maxidx];
		if (temp > temp2)
		{
			maxidx = i;
		}
	}
	return maxidx;
}

#endif
