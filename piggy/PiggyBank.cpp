#include "PiggyBank.h"
#include <iostream>

using namespace std;

PiggyBank::PiggyBank(double s, bool b){
    savings = s;
    broken = b;
}

double PiggyBank::countSavings(){
    return savings;
}

void PiggyBank::depositMoney(double deposit){
    if(broken == false){
        if(deposit > 0)
            savings += deposit;
        else{
            cout << "Deposit must be positive\n";
        }
    }
    else{
        cout << "Bank is Broken\n";
    }
}

int PiggyBank::smash(){
    broken = true;
    savings = 0;
    return savings;
}
