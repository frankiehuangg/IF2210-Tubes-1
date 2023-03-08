#include "header/Table.hpp"
#include <iostream>
using namespace std;

/***** Constructor and destructor *****/
// Construct sebuah table dengan amount = 5, opened = 0, serta inisialisasikan atribut cards dengan panjang amount
 
//ples update table constructor @frank
Table::Table(Inventory& deck){ 
    this->amount=5;
    this->opened=0;   
    for(int i=0;i<this->amount;i++){
        (*this)=(*this)+deck;
    }
}

// Tambahkan nilai opened dengan 1, kemudian panggil fungsi operator +
void Table::openCard(){
    this->opened +=1;
    // fungsi operator + ?
}

// Print semua kartu yang terdapat pada table (yang sudah terbuka)
void Table::printCards(){
    for(int i=0; i < opened; i++){
        this->cards[i].printCard();
    }
}


