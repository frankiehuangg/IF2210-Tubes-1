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
T& maxElmt (vector<T>& container) {
	T maxx;
	if(!container.empty()){
		vector<T>::iterator it = container.begin();
		maxx = *it;
		++it;

		// start iteration from 2nd elmt
		while(it != container.end()) {
			if(maxx < *it) maxx = *it;
			++it;
		}
	}
	return maxx;
}