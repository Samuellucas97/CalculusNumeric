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
	double ponto_Medio = 0; //-> Contém o valor do ponto médio atual.
	
	numero_IteracaoAtual += 1;

	while( numero_IteracaoAtual <= numero_IteracaoMaxima ){

		cout << "48/- ponto medio = " << ponto_Medio 
			 << " / ponto medio anterior =  " << ponto_Medio_anterior << endl;

		ponto_Medio = f(ponto_Medio_anterior);
		
		cout << "53/- ponto medio = " << ponto_Medio 
			 << " / ponto medio anterior =  " << ponto_Medio_anterior << endl;

		if( fabs(ponto_Medio - ponto_Medio_anterior) < erroTolerancia )	/// Condição de parada alcançado, raiz encontrada ou intervalo pequeno demais
			return make_tuple(ponto_Medio, true);

		numero_IteracaoAtual += 1;

		ponto_Medio_anterior = ponto_Medio; 
		
		cout << "63/- ponto medio = " << ponto_Medio 
			 << " / ponto medio anterior =  " << ponto_Medio_anterior << endl;

	}

	return make_tuple(ponto_Medio,false);
}

int main(){
	
	cout << "As tres raizes sao: "; 
	
	if( get<1>( metodoPontoFixo(3, 0.01, 10) ) == true )	/// PRIMEIRA RAIZ: 4.8
		cout << " " << get<0>( metodoPontoFixo(3, 0.1, 10) ) << endl;
	// if( get<1>( metodoPontoFixo(-10, 0.001, 30) ) == true )	/// SEGUNDA RAIZ: -2,1
	// 	cout << " " << get<0>( metodoPontoFixo(-10, 0.001, 30) ) << endl;
	// if( get<1>( metodoPontoFixo(-1.5, 0.0000001, 30) ) == true )  /// TERCEIRA RAIZ: -1
	// 	cout << " " << get<0>( metodoPontoFixo(-1.5, 0.0000001, 30) ) << endl;
	else
		cout << "Nao foi encontrado raiz..." << endl;

	return 0;
}
