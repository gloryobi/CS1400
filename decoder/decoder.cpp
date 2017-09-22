#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
	ofstream fout;
    char a;

    fin.open("secretMessage.txt");
    fout.open("decodedMessage.txt");

    while(!fin.eof()){
		a = fin.get();
        if((a >= 'A' && a <= 'M') || (a >= 'a' && a <= 'm')){
            a = a + 13;
        }
        else if((a > 'M' && a <= 'Z') || (a > 'm' && a <= 'z')){
            a = a - 13;
        }
        if(!fin.eof())
            fout << a;
    }

    fin.close();
	fout.close();

    return 0;
}
