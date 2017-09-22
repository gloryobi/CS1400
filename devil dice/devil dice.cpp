#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void bottom(){
    cout << "\n\nPass[P], Roll[R], or Forfeit[F]: ";
}

void top(){
    cout << setw(8) << "You" << setw(32) << "Devil\n";
    cout << setw(8) << "---" << setw(32) << "-----\n";
}

void turnYou(){
    cout << setw(9) << "Your turn\n";
    cout << setw(9) << "---------\n";
}

void turnDevil(){
    cout << setw(41) << "Devil's turn\n";
    cout << setw(41) << "------------\n";
}

void c1(int y, int n){
    if(y > n-5 && y <= n) cout << setw(2) << y << " >";
    else cout << setw(4) << "";
}

void c2(int n){
    cout << "--" << n;
}

void c3(int s, int n){
    if (n == 0 && s == 0) cout << setw(4) << "";
    else if(s > n-5 && s <= n) cout << " < " << s;
    else cout << setw(4) << "";
}

void c4(int r, int s, int n){
    if (n == 90 && (s > 85 && s < 91)) cout << setw(9) << "die";
    else if(n == 90) cout << setw(10) << "die";
    else if (n == 85 && (s > 80 && s < 86)) cout << setw(9) << "---";
    else if (n == 85) cout << setw(10) << "---";
    else if (n == 80 && (s > 75 && s < 81)) cout << setw(7) << "| " << setw(1) << r << setw(2) << "|";
    else if (n == 80) cout << setw(8) << "| " << setw(1) << r << setw(2) << "|";
    else if (n == 75 && (s > 70 && s < 76)) cout << setw(9) << "---";
    else if (n == 75) cout << setw(10) << "---";
    else if (n == 100) cout << setw(9) << "";
    else if (n >= 0 && n < 10) cout << setw(11) << "";
    else cout << setw(10) << "";
}

void c5(int s2, int s, int n){
    if (n == 100 && s2 == 100) cout << setw(9) << s2 << " >";
    else if (n == 90 && (s2 > 85 && s2 < 91)) cout << setw(9) << s2 << " >";
    else if (n == 85 && (s2 > 80 && s2 < 86)) cout << setw(9) << s2 << " >";
    else if (n == 80 && (s2 > 75 && s2 < 81)) cout << setw(8) << s2 << " >";
    else if (n == 75 && (s2 > 70 && s2 < 76)) cout << setw(9) << s2 << " >";
    else if (n == 10 && (s > 5 && s < 10)) cout << setw(11) << "";
    else if (n == 5 && (s > 0 && s < 6)) cout << setw(11) << "";
    else if (n == 0) cout << setw(11) << "";
    else if (n == 90) cout << setw(11) << "";
    else if (n == 85) cout << setw(11) << "";
    else if (n == 75) cout << setw(11) << "";
    else if (n == 100 && s == 100) cout << setw(9) << "";
    else if (s > n-5 && s <= n) cout << setw(10) << "";
    else if (s2 > n-5 && s2 <= n) cout << setw(9) << s2 << " >";
    else if (n == 80) cout << setw(10) << "";
    else cout << setw(11) << "";
}

void c6(int d, int n){
    if(d > n-5 && d <= n) cout << " < " << d << endl;
    else cout << setw(5) << "\n";
}

void game(int y, int d, int r, int s, int s2){
    for(int n = 100; n >= 0; n-=5){
        c1(y, n);
        c2(n);
        c3(s, n);
        c4(r, s, n);
        c5(s2, s, n);
        c2(n);
        c6(d, n);
    }
}

