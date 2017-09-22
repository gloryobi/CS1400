//Glory Obielodan
//CS 1400
//Section 002

#include <iostream>
#include <cmath>
#include "lunarLander.h"

using namespace std;

Lander::Lander(){G.x = 0; G.y = -1.622; angle = PI/2; velocity.y = 0; velocity.x = 0; fuel = 200; position.y = 10, position.x = 30; maxTouchdownVelocity = 5; crashed = false; landed = false;}
Lander::Lander(Vect iG, double iangle, Vect ivelocity, double ifuel, Vect iposition , double imax, bool icrashed, bool ilanded){
    G = iG;
    if(iangle >= 0 && iangle <= 2*PI)
        angle = iangle;
    velocity = ivelocity;
    if(ifuel > 0)
        fuel = ifuel;
    if(iposition.y >= 0)
        position = iposition;
    if(imax >= 0)
        maxTouchdownVelocity = imax;
    if(icrashed != ilanded)
        crashed = icrashed;
    if(icrashed != ilanded)
        landed = ilanded;
}
double Lander::getAngle(){
    return angle;
}
Vect Lander::getVelocity(){
    return velocity;
}
double Lander::getFuel(){
    return fuel;
}
Vect Lander::getPosition(){
    return position;
}
double Lander::getMTV(){
    return maxTouchdownVelocity;
}
bool Lander::getCrashed(){
    if((position.y <= 1) && velocity.y > maxTouchdownVelocity){
        return true;
    }
    if(velocity.y < 0){
        return true;
    }

}

bool Lander::getLanded(){
    if((position.y <= 1) && (velocity.y >= 0 && velocity.y <= maxTouchdownVelocity)){
        return true;
    }
    if((position.y <= 1) && velocity.y < 0){
        return false;
    }
}

void Lander::rotateLeft(double rotateAngle){
    if(rotateAngle < 0) rotateAngle *= -1;
    if(rotateAngle >= 0 && rotateAngle <= PI/12){
        rotatedThisTurn = rotateAngle;
    }
    else{
        rotateAngle = PI/12;
        rotatedThisTurn = rotateAngle;
    }
}
void Lander::rotateRight(double rotateAngle){
    if(rotateAngle < 0) rotateAngle *= -1;
    if(rotateAngle >= 0 && rotateAngle <= PI/12){
        rotatedThisTurn = rotateAngle;
    }
    else{
        rotateAngle = PI/12;
        rotatedThisTurn = rotateAngle;
    }
    rotatedThisTurn *= -1;
}
void Lander::burn(double fuelAmount){
    if(fuelAmount < 0) fuelAmount *= -1;
    if(fuelAmount >= 0 && fuelAmount <= 50){
        fuelBurnedThisTurn = fuelAmount;
    }
    else{
        fuelAmount = 50;
        fuelBurnedThisTurn = fuelAmount;
    }
}
void Lander::timeUpdate(){
    thrust.x=cos(angle)*fuelBurnedThisTurn;
    thrust.y=sin(angle)*fuelBurnedThisTurn;
    angle = getAngle() + rotatedThisTurn;
    if(angle < 0)
        angle += 2*PI;
    if(angle > 2*PI)
        angle -= 2*PI;
    velocity = getVelocity();
    velocity.x += thrust.x;
    velocity.y += thrust.y;
    velocity.x += G.x;
    velocity.y += G.y;
    position = getPosition();
    position.x += velocity.x;
    position.y += velocity.y;
    landed = getLanded();
    crashed = getCrashed();
    fuel = getFuel() - fuelBurnedThisTurn;
    rotatedThisTurn = 0;
    fuelBurnedThisTurn = 0;
}


