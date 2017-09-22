#include "unit.h"
#include "ogo.h"
#include <iostream>

using namespace std;

//getR() test
bool test01(){
	ogo u(10,22,4,up,archer,false,"ogo");
	int r=u.getR();
	if(r==10){
		return true;
	}else{
		return false;
	}
}

//getC() test
bool test02(){
	ogo u(10,22,4,up,archer,false,"ogo");
	int c=u.getC();
	if(c==22){
		return true;
	}else{
		return false;
	}
}

//getHp() test
bool test03(){
	ogo u(10,22,4,up,archer,false,"ogo");
	int hp=u.getHp();
	if(hp==4){
		return true;
	}else{
		return false;
	}
}

//getDir() test
bool test04(){
	ogo u(10,22,4,up,archer,false,"ogo");
	Dir dir=u.getDir();
	if(dir==up){
		return true;
	}else{
		return false;
	}
}

//getRank() test
bool test05(){
	ogo u(10,22,4,up,archer,false,"ogo");
	Rank irank=u.getRank();
	if(irank==archer){
		return true;
	}else{
		return false;
	}
}

//getDead() test
bool test06(){
	ogo u(10,22,4,up,archer,false,"ogo");
	bool dead=u.getDead();
	if(dead==false){
		return true;
	}else{
		return false;
	}
}

//getTla() test
bool test07(){
	ogo u(10,22,4,up,archer,false,"ogo");
	string itla=u.getTla();
	if(itla=="ogo"){
		return true;
	}else{
		return false;
	}
}

//Attack() test
bool test08(){
	ogo u(10,22,4,up,infantry,false,"ogo");

	int hits;
	int i=0;
	while(i<100000){
		hits=u.Attack();
		if(hits<0 || hits > u.getHp())return false;
		i++;
	}

	return true;
}

//Place() test
bool test09(){
	ogo u(10,22,4,up,archer,false,"ogo");
	SitRep s;
	int i,j;
	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			s.thing[i][j].what=rock;
		}
	}
	s.thing[12][12].what=space;
	s.nearestEnemyCrown.r=25;
	s.nearestEnemyCrown.c=25;
	s.nearestEnemyCrown.dirFor=up;
	s.nearestEnemy.r=22;
	s.nearestEnemy.c=22;
	s.nearestEnemy.dirFor=lt;
	s.anyOpenSpace=up;
	s.turnNumber=234;

	u.Place(9,15,9,15,s);
	int r = u.getR();
	int c = u.getC();

	if(r==12 && c==12){
		return true;
	}else{
		return false;
	}
}

//Recommendation() test
bool test10(){
	ogo u(10,22,4,dn,infantry,false,"ogo");
	SitRep s;
	Action a;
	int i,j;
	for(i=0;i<ROWS;++i){
		for(j=0;j<COLS;++j){
			s.thing[i][j].what=space;
		}
	}
	s.thing[12][12].what=space;
	s.nearestEnemyCrown.r=25;
	s.nearestEnemyCrown.c=25;
	s.nearestEnemyCrown.dirFor=up;
	s.nearestEnemy.r=11;
	s.nearestEnemy.c=22;
	s.nearestEnemy.dirFor=up;
	s.anyOpenSpace=up;
	s.turnNumber=234;

	a = u.Recommendation(s);

    if(a.action == turn){
		return true;
	}else{
		return false;
	}
}

//Turn() test
bool test11(){
	ogo u(10,22,4,up,archer,false,"ogo");
    u.Turn(dn);
    int dir = u.getDir();
	if(dir == dn){
		return true;
	}else{
		return false;
	}
}

//Move() test
bool test12(){
	ogo u(42,16,4,up,knight,false,"ogo");
	u.Move(3);
	int r = u.getR();
	int c = u.getC();
	if(r==39 && c==16){
		return true;
	}else{
		return false;
	}
}

//Suffer() test
bool test13(){
	ogo u(10,22,10,up,archer,false,"ogo");
    u.Suffer(4);
    int hp = u.getHp();
    if(hp == 6){
		return true;
	}else{
		return false;
	}
	return 1;
}

int main(){

	if(!test01()){cout<<"failed test01.\n";exit(1);}
	if(!test02()){cout<<"failed test02.\n";exit(1);}
	if(!test03()){cout<<"failed test03.\n";exit(1);}
	if(!test04()){cout<<"failed test04.\n";exit(1);}
	if(!test05()){cout<<"failed test05.\n";exit(1);}
	if(!test06()){cout<<"failed test06.\n";exit(1);}
	if(!test07()){cout<<"failed test07.\n";exit(1);}
	if(!test08()){cout<<"failed test08.\n";exit(1);}
	if(!test09()){cout<<"failed test09.\n";exit(1);}
	if(!test10()){cout<<"failed test10.\n";exit(1);}
	if(!test11()){cout<<"failed test11.\n";exit(1);}
	if(!test12()){cout<<"failed test12.\n";exit(1);}
	if(!test13()){cout<<"failed test13.\n";exit(1);}

	cout<<"You passed all the tests.\n";

	return 0;

}
