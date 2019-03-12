/**
 * @file	pontoFixo.cpp
 * @brief	Contém a função método interativo do ponto fixo
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

tuple<double,bool> metodoPontoFixo(	double ponto_Medio_anterior, 
						double erroTolerancia,
						int numero_IteracaoMaxima){

	int numero_IteracaoAtual = 0; //-> Quantidade de iterações realizadas atualmente.
	double ponto_Medio; //-> Contém o valor do ponto médio atual.
	
	numero_IteracaoAtual += 1;

	while( numero_IteracaoAtual <= numero_IteracaoMaxima ){

		ponto_Medio = f(ponto_Medio_anterior);

		if( fabs(ponto_Medio_anterior - ponto_Medio) < erroTolerancia )	/// Condição de parada alcançado, raiz encontrada ou intervalo pequeno demais
			return make_tuple(ponto_Medio, true);

		numero_IteracaoAtual += 1;

		ponto_Medio_anterior = ponto_Medio; 

	}

	return make_tuple(ponto_Medio,false);
}

int main(){

	if( get<1>( metodoPontoFixo(-1,1, 0.00001, 10) ) == true )
		cout << "A raiz eh " << get<0>( metodoPontoFixo(-100,100, 0.00001, 10) ) << endl;

	return 0;
}
