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

/* Return maximum element of a Comparable vector, must contain at least one element */
template <class T>
T &maxElmt(const vector<T> &);

/* Return index of maximum element of a Comparable vector, must contain at least one element */
template <class T>
int maxElmtidx(const vector<T> &);

#endif
