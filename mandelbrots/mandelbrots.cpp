//Glory Obielodan
//CS 1400
//Section 008
#include <iostream>
#include <fstream>

using namespace std;

const int ROWS=500;
const int COLS=500;
const float C1R=-2;
const float C1I=1;
const float C2R=0;
const float C2I=-1;
const int MAXITERS=256;

struct Complex {
	float real;
	float imag;
};

struct point{
	float x;
	float y;
};

struct color{
	int r;
	int g;
	int b;
};

void PrintComplex(Complex cplx){
	cout << cplx.real << "+" << cplx.imag << "i";
}

Complex AddComplex(Complex c1, Complex c2){
	Complex c3;

	c3.real=c1.real+c2.real;
	c3.imag=c1.imag+c2.imag;
	return c3;
}

Complex MultiplyComplex(Complex c1, Complex c2){
	Complex c3;

	c3.real=c1.real*c2.real-c1.imag*c2.imag;
	c3.imag=c1.real*c2.imag+c1.imag*c2.real;
	return c3;
}

float getReal(int j, Complex c1, Complex c2){
	float interval;
	float real;
	interval=(c2.real-c1.real)/COLS;
	real=c1.real+(interval*j);
	return real;
}

float getImag(int i, Complex c1, Complex c2){
	float interval;
	float imag;
	interval=(c2.imag-c1.imag)/ROWS;
	imag=c1.imag+(interval*i);
	return imag;
}

Complex getComplex(int i, int j, Complex c1, Complex c2){
	Complex c;
	c.real=getReal(j,c1,c2);
	c.imag=getImag(i,c1,c2);
	return c;
}


float getx(int j, point p1, point p2){
	float interval;
	float x;
	interval=(p2.x-p1.x)/COLS;
	x=p1.x+(interval*j);
	return x;
}

float gety(int i, point p1, point p2){
	float interval;
	float y;
	interval=(p2.y-p1.y)/ROWS;
	y=p1.y+(interval*i);
	return y;
}

point getPoint(int i, int j, point p1, point p2){
	point p;
	p.x=getx(j,p1,p2);
	p.y=gety(i,p1,p2);
	return p;
}

color getColor(int i){
	color c;
	i%=256;
	c.r=i%(MAXITERS/5)*10;
	c.g=i/(MAXITERS*50)/20;
	c.b=i%(MAXITERS/5)*50;
	return c;
}

int distFromOrigSq(point p){
	return p.x*p.x + p.y*p.y;
}

bool isInsideUnitCircle(point p){
	if(p.x*p.x + p.y*p.y <=1)return true;
	else return false;
}

void printPixel(color c, ofstream &fout){
	fout<< c.r <<" ";
	fout<< c.g <<" ";
	fout<< c.b <<" ";
	fout<<endl;
}

int mandelbrotIters(Complex c){
	int i=0;
	Complex z;
	z=c;
	while((z.real*z.real+z.imag*z.imag<50.0) && i<MAXITERS){
		z=MultiplyComplex(z,z);
		z=AddComplex(z,c);
		++i;
	}

	return i;
}

int main(){
	ofstream fout;
	Complex c1, c2;
	c1.real=C1R;
	c1.imag=C1I;
	c2.real=C2R;
	c2.imag=C2I;
	color pc;
	Complex c;
	int index;

	//print top matter
	fout.open("mandel.ppm");
	fout<<"P3 ";
	fout<<COLS<<" ";
	fout<<ROWS<<" ";
	fout<<"255 ";
	fout<< endl;

	//for each pixel i,j
	for(int i=0;i<ROWS;++i){
		for(int j=0;j<COLS;++j){
			//get Complex for that row and col
			c=getComplex(i,j,c1,c2);

			//get the index for that point
			//index = distFromOrigSq(c);
			index = mandelbrotIters(c);


			//get color for that index
			pc=getColor(index);

			//output the pixel color
			printPixel(pc, fout);

		}
	}


	fout.close();
	return 0;

}
