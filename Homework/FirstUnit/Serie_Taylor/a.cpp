#include <iostream>

#include <fstream>
using std::ofstream;

#include <string>
using std::string;
using std::to_string;

#include <cmath>


int fatorial( int x){
	if( x == 0) 
		return 1;
	else
		return fatorial(x-1)*x;
}

double df1(double  x){
	return cos(x) -x*sin(x);
}

double df2(double x){
	return -2*sin(x) -x*cos(x) ;
}

double df3(double x){
	return -3*cos(x) +x*sin(x);
}

double df4(double x){
	return 4*sin(x) +x*cos(x);
}

double df5(double x){
	return 5*cos(x) -x*sin(x);
}

double df6(double x){
	return -6*sin(x) -x*cos(x);
}

double serie_taylor(double a){
	return f(a) + 
		(df1(a)*(x-a)**1)/fatorial(1) + 
		(df2(a)*(x-a)**2)/fatorial(2) + 
		(df3(a)*(x-a)**3)/fatorial(3) + 
		(df4(a)*(x-a)**4)/fatorial(4) + 
		(df5(a)*(x-a)**5)/fatorial(5) + 
		(df6(a)*(x-a)**6)/fatorial(6) ;
}

int main(){
	double a0 = 0;
	ofstream arqDados = 

}
