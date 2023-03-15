#include "header/Table.hpp"
#include <iostream>
using namespace std;

#define C00 "\x1B[0m"
#define C01 "\x1B[31m"
#define C02 "\033[0;33m"
#define C03 "\x1B[32m"
#define C04 "\x1B[34m"
#define C05 "\x1b[38;5;238m"
/***** Constructor and destructor *****/
// Construct sebuah table dengan amount = 5, opened = 0, serta inisialisasikan atribut cards dengan panjang amount
Table::Table():Inventory(5)
{ 
    this->opened = 0;   
}

int Table::getOpened() const{
	return this->opened;
}

void Table::setOpened(int opened)
{
	this->opened = opened;
}

// Tambahkan nilai opened dengan 1
void Table::openCard()
{
    this->opened +=1;
}

// Print semua kartu yang terdapat pada table (yang sudah terbuka)
ostream& operator<<(ostream& os, Table table)
{
	string print[11][5];

	char line[100];

	vector<MainCard> cards = table.getInventoryCards();

	int numCard = cards.size();
	int openThen=table.getOpened();
	if(numCard<openThen) openThen=numCard;

	for (int i = 0; i <openThen; i++)
	{
		FILE *fin = fopen("src/ascii/cards2.txt", "r");

		int line_num = (cards[i].getNumber() - 1) * 11;

		int num = 0;
		while (num < line_num)
		{
			if(fgets(line, sizeof(line), fin)==NULL){
				cout<<"ERROR : error occured when opening file"<<endl;
			}
			num++;
		}

		for (int j = 0; j < 11; j++)
		{
			if(fgets(line, sizeof(line), fin)==NULL){
				cout<<"ERROR : error occured when opening file"<<endl;
			}
			print[j][i] = line;
		}
	}

	for (int i = table.getOpened(); i < numCard; i++)
	{
		FILE *fin = fopen("src/ascii/cards2.txt", "r");

		int line_num = 143;

		int num = 0;
		while (num < line_num)
		{
			if(fgets(line, sizeof(line), fin)==NULL){
				cout<<"ERROR : error occured when opening file"<<endl;
			}
			num++;
		}

		for (int j = 0; j < 11; j++)
		{
			if(fgets(line, sizeof(line), fin)==NULL){
				cout<<"ERROR : error occured when opening file"<<endl;
			}
			print[j][i] = line;
		}
	}

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < openThen; j++)
		{
			if (cards[j].getColor() == 0)
				os << C01 << print[i][j].erase(print[i][j].length()-1) << " ";
			else if (cards[j].getColor() == 1)
				os << C02 << print[i][j].erase(print[i][j].length()-1) << " ";
			else if (cards[j].getColor() == 2)
				os << C03 << print[i][j].erase(print[i][j].length()-1) << " ";
			else
				os << C04 << print[i][j].erase(print[i][j].length()-1) << " ";
		}
		for (int j = table.getOpened(); j < numCard; j++)
		{
			os << C05 << print[i][j].erase(print[i][j].length() - 1) << " ";
		}
		os << endl;
	}

	os << C00;


	return os;
}

void Table::printCards()
{
    cout<<(*this);
}


