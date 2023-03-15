#ifndef _IO_HANDLER_HPP_
#define _IO_HANDLER_HPP_

#include <iostream>
#include <vector>
#include "Exception.hpp"
using namespace std;

template<class T>
class IOHandler{
    private:
    vector<T> acceptedInput;
    
    public:
    /* IOHandler constructor
	 * @param vector<T> acc 	    Vector of accepted inpputs */
    IOHandler(vector<T>);

    /***** Input *****/
	/* Input a value of type T */
    T getInput();

    /* Input a value of type T that exists in acceptedInput*/
    T getInputInAccepted();
};



#endif