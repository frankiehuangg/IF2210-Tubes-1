#include "header/Combo.hpp"
// ini nanti dipindahin ke Combo.cpp 

/*
Methods untuk melakukan pengecekan combo pada suatu subset kartu.
Prekondisi: ukuran subset kartu minimal 1 dan subset kartu terurut menaik berdasarkan nomor kartu dan warna
*/

bool checkHighCard(vector<MainCard>& cards) 
{
    return cards.size() == 1;
}

bool checkPair(vector<MainCard>& cards) 
{
    if (cards.size() != 2) return false;
    return cards[0].getNumber() == cards[1].getNumber();
}

bool checkTwoPair(vector<MainCard>& cards) 
{
    if (cards.size() != 4) return false;
    return cards[0].getNumber() == cards[1].getNumber() && 
    cards[2].getNumber() == cards[3].getNumber();
}

bool checkThreeOfaKind(vector<MainCard>& cards) 
{
    if (cards.size() != 3) return false;
    return cards[0].getNumber() == cards[1].getNumber() &&
    cards[1].getNumber() == cards[2].getNumber();
}

bool checkStraight(vector<MainCard>& cards)
{
    if (cards.size() != 5) return false;
    for (int i = 0; i < 4; i++) 
    {
        if (cards[i].getNumber() + 1 != cards[i + 1].getNumber()) return false;
    }
    return true;
}

bool checkFlush(vector<MainCard>& cards) 
{
    if (cards.size() != 5) return false;
    int color = cards[0].getColor();
    for (int i = 1; i < 5; i++) 
    {
        if (cards[i].getColor() != color) return false;
    }
    return true;
}

bool checkFullHouse(vector<MainCard>& cards)
{
    if (cards.size() != 5) return false;
    int cardNum1 = cards[0].getNumber();
    int cardNum2 = cards[cards.size() - 1].getNumber();
    int count1 = 0, count2 = 0;
    for (MainCard card: cards) 
    {
        if (card.getNumber() == cardNum1) ++count1;
        else if (card.getNumber() == cardNum2) ++count2;
        else return false;
    }
    return (count1 == 2 && count2 == 3) || (count1 == 3 && count2 == 2);
}

bool checkFourOfaKind(vector<MainCard>& cards)
{
    if (cards.size() != 5) return false;
    int cardNum = cards[0].getNumber();
    for (int i = 1; i < 5; i++) 
    {
        if (cards[i].getNumber() != cardNum) return false;
    }
    return true;
}

bool checkStraightFlush(vector<MainCard>& cards) 
{
    return checkStraight(cards) && checkFlush(cards);
}