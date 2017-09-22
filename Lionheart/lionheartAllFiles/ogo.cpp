#include "ogo.h"
#include <cmath>
#include <iostream>


void ogo::Place(int minR,int maxR,int minC,int maxC, SitRep sitrep){
	bool done=false;
	int tr, tc;
	Dir td;
	while(!done){
		tr=minR+rand()%(maxR-minR);	
		tc=minC+rand()%(maxC-minC);	
		if(sitrep.thing[tr][tc].what==space)done=true;
	}
	int rdist=ROWS/2-tr;
	int cdist=COLS/2-tc;
	if(abs(rdist)<abs(cdist)){
		if(cdist>0)td=rt;
		else td=lt;
	}else{
		if(rdist>0)td=up;
		else td=dn;
	}
	r=tr;
	c=tc;
	dir=td;
}


// tell someone what you want to do
Action ogo::Recommendation(SitRep sitrep){

	// this code is provided as an example only
	// use at your own risk
	Action a;
	Location l;

	// first, try to attack in front of you
	int tr = r, tc = c;
	switch (dir){
	case up: tr--; break;
	case dn: tr++; break;
	case rt: tc++; break;
	case lt: tc--; break;
	case none: break;
	}
	if (rank != crown){
		if (tr >= 0 && tr < ROWS&&tc >= 0 && tc < COLS){
			if (sitrep.thing[tr][tc].what == unit){
				if (sitrep.thing[tr][tc].tla != tla){
					a.action = attack;
					a.ar = tr;
					a.ac = tc;
					return a;
				}
			}
		}
	}
	if (rank != crown){
		if (rank == infantry){
			if (dir == sitrep.nearestEnemy.dirFor){
				a.action = fwd;
				a.maxDist = 1;
				if (rank == knight)a.maxDist = HORSESPEED;
				return a;
			}
			else {
				a.action = turn;
				a.dir = sitrep.nearestEnemy.dirFor;
				return a;
			}
			a.action = nothing;
			return a;
		}
		else if (rank == knight){
			if (dir == sitrep.nearestEnemyCrown.dirFor){
				a.action = fwd;
				a.maxDist = 1;
				if (rank == knight)a.maxDist = HORSESPEED;
				return a;
			}
			else {
				a.action = turn;
				a.dir = sitrep.nearestEnemyCrown.dirFor;
				return a;
			}
			a.action = nothing;
			return a;
		}
		else if (rank == archer){
			if (dir == sitrep.nearestEnemy.dirFor){
				a.action = fwd;
				a.maxDist = 1;
				if (rank == knight)a.maxDist = HORSESPEED;
				return a;
			}
			else {
				a.action = turn;
				a.dir = sitrep.nearestEnemy.dirFor;
				return a;
			}
			a.action = nothing;
			return a;
		}
	}
	if (rank == crown){
		a.action = fwd;
		return a;
	}
}
