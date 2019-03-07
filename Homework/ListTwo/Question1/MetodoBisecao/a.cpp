/**
 * @file	a.cpp
 * @brief	Contém a função método interativo de biseção
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
using std::exp;

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

tuple<double,bool> metodoBisecao(	double inicioIntervalo, 
						double fimIntervalo, 
						double erroTolerancia, 
						int numero_IteracaoMaxima){

	int numero_IteracaoAtual = 0; //-> Quantidade de iterações realizadas atualmente.
	double ponto_Medio; //-> Contém o valor do ponto médio atual.
	double FA; //-> Contém o valor de f(a) onde 'a' é o ponto inicial do intervalo usado.
	double FP; //-> Contém o valor de f(p) onde 'p' é o ponto médio.

	numero_IteracaoAtual += 1;
	FA = f(inicioIntervalo);

	while( numero_IteracaoAtual <= numero_IteracaoMaxima ){

		ponto_Medio = pontoMedio(inicioIntervalo, fimIntervalo);
		FP = f(ponto_Medio);

		if( FP == 0 || ((fimIntervalo - inicioIntervalo)/2) < erroTolerancia )	/// Condição de parada alcançado, raiz encontrada ou intervalo pequeno demais
			return make_tuple(ponto_Medio, true);

		numero_IteracaoAtual += 1;

		if( (FA * FP) > 0 ){ 	/// Já que é positivo é resultado, então a raiz estará no intervalo [p,b]	
			inicioIntervalo = ponto_Medio;
			FA = FP;	
		}
		else{	/// Já que é negativo o resultado, então a raiz da função estará no intervalo [a,p] 
			fimIntervalo = ponto_Medio;
		}

	}

	return make_tuple(ponto_Medio,false);
}

int main(){

	//if( get<1>( metodoBisecao(-1,1, 0.00001, 10) ) == true )
		cout << "A raiz eh " << fabs( get<0>( metodoBisecao(-100,100, 0.00001, 10) ) )<< endl;

	return 0;
}
