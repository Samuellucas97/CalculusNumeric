/**
 * @file	linearizando.cpp
 * @brief	Linearizando o gráfico da função x*cos(x) + 1 e salva os pontos em um arquivo
 * @author 	Samuel Lucas de Moura Ferino
 * @version	0.0.9
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <fstream>
using std::ofstream;

#include <string>
using std::to_string;
using std::string;

#include <cmath>

/**
 * @brief	Calcula a derivada de um ponto
 * @param	x_anterior	Valor do 'x' anterior
 * @return	Derivada no ponto x anterior
 */  
double derivada_f(double x_anterior){
	return cos(x_anterior) - x_anterior*sin(x_anterior);
}

/**
 * @brief	Calcula o valor da equção da reta tangente no x
 * @param	x_anterior	'x' usado na iteração passada
 * @param	x_atual		'x' usado na iteração atual
 * @param	imagem_x_anterior	Imagem do 'x' anterior
 * @return	Valor da equação da reta tangente da f no x 
 */ 
double eq_reta_tangente_no_x_ATUAL( double x_anterior, double x_atual, double imagem_x_anterior){
	return imagem_x_anterior + derivada_f(x_anterior)*(x_atual- x_anterior);
}

int main(){

	double imagem_x_anterior=1; //! f(0) = 1
	double taxaDeVariacao = 0.5; //! Taxa de variação parametrizada 
	string intervaloCrescente;	//! Guardam as valores da tupla dos intervalos crescente
	string intervaloDecrescente; //! Guardam as valores da tupla dos intervalos decrescente

	ofstream arqDados;
	arqDados.open("dados_Q2.pts");

	if(arqDados.is_open() == 0){ /// VERIFICANDO SE O ARQUIVO FOI ABERTO
		cerr << "O arquivo nao foi aberto" << endl;
		exit(1);
	}

	for(double i=taxaDeVariacao; i <= 6; i=i+taxaDeVariacao){	/// INTERVALO CRESCENDO DE 0.5 ATÉ 6
	
		intervaloCrescente += 	to_string(i) 
							+ 	( string(" ") 
							+ 	to_string(eq_reta_tangente_no_x_ATUAL(i-taxaDeVariacao,i, imagem_x_anterior)) ) 
							+ 	"\n";
						
		imagem_x_anterior = eq_reta_tangente_no_x_ATUAL(i-taxaDeVariacao,i, imagem_x_anterior);
	
	}	

	imagem_x_anterior=1; /// Reinicialização de variável

	for(double i=-taxaDeVariacao; i >= -6; i=i-taxaDeVariacao){ /// INTERVALO DECRESCENDO DE -6 A -0.5
	
		intervaloDecrescente = 	to_string(i) 
							+ 	( string(" ") 
							+ 	to_string(eq_reta_tangente_no_x_ATUAL(i+taxaDeVariacao,i, imagem_x_anterior)) ) 
							+ 	"\n"
							+ 	intervaloDecrescente; 
							
		imagem_x_anterior = eq_reta_tangente_no_x_ATUAL(i+taxaDeVariacao,i, imagem_x_anterior);
	
	}	

	arqDados << intervaloDecrescente; 
	arqDados << "0 1" << endl;
	arqDados << intervaloCrescente;

	arqDados.close();

	return 0;
}
