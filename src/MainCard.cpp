#include "header/MainCard.hpp"

/* Constructor & destructor */
MainCard::MainCard(int val1, int val2)
{
    this->card.first = val1;
    this->card.second = val2;
}

/***** Getter & Setter *****/
// Value
float MainCard::getValue() const
{
    return this->value;
}
void MainCard::setValue(float value)
{
    this->value = value;
}

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

bool operator<(const MainCard m, const MainCard m2){
    return m.getValue()<m2.getValue();
}