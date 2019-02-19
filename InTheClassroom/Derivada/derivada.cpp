/**
 * @file	derivada.cpp
 * @brief	Descreve a aproximação que é feita do x0 = 1 até 0 da função x*cos(x)
 * @author 	Samuel Lucas de Moura Ferino
 * @since	14.04.2019
 */ 
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double function( double h){
	return h*cos(h);
}

int main(){
	
	double x = 1; //! Será o valor inicial 

	for( double h= 1; h>0; h = h -0.01){
		cout << (  ( function(x + h) - function(x) ) / h ) << endl;
	}
	
	return 0;
}
