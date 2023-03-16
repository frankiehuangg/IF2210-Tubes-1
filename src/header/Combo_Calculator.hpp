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