int main()
{
    ifstream fin;
	ofstream fout;

    fin.open("devilDiceRecord.txt");
	fout.open("devil Dice Record.txt");

	int win = 0, lose = 0;
    int devil = 0;
    int you = 0;
    int scoreRoll = 0;
    int scoreRoll2 = 0;
    int roll = 0;
    char ans;
    char response;
    while(true){
        while (true){
            top();
            game(you, devil, roll, scoreRoll, scoreRoll2);
            turnYou();
            bottom();
            cin >> response;
            if(scoreRoll >= 100){
                win++;
                if(fin){
                    fin >> win;
                    fin >> lose;
                    fin.close();
                }
                cout << "\nYOU WON!!!!!!!!!!!!!\n\n";
                cout << "Wins/Losses record: " << "(" << win << "/" << lose << ")\n";
                cout << "\nDo you want to play again (y/n): ";
                cin >> ans;
                if (ans == 'Y' || ans == 'y'){
                    scoreRoll = 0;
                    you = 0;
                    devil = 0;
                    scoreRoll2 = 0;
                    roll = 0;
                    continue;
                }
                else if(ans == 'n' || ans == 'N'){
                    cout << "\nThank you for playing\n";
                    break;
                }
                else{
                    cout << "\nI don't understand. Enter (y for yes) or (n for no): ";
                    cin >> ans;
                }
            }
            else if (response == 'r' || response == 'R'){
                roll = rand()% 6 + 1;
                if (roll == 1){
                    scoreRoll = 0;
                    roll = 0;
                    break;
                }
                else if(scoreRoll > you){
                    scoreRoll = scoreRoll + roll;
                }
                else{
                    scoreRoll = scoreRoll + you + roll;
                }
            }
            else if (response == 'p' || response == 'P'){
                you = scoreRoll;
                scoreRoll = 0;
                break;
            }
            else if (response == 'f' || response == 'F'){
                cout << "\nDo you want to play again (y/n): ";
                cin >> ans;
                if (ans == 'Y' || ans == 'y'){
                    scoreRoll = 0;
                    you = 0;
                    devil = 0;
                    scoreRoll2 = 0;
                    roll = 0;
                    continue;
                }
                else if(ans == 'n' || ans == 'N'){
                    cout << "\nThank you for playing\n";
                    cout << "\nWins/Losses record: " << "(" << win << "/" << lose << ")\n";
                    break;
                }
                else{
                    cout << "\nI don't understand. Enter (y for yes) or (n for no): ";
                    cin >> ans;
                }
            }
            else
                continue;
        }
        if(ans == 'n' || ans == 'N')
            break;
        //while (true){
        for(int i = 0; i < rand()% 5 + 1; ++i){
            top();
            game(you, devil, roll, scoreRoll, scoreRoll2);
            turnDevil();
            bottom();
            cout << endl;
            cout << endl;
            response = 'r';
            if (scoreRoll2 >= 100){
                lose++;
                if(fin){
                    fin >> win;
                    fin >> lose;
                    fin.close();
                }
                cout << "\nToo bad the devil won.\n\n";
                cout << "Wins/Losses record: " << "(" << win << "/" << lose << ")\n";
                cout << "\nDo you want to play again (y/n): ";
                cin >> ans;
                if (ans == 'Y' || ans == 'y'){
                    scoreRoll2 = 0;
                    devil = 0;
                    you = 0;
                    scoreRoll = 0;
                    roll = 0;
                    continue;
                }
                else if(ans == 'n' || ans == 'N'){
                    cout << "\nThank you for playing\n";
                    break;
                }
                else{
                    cout << "\nI don't understand. Enter (y for yes) or (n for no): ";
                    cin >> ans;
                }
            }
            else if (response == 'r' || response == 'R'){
                roll = rand()% 6 + 1;
                if (roll == 1){
                    scoreRoll2 = 0;
                    roll = 0;
                    break;
                }
                else if(scoreRoll2 > devil){
                    scoreRoll2 = scoreRoll2 + roll;
                }
                else{
                    scoreRoll2 = scoreRoll2 + devil + roll;
                }
            }
        }
        response = 'p';
        if (response == 'p' || response == 'P'){
            devil = scoreRoll2;
            scoreRoll2 = 0;
        }
        /*if(ans == 'n' || ans == 'N')
            break;*/
    }
    fout << "Wins/Losses record: " << "(" << win << "/" << lose << ")";
    fout.close();
    return 0;
}
