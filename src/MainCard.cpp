#include "header/MainCard.hpp"

/* Constructor & destructor */
MainCard::MainCard(int val1, int val2)
{
    this->card.first = val1;
    this->card.second = val2;
}

/***** Getter & Setter *****/
// Number - Assumption: First element of the pair
int MainCard::getNumber() const
{
    return this->card.first;
}
void MainCard::setNumber(int number)
{
    this->card.first = number;
}

// Color - Assumption: Second element of the pair
int MainCard::getColor() const
{
    return this->card.second;
}
void MainCard::setColor(int color)
{
    this->card.second = color;
}

/***** Print *****/
// Print card number and color, ends with endl
void MainCard::printCard()
{
    std::cout << this->card.first << "(" << this->card.second << ")" << endl;
}

/***** Comparison *****/
bool operator< (const MainCard m1, const MainCard m2)
{
	return m1.getValue() < m2.getValue();
}

// Cek apakah nilai kartu < kartu lain
bool MainCard::operator<(Comparable &other)
{
    // Not sure yet
    return this->value < other.getValue();
}

// Cek apakah nilai kartu > kartu lain
bool MainCard::operator>(Comparable &other)
{
    // Not sure yet
    return this->value > other.getValue();
}

// Cek apakah nilai kartu = kartu lain
bool MainCard::operator==(Comparable &other)
{
    // Not sure yet
    return this->value == other.getValue();
}
