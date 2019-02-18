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


double derivada_f(double x_anterior){
	return cos(x_anterior) - x_anterior*sin(x_anterior);
}

double eq_reta_tangente_no_x_ATUAL( double x_anterior, double x_atual, double imagem_x_anterior){
	return imagem_x_anterior + derivada_f(x_anterior)*(x_atual- x_anterior);
}


int main(){

	double imagem_x_anterior=1; //! f(0) =1
	double taxaDeVariacao = 0.5; //! Taxa de variação parametrizada 

	ofstream arqDados;
	arqDados.open("dados.pts");

	if(arqDados.is_open() == 0){ /// VERIFICANDO SE O ARQUIVO FOI ABERTO
		cerr << "O arquivo nao foi aberto" << endl;
		exit(1);
	}

	arqDados << "0 1" << endl;
//	cout << "0 1" << endl;  /// CASO BASE


	for(double i=taxaDeVariacao; i <= 6; i=i+taxaDeVariacao){	/// CRESCENDO ATÉ 6
	
//		cout << to_string(i); 
//		cout << string(" ") + to_string(eq_reta_tangente_no_x_ATUAL(i-taxaDeVariacao,i, imagem_x_anterior)) << endl;  

		arqDados << to_string(i) + ( string(" ") + to_string(eq_reta_tangente_no_x_ATUAL(i-taxaDeVariacao,i, imagem_x_anterior)) ) << endl;  
		imagem_x_anterior = eq_reta_tangente_no_x_ATUAL(i-taxaDeVariacao,i, imagem_x_anterior);
	}

	imagem_x_anterior=1;
//	cout << endl << endl;


	for(double i=-taxaDeVariacao; i >= -6; i=i-taxaDeVariacao){ /// DECRESCENDO ATÉ -6
	
//		cout << to_string(i); 
//		cout << string(" ") + to_string(eq_reta_tangente_no_x_ATUAL(i+taxaDeVariacao,i, imagem_x_anterior)) << endl;  

		arqDados << to_string(i) + ( string(" ") + to_string(eq_reta_tangente_no_x_ATUAL(i+taxaDeVariacao,i, imagem_x_anterior)) ) << endl;  
		imagem_x_anterior = eq_reta_tangente_no_x_ATUAL(i+taxaDeVariacao,i, imagem_x_anterior);
	}	


	arqDados.close();

	return 0;
}
