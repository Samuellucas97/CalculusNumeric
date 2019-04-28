/**
* @file	interpolacaoPolinomialLagrange.h
* @brief	Header composto apenas pela funcao que calcula a interpolacao pelo polinomio de lagrange
* @author	Samuel Lucas de Moura Ferino
* @date	27.05.2019
* @version	0.0.6
*/

#ifndef _INTERPOLACAOPOLINOMIAL_H
#define _INTERPOLACAOPOLINOMIAL_H

#include <vector>

/**
* @brief	Implementacao da interpolacao polinomial de lagrange
* @param	y	Vetor de ordenadas
* @param	x_aproximado	Ponto o qual havera o calculo da aproximacao de sua imagem
* @return 	Ordenada aproximada referente ao ponto x dado
*/
interpolacaoLagrange( std::vector<double> &y, double x_aproximado ){

	std::vector<double> x; //-> Vetor de x
	double pn = 0; //-> Polinomio de lagrange

	for( int i = 0; i < (int)y.size(); ++i)
		x.push_back(i);

	for(int i = 0; i < (int)y.size(); ++i){
		double p = 1;
		
		for(int j = 0; j < (int)y.size(); ++j){
			if( i != j ){
				p  = p * (( x_aproximado - x[j]) / (x[i] - x[j]));
			}
		}
		
		pn += ( p * y[i] );
	}

	return pn;
}



#endif
