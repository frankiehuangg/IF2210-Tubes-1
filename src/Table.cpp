#include "header/Table.hpp"
#include <iostream>
using namespace std;

/***** Constructor and destructor *****/
// Construct sebuah table dengan amount = 5, opened = 0, serta inisialisasikan atribut cards dengan panjang amount
Table::Table(Inventory& deck):Inventory(5){ 
    this->opened=0;   
    vector<MainCard>grabbedCards=deck-5;
    (*this) + grabbedCards;
}

// Tambahkan nilai opened dengan 1
void Table::openCard(){
    this->opened +=1;
}

// Print semua kartu yang terdapat pada table (yang sudah terbuka)
void Table::printCards(){
    for(int i=0; i < opened; i++){
        this->cards[i].printCard();
    }
}


