#include "Combo.hpp"

class ComboCalculator:public Table{
    private:
    vector<MainCard> stored;
    vector<Player> players;
    vector<Combo> combos;
    float value;
    string comboType;
    int playerNum;

    public:
    /* ComboCalculator constructor */
    ComboCalculator(){}

    /* Start the module */
    void start();

    /* Calculate all combos */
    void calculate();

    /* Announce winner */
    void announce();

    /* Input a certain amount of card 
     * @param int amount        Amount of card to be input */
    void getCard(int);

};

void ComboCalculator::getCard(int amount){
    int tempNum, tempCol;
    IOHandler<int> intIO;

    for(int j=1;j<=amount;j++){
        cout<<"Masukkan kartu ke- "<<j<<":"<<endl;

        bool invalid=true;
        while(invalid){
            invalid=false;
            cout<<"Masukkan nomor kartu(1-13)"<<endl;
            tempNum=intIO.getInputInAccepted(1,13);

            cout<<"Masukkan warna kartu(0-3)"<<endl;
            tempCol=intIO.getInputInAccepted(0,3);

            for(MainCard m: stored)
            {
                if(tempNum==m.getNumber() && tempCol==m.getColor()){
                    invalid=true;
                    cout<<"Kartu telah ada, tolong masukkan kartu yang berbeda!"<<endl;
                }

            }
        }
        MainCard cardtemp(tempNum,tempCol);
        stored.push_back(cardtemp);
        cout<<endl;
    }
}

void ComboCalculator::start()
{
    IOHandler<int> intIO;

    cout<<"Masukkan jumlah pemain(1-7)"<<endl;
    playerNum=intIO.getInputInAccepted(1,7);

    int tempNum;
    int tempCol;
    for(int i=1; i<=playerNum; i++)
    {
        cout<<"Masukkan untuk player ke-"<<i<<endl;
        getCard(2);
    }

    cout<<"Masukkan untuk table"<<endl;
    getCard(5);

    (*this).operator+(stored);

    calculate();
    announce();
}

void ComboCalculator::calculate()
{
    Table t;
    t.setOpened(7);
    for(int i=1; i<=playerNum; i++)
    {
        Player p=Player("dummy",i);
        p.takeCardFromDeck((*this),2);
        players.push_back(p);
        p.printCards();
    }

    t.takeCardFromDeck((*this),5);
    t.printCards();

   for (int i = 0; i < playerNum; i++){
		Player& player = players[i];
		Combo c = Combo(player, t);
        combos.push_back(c);
		player.printInfo();

		cout << this->combos[i];
		cout << this->combos[i].what() << '\n';
	}  
}

void ComboCalculator::announce()
{
    int winnerID=maxElmtidx(this->combos);
    cout << "Pemain " << this->players[winnerID].getPlayerNumber() << " memenangkan permainan!" << endl;
    
    //cout<<"Combo tertinggi dari susunan ini adalah "<<comboType<<endl;
    //cout<<"dengan skor "<<value<<endl;
}