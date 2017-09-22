// name: Glory Obielodan
// A number: A02042652
// section number: 002

#include <iostream>
#include <cmath>

using namespace std;

// This function determines the drawlength.
//  Insert your code between the start and end comments *only*
float GetX(float distance, float theta){
	float drawlength;
	//TODO: write your code here
	//start of your code
    float G = 9.8, K = 25, M = 0.065;
    theta = theta * (3.14159/180);
    drawlength = sqrt((M*G*distance)/(K*sin(2*theta)));
	//end of your code

	return drawlength;
}


// make no changes here
int main(){
	float dist,theta;

	dist = 100;
	theta = 1;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 15;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 30;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 45;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 60;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 75;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;

	dist = 100;
	theta = 89;
	cout << "distance: " << dist << "   theta: " << theta << "   draw: " << GetX(dist,theta)<<endl;


	return 0;
}

