#include "header/Io_Handler.hpp"

template<class T>
IOHandler<T>::IOHandler(vector<T> acc) 
{
    acceptedInput= acc;
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
            if(!valid) throw bebas();
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

/*
int main(){
    vector<int> acc;
    acc.push_back(1);
    acc.push_back(2);
    acc.push_back(3);

    IOHandler<int> intIO(acc);

    int inp=intIO.getInputInAccepted();
}
*/