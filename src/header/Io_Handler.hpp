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
    /* IOHandler default constructor
	 * @param vector<T> acc 	    Vector of accepted inputs */
    IOHandler();
    
    /* IOHandler constructor
	 * @param vector<T> acc 	    Vector of accepted inputs */
    IOHandler(vector<T>);

    /* accepted adder
	 * @param T acc 	            new accepted inputs */
    void addAccepted(T);

    /***** Input *****/
	/* Input a value of type T */
    T getInput();

    /* Input a value of type T that exists in acceptedInput*/
    T getInputInAccepted();
};

template<class T>
IOHandler<T>::IOHandler() 
{

}

template<class T>
IOHandler<T>::IOHandler(vector<T> acc) 
{
    acceptedInput= acc;
}

template<class T>
void IOHandler<T>::addAccepted(T acc)
{
    acceptedInput.push_back(acc);
}

template<class T>
T IOHandler<T>::getInput()
{
    T input;
    string tmp;
    bool valid = false;
    cin.exceptions(std::istream::failbit);
    while (!valid) 
    {
        try
        {
            cout<< "Masukan input: ";
            cin >> input;
            valid = true;
        }
        catch (exception &e) 
        {
            cout << "Masukan tidak valid. Mohon ulangi." << endl;
            cin.clear();
            getline(cin,tmp);
        }   
    }
    return input;
}

template<class T>
T IOHandler<T>::getInputInAccepted(){
    T input;
    string tmp;
    bool valid = false;
    cin.exceptions(std::istream::failbit);
    while (!valid) 
    {
        try
        {
            cout<< "Masukan input: ";
            cin >> input;
            for(T it: acceptedInput)
            {
                if(input==it)
                valid = true;
            }
            if(!valid) throw InputInvalid();
        }
        catch (exception &e) 
        {
            cout << "Masukan tidak valid. Mohon ulangi." << endl;
            cin.clear();
            getline(cin,tmp);
        }   
    }
    return input;
}

#endif