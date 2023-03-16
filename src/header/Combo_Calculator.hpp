#include "Combo.hpp"

class ComboCalculator:public Table{
    public:
    ComboCalculator(){}
    void start();
    void calculate();
    void announce();

    private:
    vector<MainCard> stored;
    float value;
    string comboType;
};

void ComboCalculator::start()
{
    IOHandler<int> intIO;
    int tempNum;
    int tempCol;
    for(int i=1; i<=7; i++)
    {

        cout<<"Masukkan kartu ke- "<<i<<":"<<endl;

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

    (*this).operator+(stored);

    calculate();
    announce();
}

void ComboCalculator::calculate()
{
    Table t;
    Player p("dummy",0);
    p.takeCardFromDeck((*this),2);
    t.takeCardFromDeck((*this),5);
    t.setOpened(7);
    t.printCards();
    
    p.printCards();
    try{
    Combo c(p,t);
    value=c.getValue();
    comboType=c.what();
    }
    catch(char const* cc){
        cout<<cc<<endl;
    }   
}

void ComboCalculator::announce()
{
    cout<<"Combo tertinggi dari susunan ini adalah "<<comboType<<endl;
    cout<<"dengan skor "<<value<<endl;
}