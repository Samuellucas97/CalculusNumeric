/**
 * @file	secante.cpp
 * @brief	Contém a função método interativo da secante
 * @author	Samuel Lucas de Moura Ferino
 * @version	0.0.2
 */ 

/**
 * 					**** TEOREMA DE BOLZANO **** 
 * 
 * 			Sejam f uma função contínua e [a,b] E Domínio(f). Diante disso, temos que:			
 * 		
 * 			f(a) * f(b) < 0  ==>  Existe pelo menos uma raiz nesse intervalo [a,b]
 * 
 * 
 */ 

#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

#include <tuple>
using std::tuple;
using std::make_tuple;
using std::get;

double pontoMedio(double a, double b){
	return a + ((b-a)/2);
}

double f(double x){
	return pow(x,3) - 1.7*pow(x,2) - 12.78*x -10.08;
}

tuple<double,bool> metodoSecante(	double inicioIntervalo, 
						double fimIntervalo, 
						double erroTolerancia, 
						int numero_IteracaoMaxima){

	int numero_IteracaoAtual = 0; //-> Quantidade de iterações realizadas atualmente.
	double ponto_Medio; //-> Contém o valor do ponto médio atual.
	double FA; //-> Contém o valor de f(a) onde 'a' é o ponto inicial do intervalo usado.
	double FB; //-> Contém o valor de f(b) onde 'b' é o ponto final do intervalo usado.
	
	numero_IteracaoAtual += 2;

	FA = f(inicioIntervalo);
    FB = f(fimIntervalo);


	while( numero_IteracaoAtual <= numero_IteracaoMaxima ){

        ponto_Medio = fimIntervalo - ( FB*(fimIntervalo - inicioIntervalo)/(FB - FA) );

		if ( fabs(ponto_Medio - fimIntervalo) < erroTolerancia )
			return make_tuple(ponto_Medio, true);

		numero_IteracaoAtual += 1;

		inicioIntervalo = fimIntervalo;
		FA = FB;
		fimIntervalo = ponto_Medio;
		FB = f( ponto_Medio ); 	

	}

	return make_tuple(ponto_Medio,false);
}

int main(){


	cout << "As tres raizes sao: "; 

	if( get<1>( metodoSecante(-10,10, 0.00001, 15) ) == true )  /// PRIMEIRA RAIZ: 4,8
		cout << " " << get<0>( metodoSecante(2,10, 0.00001, 15) );
	if( get<1>( metodoSecante(-5,-1.7, 0.00001, 10) ) == true )  /// SEGUNDA RAIZ: -2,1
		cout << ", " << get<0>( metodoSecante(-5,-1.7, 0.00001, 10) );
	if( get<1>( metodoSecante(-1.5,1, 0.00001, 9) ) == true )  /// TERCEIRA RAIZ: -1
		cout << " e " << get<0>( metodoSecante(-1.5,1, 0.00001, 9) ) << endl;
	else
		cout << "Nao foi encontrado raiz..." << endl;

	return 0;
}
