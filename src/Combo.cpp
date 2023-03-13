#include "Combo.hpp"

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