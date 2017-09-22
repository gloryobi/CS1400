//Glory Obielodan
//CS 1400
//Section 002

#include <iostream>
#include <iomanip>

using namespace std;

void menu(){
    cout << "Please choose an option valued customer\n\n";
    cout << "S - Report the Machine Status\n";
    cout << "D - Drop in a quarter\n";
    cout << "1 - Pull the 1st Knob: Lucky Strikes - $0.75\n";
    cout << "2 - Pull the 2nd Knob: Camels - $0.75\n";
    cout << "3 - Pull the 3rd Knob: Gauloises - $0.75\n";
    cout << "4 - Pull the 4th Knob: Pall Malls - $0.75\n";
    cout << "R - Restock Machine\n";
    cout << "Q - Quit\n\n";
    }

int main()
{
    char response = 'x';
    int ls = 5, ca = 7, ga = 1, pm = 6;
    double money = 24.50, pay = 0;

    menu();
    while (response != 'q'){
        if(ls == 0 || ca == 0 || ga == 0 || pm == 0){
            cout << "Need to Restock: An item slot is empty\n\n";
        }
        cout << ">";
        cin >> response;
        cout << endl;
        if (response == 's' || response == 'S'){
                cout << "1: " << ls << " Packs of Lucky Strikes\n";
                cout << "2: " << ca << " Packs of Camels\n";
                cout << "3: " << ga << " Packs of Gauloises\n";
                cout << "4: " << pm << " Packs of Pall Malls\n";
                cout << "There is $" << setprecision(2) << fixed << money << " in the machine\n\n";
        }
        else if (response == 'd' || response == 'D'){
            if(ls != 0 && ca != 0 && ga != 0 && pm != 0){
                pay = pay + .25;
                money = money + .25;
                cout << setprecision(2) << fixed << pay << endl;
                cout << endl;
            }
        }
        else if (response == 'q' || response == 'Q'){
            response = 'q';
            cout << "Good Bye Valued Customer\n";
        }
        else if (response == '1'){
            if(ls != 0 && ca != 0 && ga != 0 && pm != 0){
                if (pay < .75){
                    cout << "What you doing I need more Money: The price is $0.75\n\n";
                }
                else{
                    if (pay > .75){
                        cout << "You gave me too much money, here is $" << setprecision(2) << fixed << pay - .75 << " back\n\n";
                        money = money - (pay - .75);
                        ls -= 1;
                        cout << "Here is a Pack of Lucky Strikes\n\n";
                        pay = 0;
                    }
                    else if (pay = .75){
                        ls -= 1;
                        cout << "Here is a Pack of Lucky Strikes\n\n";
                        pay = 0;
                    }
                }
            }
        }
        else if (response == '2'){
            if(ls != 0 && ca != 0 && ga != 0 && pm != 0){
                if (pay < .75){
                    cout << "What you doing I need more Money: The price is $0.75\n\n";
                }
                else{
                    if (pay > .75){
                        cout << "You gave me too much money, here is $" << setprecision(2) << fixed << pay - .75 << " back\n\n";
                        money = money - (pay - .75);
                        ca -= 1;
                        cout << "Here is a Pack of Camels\n\n";
                        pay = 0;
                    }
                    else if (pay = .75){
                        ca -= 1;
                        cout << "Here is a Pack of Camels\n\n";
                        pay = 0;
                    }
                }
            }
        }
        else if (response == '3'){
            if(ls != 0 && ca != 0 && ga != 0 && pm != 0){
                if (pay < .75){
                    cout << "What you doing I need more Money: The price is $0.75\n\n";
                }
                else{
                    if (pay > .75){
                        cout << "You gave me too much money, here is $" << setprecision(2) << fixed << pay - .75 << " back\n\n";
                        money = money - (pay - .75);
                        ga -= 1;
                        cout << "Here is a Pack of Gauloises\n\n";
                        pay = 0;
                    }
                    else if (pay = .75){
                        ga -= 1;
                        cout << "Here is a Pack of Gauloises\n\n";
                        pay = 0;
                    }
                }
            }
        }
        else if (response == '4'){
            if(ls != 0 && ca != 0 && ga != 0 && pm != 0){
                if (pay < .75){
                    cout << "What you doing I need more Money: The price is $0.75\n\n";
                }
                else{
                    if (pay > .75){
                        cout << "You gave me too much money, here is $" << setprecision(2) << fixed << pay - .75 << " back\n\n";
                        money = money - (pay - .75);
                        pm -= 1;
                        cout << "Here is a Pack of Pall Malls\n\n";
                        pay = 0;
                    }
                    else if (pay = .75){
                        pm -= 1;
                        cout << "Here is a Pack of Pall Malls\n\n";
                        pay = 0;
                    }
                }
            }
        }
        else if (response == 'r' || response == 'R'){
            ls = 10;
            ca = 10;
            ga = 10;
            pm = 10;
            money = 0;
        }
        else{
            cout << "Invalid Input: (I do not understand)\n\n";
        }
    }
    return 0;
}
