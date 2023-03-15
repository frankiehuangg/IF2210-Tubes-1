#ifndef _COMPARABLE_HPP_
#define _COMPARABLE_HPP_

#include <vector>

using std::vector;

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

/* Return maximum element of a Comparable vector, must contain at least one element, else return default constructed object of elmt type */
template <class T>
T &maxElmt(vector<T> &);

#endif
