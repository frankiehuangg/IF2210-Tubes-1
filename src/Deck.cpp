#include "header/Deck.hpp"
#include "header/Io_Handler.hpp"

Deck::Deck() : Inventory(52) {
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j <= 3; j++) {
            cards.push_back(MainCard(i, j));
        }
    }
    
    // initiate ability cards
    AbilityCard* card;
    
    card = new ReRoll;
    abilities.push_back(card);
    usedBy.emplace(card, -1);

    card = new Quadruple;
    abilities.push_back(card);
    usedBy.emplace(card, -1);
    
    card = new Quarter;
    abilities.push_back(card);
    usedBy.emplace(card, -1);
    
    card = new Reverse;
    abilities.push_back(card);
    usedBy.emplace(card, -1);
    
    card = new Swap;
    abilities.push_back(card);
    usedBy.emplace(card, -1);
    
    card = new Switch;
    abilities.push_back(card);
    usedBy.emplace(card, -1);

    card = new Abilityless;
    abilities.push_back(card);
    usedBy.emplace(card, -1);

    abilityCardTop = 6;  // 0..6, -1 means empty


}

Deck::~Deck() {
    for(AbilityCard* card : abilities) {
        delete card;
    }
}

// Acak MainCard
void Deck::shuffleMainCards() {
    int size = cards.size();
    
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        int idx = rand() % size;  // generate random index from 0..size
        // swap
        MainCard temp = cards[i];
        cards[i] = cards[idx];
        cards[idx] = temp;
    }
}

// Baca urutan deck dari file
void Deck::getDeckFromInput() {
    vector<MainCard> tempcards;
    // create card table to check for duplicate card during input
    map<MainCard, bool> cardTable;
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j <= 3; j++) {
            cardTable.emplace(MainCard(i, j), false);
        }
    }

    cout << "Input nama file: ";
    string filename;
    do {
        getline(cin, filename);
    } while (filename == "");

    FILE* fin = fopen(filename.c_str(), "r");
    if(fin == NULL){
        cout << "File not found\n";
        throw InvalidFile();
    }

    // parse input
    char line[100];
    int n = 1;
    try {
        while(fgets(line, sizeof(line), fin)!=NULL) {
            int num, color;
            char dummy;
            if(sscanf(line, "%d %d %c", &num, &color, &dummy) != 2) throw InvalidFileInput();

            MainCard inCard(num, color);
            if(cardTable[inCard]) throw DuplicateCardExist();
            tempcards.push_back(inCard);
            n++;
        }
        
        if(tempcards.size() < 52) {
            throw CardsIncomplete();
        }
    }
    catch (InvalidFileInput& err) {
        cout << err.printError() << n << '\n';
        throw InvalidFile();
    }
    catch (DuplicateCardExist& err) {
        cout << err.printError() << n << '\n';
        throw InvalidFile();
    }
    catch (CardsIncomplete& err) {
        cout << err.printError() << '\n';
        throw InvalidFile();
    }

    cards = tempcards;
}

// Acak AbilityCard
void Deck::shuffleAbilityCards() {
    int size = abilities.size();
    
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        int idx = rand() % size;  // generate random index from 0..size
        // swap
        AbilityCard* temp = abilities[i];
        abilities[i] = abilities[idx];
        abilities[idx] = temp;
    }
}

// Cetak kartu
void Deck::printCards() {
    vector<MainCard> temp=getInventoryCards();
    int size=temp.size();
    while(size>0)
    {
        int decrease=min(size,10);
        vector<MainCard>print;
        for(int i=0;i<decrease;i++) 
            print.push_back(temp[i]);

        vector<MainCard>::iterator it = temp.begin();
	    vector<MainCard>::iterator it2 = temp.begin()+decrease;
        temp.erase(it,it2);

        cout<<print;
        print.clear();
        
        size-=decrease;   
    }
    
}

AbilityCard* Deck::takeAbilityFromDeck(int n) {
    AbilityCard* ability = abilities[abilityCardTop];
    abilityCardTop--;
    usedBy[ability] = n;
    return ability;
}

void Deck::returnAbilityToDeck(AbilityCard * ability) {
    ability->setStatus(true);   // kartu kembali bisa digunakan
    ability->enable();          // kartu yang sebelumnya ter-disable oleh abilityless kembali di enable
    usedBy[ability] = -1;
    abilityCardTop++;
}
