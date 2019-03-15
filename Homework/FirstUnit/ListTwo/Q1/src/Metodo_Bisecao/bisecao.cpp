/**
 * @file	bisecao.cpp
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

#include <tuple>
using std::tuple;
using std::make_tuple;
using std::get;

/**
 * @brief	Ponto médio do intervalo do valor a até o valor b
 * @param	a	Valor que delimita o início do intervalo
 * @param	b	Valor que delimita o fim do intervalo
 */ 
double pontoMedio(double a, double b){
	return a + ((b-a)/2);
}

/**
 * @brief	Função genérica
 * @param	x	Entrada da função
 */ 
double f(double x){
	return pow(x,3) - 1.7*pow(x,2) - 12.78*x -10.08;
}

/**
 * @brief	Método iterativo da biseção
 * @param	inicioIntervalo	Valor que delimita o inicício do intervalo
 * @param	fimIntervalo	Valor que delimita o fim do intervalo
 * @param	erroTolerancia	Tolerância de erro
 * @param	numero_IteracaoMaxima	Quantidade máxima de iterações
 * @return	Uma tupla contendo o valor da raiz e o valor verdade que indica
 * 			se o método terminou com sucesso caso seja true e false caso
 * 			contrário 
 */ 
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

	cout << "As tres raizes sao: "; 

	if( get<1>( metodoBisecao(-10,10, 0.0000001, 28) ) == true )  /// PRIMEIRA RAIZ: 4,8
		cout << " " << get<0>( metodoBisecao(-10,10, 0.0000001, 28) );
	if( get<1>( metodoBisecao(-10,1, 0.0000001, 28) ) == true )  /// SEGUNDA RAIZ: -2,1
		cout << ", " << get<0>( metodoBisecao(-10,1, 0.0000001, 28) );
	if( get<1>( metodoBisecao(-1.5,1, 0.0000001, 28) ) == true )  /// TERCEIRA RAIZ: -1
		cout << " e " << get<0>( metodoBisecao(-1.5,1, 0.0000001, 28) ) << endl;
	else
		cout << "Nao foi encontrado raiz..." << endl;

	return 0;
}
