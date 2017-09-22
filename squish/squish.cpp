//Glory Obielodan
//A02042652
//CS 1400
//Section 002

#include <iostream>
using namespace std;

int main()
{
    char response;
    int legs;
    cout << "Should you squish the bug. Well ...\n\n";
    cout << "Is it freaking you out? (y/n): ";
    cin >> response;
    if (response == 'y' || response == 'Y'){
        cout << "\nDoes it bite or suck blood? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y'){
            cout << "\nWill it make an unfortunate noise or mess if squished? (y/n): ";
            cin >> response;
            if (response == 'y' || response == 'Y'){
                cout << "\nPut it in a cup or flush it down the toilet.\n";
            }
            else{
                cout << "\nWill you feel bad if you squish it? (y/n): ";
                cin >> response;
                if (response == 'y' || response == 'Y'){
                    cout << "\nPut it in a cup or flush it down the toilet.\n";
                } else{
                    cout << "\nSQUISH!!!\n";
                }
            }
        }else {
            cout << "\nHow many legs?: ";
            cin >> legs;
            if (legs == 0){
                cout << "\nLeave the poor thing alone.\n";
            }
            if (legs >= 1 && legs <= 7){
                cout << "\nDoes it hiss? (y/n): ";
                cin >> response;
                if (response == 'y' || response == 'Y'){
                    cout << "\nSQUISH!!!\n";
                } else{
                    cout << "\nIs it a ladybug or a praying mantis? (y/n): ";
                    cin >> response;
                    if (response == 'y' || response == 'Y'){
                        cout << "\nPut it in a cup and take it outside.\n";
                    }else{
                        cout << "\nDo you believe in reincarnation? (y/n): ";
                        cin >> response;
                        if (response == 'y' || response == 'Y'){
                        cout << "\nPut it in a cup and take it outside.\n";
                        }else{
                            cout << "\nSQUISH!!!\n";
                        }
                    }
                }
            }
            if(legs >= 8){
                cout << "\nIs it a Caterpillar? (y/n): ";
                cin >> response;
                if (response == 'y' || response == 'Y'){
                    cout << "\nMake a nice home for it in a shoebox.\n";
                }
                else{
                    cout << "\nHas it spelled out words in a web? (y/n): ";
                    cin >> response;
                    if(response == 'y' || response == 'Y'){
                        cout << "\nSome Bug.\n";
                    }else {
                        cout << "\nSQUISH!!!\n";
                    }
                }
            }
        }
    }
    else{
        cout << "\nWhy not?\n";
        cout << "\nAre you an entomologist? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y'){
            cout << "\nCool. Look over there <-\n";
        }
        else {
            cout << "\nAre you nine? (y/n): ";
            cin >> response;
            if(response == 'y' || response == 'Y') {
                cout << "\nPut it in a cup and freak someone with it.\n";
            }
            else{
                cout << "\nJust Squish it already.\n";
            }
        }
    }
   return 0;
}
