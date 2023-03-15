#ifndef _IO_HANDLER_HPP_
#define _IO_HANDLER_HPP_

#include<iostream>
#include<vector>
#include<exception>
using namespace std;

template<class T>
class IOHandler{
    private:
    vector<T> acceptedInput;
    
    public:

    IOHandler(vector<T>);

    T getInput();

    T getInputInAccepted();
};



#endif