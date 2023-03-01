#ifndef _COMPARABLE_HPP_
#define _COMPARABLE_HPP_

class Comparable {
protected:
	float value;

public:
	/***** Getter & Setter *****/
	virtual float getValue() const = 0;
	virtual void setValue(float) = 0;

	/***** Comparison operator *****/
	virtual bool operator< (Comparable&) = 0;
	virtual bool operator> (Comparable&) = 0;
	virtual bool operator== (Comparable&) = 0;
};

#endif
