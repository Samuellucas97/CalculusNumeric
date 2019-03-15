/**
 * @file	quedaLivre.cpp
 * @brief	Contém o método iterativo de biseção sendo usado para encontra o ponto em que o objeto
 * 			atinge o solo
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
 * @brief	Calcula o ponto médio do intervalo do valor a até o valor b
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
	return 300 - ( (0.25*32.17) / 0.1)*x 
			   + ( ( pow(0.25,2)*32.17) / pow(0.1,2) )*(1 - pow(M_E, (-1*x)/0.25 ) );
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

	if( get<1>( metodoBisecao(2,10, 0.00001, 100) ) == true )
		cout << "Demorou " << get<0>( metodoBisecao(2,10, 0.00001, 100) ) 
			 << " segundos para atingir ao solo" << endl;
	else
		cout << "Nao foi encontrado raiz..." << endl;


	return 0;
}
