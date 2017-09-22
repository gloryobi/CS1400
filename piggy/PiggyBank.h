#ifndef PIGGYBANK_H_INCLUDED
#define PIGGYBANK_H_INCLUDED

#include <iostream>

using namespace std;

class PiggyBank{

public:
    PiggyBank(){ broken = false; savings = 0;}
    PiggyBank(double s, bool b);
    double countSavings();
    void depositMoney(double savings);
    int smash();
    ~PiggyBank(){ if(broken == true) cout << "NOOOOOOOOOOOOOOOO!!!!!\n";}

private:
    bool broken;
    double savings;
};

#endif // PIGGYBANK_H_INCLUDED

