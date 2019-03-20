/**
 * @file	newtonRaphson.cpp
 * @brief	Contém as funções que implementam o método interativo de Newton Raphson
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

double derivada_f( double x){
	return 3*pow(x,2) - 3.4*x - 12.78;
}

tuple<double,bool> metodoNewtonRaphson(	double ponto_Medio_anterior, 
                                        double erroTolerancia,
						                int numero_IteracaoMaxima){

	int numero_IteracaoAtual = 0; //-> Quantidade de iterações realizadas atualmente.
	double ponto_Medio; //-> Contém o valor do ponto médio atual.
	
	numero_IteracaoAtual += 1;

	while( numero_IteracaoAtual <= numero_IteracaoMaxima ){

		ponto_Medio = ponto_Medio_anterior - f(ponto_Medio_anterior)/derivada_f(ponto_Medio_anterior);

		if( fabs(ponto_Medio_anterior - ponto_Medio) < erroTolerancia )	/// Condição de parada alcançado, raiz encontrada ou intervalo pequeno demais
			return make_tuple(ponto_Medio, true);

		numero_IteracaoAtual += 1;

		ponto_Medio_anterior = ponto_Medio; 

	}

	return make_tuple(ponto_Medio,false);
}

int main(){

	cout << "As tres raizes sao: "; 

	if( get<1>( metodoNewtonRaphson(4, 0.001, 30) ) == true ) /// PRIMEIRA RAIZ: 4,8
		cout << " " << get<0>( metodoNewtonRaphson(4, 0.001, 30) ) << endl;
	if( get<1>( metodoNewtonRaphson(-2, 0.001, 30) ) == true ) /// SEGUNDA RAIZ:  -2,1
		cout << ", " << get<0>( metodoNewtonRaphson(-2, 0.001, 30) ) << endl;
	if( get<1>( metodoNewtonRaphson(-0.5, 0.001, 30) ) == true ) /// TERCEIRA RAIZ:  -1
		cout << " e " << get<0>( metodoNewtonRaphson(-0.5, 0.001, 30) ) << endl;
	else
		cout << "Nao foi encontrado raiz..." << endl;

	return 0;
}
