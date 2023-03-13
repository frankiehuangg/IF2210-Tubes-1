#include "header/Combo.hpp"

const map<int, float> Combo::combo_list = {make_pair(0,0.0), make_pair(1,1.0), make_pair(2,2.0), make_pair(3,4.0), make_pair(4,8.0), make_pair(5,16.0), make_pair(6,32.0), make_pair(7,64.0), make_pair(8,128.0)};


Combo::Combo(const Player& player, const Table& table) {
    value = 0;
    vector<MainCard> handCard = player.getInventoryCards();
    vector<MainCard> tableCard = table.getInventoryCards();

    // for (int i = 0; i < (1 << handCard.size()); i++) {
    //     for(int j = 0; j < (1 << tableCard.size()); j++) {
    //         vector<MainCard> temp;

    //     }
    // }

    vector<vector<MainCard>> perm;
    vector<MainCard> temp;

    // handCard must be of size 2
    // insert handCard permutations
    // insert {hand_0}
    temp.push_back(handCard[0]);
    perm.push_back(temp);
    
    // insert {hand_0, hand_1}
    temp.push_back(handCard[1]);
    perm.push_back(temp);
    temp.clear();
    
    // insert {hand_1}
    temp.push_back(handCard[1]);
    perm.push_back(temp);
    temp.clear();

    // insert tableCard permutations
    for (int i = 0; i < tableCard.size(); i++){
        int n = perm.size();
        for(int j = 0; j < n; j++){
            if(perm[j].size() < 5){
                temp = perm[j];
                temp.push_back(tableCard[i]);
                perm.push_back(temp);
                temp.clear();
            }
        }
    }

    // check for combos
    for(int i = 0; i < perm.size(); i++){
        sort(perm[i].begin(), perm[i].end());
        if(/*StraightFlush(perm[i])*/){
            // count
        }
    }
        
}

float Combo::getValue() const {
    return value;
}

void Combo::setValue(float _value) {
    value = _value;
}

/***** Comparison *****/
// Implementasi combo pakai map
// Cek apakah nilai kombo > kombo lain
bool Combo::operator> (Comparable& other) {
    return value > other.getValue();
}

// Cek apakah nilai kombo < kombo lain
bool Combo::operator< (Comparable& other) {
    return value < other.getValue();
}

// Cek apakah nilai kombo == kombo lain
bool Combo::operator== (Comparable& other) {
    return value == other.getValue();
}

/*
Methods untuk melakukan pengecekan combo pada suatu subset/sublist kartu.
Prekondisi: ukuran subset/sublist kartu minimal 1 dan subset kartu terurut menaik berdasarkan nomor kartu dan warna
*/

bool Combo::checkHighCard(vector<MainCard>& cardSublist) 
{
    return cardSublist.size() == 1;
}

bool Combo::checkPair(vector<MainCard>& cardSublist) 
{
    if (cardSublist.size() != 2) return false;
    return cardSublist[0].getNumber() == cardSublist[1].getNumber();
}

bool Combo::checkTwoPair(vector<MainCard>& cardSublist) 
{
    if (cardSublist.size() != 4) return false;
    return cardSublist[0].getNumber() == cardSublist[1].getNumber() && 
    cardSublist[2].getNumber() == cardSublist[3].getNumber();
}

bool Combo::checkThreeOfaKind(vector<MainCard>& cardSublist) 
{
    if (cardSublist.size() != 3) return false;
    return cardSublist[0].getNumber() == cardSublist[1].getNumber() &&
    cardSublist[1].getNumber() == cardSublist[2].getNumber();
}

bool Combo::checkStraight(vector<MainCard>& cardSublist)
{
    if (cardSublist.size() != 5) return false;
    for (int i = 0; i < 4; i++) 
    {
        if (cardSublist[i].getNumber() + 1 != cardSublist[i + 1].getNumber()) return false;
    }
    return true;
}

bool Combo::checkFlush(vector<MainCard>& cardSublist) 
{
    if (cardSublist.size() != 5) return false;
    int color = cardSublist[0].getColor();
    for (int i = 1; i < 5; i++) 
    {
        if (cardSublist[i].getColor() != color) return false;
    }
    return true;
}

bool Combo::checkFullHouse(vector<MainCard>& cardSublist)
{
    if (cardSublist.size() != 5) return false;
    int cardNum1 = cardSublist[0].getNumber();
    int cardNum2 = cardSublist[cardSublist.size() - 1].getNumber();
    int count1 = 0, count2 = 0;
    for (MainCard card: cardSublist) 
    {
        if (card.getNumber() == cardNum1) ++count1;
        else if (card.getNumber() == cardNum2) ++count2;
        else return false;
    }
    return (count1 == 2 && count2 == 3) || (count1 == 3 && count2 == 2);
}

bool Combo::checkFourOfaKind(vector<MainCard>& cardSublist)
{
    if (cardSublist.size() != 5) return false;
    int cardNum = cardSublist[0].getNumber();
    for (int i = 1; i < 5; i++) 
    {
        if (cardSublist[i].getNumber() != cardNum) return false;
    }
    return true;
}

bool Combo::checkStraightFlush(vector<MainCard>& cardSublist) 
{
    return checkStraight(cardSublist) && checkFlush(cardSublist);
}