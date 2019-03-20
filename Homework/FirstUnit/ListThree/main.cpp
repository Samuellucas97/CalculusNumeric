/**
 * @file	main.cpp
 * @brief	Contém a leitura de arquivo e os teste feito com as funções da 
 *          biblioteca eliminacaoDeGaus_com_E_semPivoteamento
 * @author 	Samuel Lucas de Moura Ferino
 * @version	0.0.9
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

#include <cstdlib>

#include <fstream>
using std::ifstream;

#include <string>
using std::string;
using std::stod;

#include <vector>
using std::vector;

#include "eliminacaoDeGauss_com_E_semPivoteamento.h"

int main(int argc, char* argv[] ){

    int sem_Ou_comPivoteamento;
    vector< vector<double> > matriz_A_b;
    vector<double> linha_de_matriz_A_b;

    string nomeDoArquivo;
    string tamanhoMatriz_string;
    string conteudoDoArquivo;

    if( argc != 2 || ( atoi(argv[1]) != 1 && atoi(argv[1]) != 2 && atoi(argv[1]) != 3 ) ){
        cerr << "Voce so pode adicionar junto ao ./exe os seguintes argumento: 1, 2 ou 3..." << endl;
        exit(1);
    }

    switch( atoi(argv[1]) ){
        case 1: nomeDoArquivo = "m1.in";
            break;

        case 2: nomeDoArquivo = "m2.in";
            break;

        case 3: nomeDoArquivo = "m3.in";
            break;        

        default: nomeDoArquivo = "m3.in";
    }
    
	ifstream arqDados;
	arqDados.open(nomeDoArquivo.c_str());

	if(arqDados.is_open() == 0){ /// VERIFICANDO SE O ARQUIVO FOI ABERTO
		cerr << "O arquivo nao foi aberto" << endl;
		exit(1);
	}

    arqDados >> tamanhoMatriz_string;
    
    for( int i = 0; i < stod(tamanhoMatriz_string); ++i){

        for(int j = 0; j < stod(tamanhoMatriz_string) + 1; ++j){    
          arqDados >> conteudoDoArquivo;
          linha_de_matriz_A_b.push_back( stoi(conteudoDoArquivo) );  

        }    

        matriz_A_b.push_back( linha_de_matriz_A_b);
        linha_de_matriz_A_b.clear();

    }  

    cout << "A matriz lida do arquivo eh a seguinte:"
         << endl;

    imprimirVetorDeVetores(matriz_A_b);
    
    cout << endl 
         << "Qual eh o metodo que voce deseja usar: " 
         << endl
         << " Digite 1 caso deseje usar a eliminacao de Gauss sem pivoteamento " 
         << "Ou, digite 2 caso deseje usar a eliminacao de Gaus com pivoteamento"
         << endl
         << endl
         << "Portanto, qual eh a sua escolha? ";
    
    cin >> sem_Ou_comPivoteamento;

    cout << endl
        << endl
        << endl
        << "Voce escolheu o metodo direto da eliminacao de Gauss ";

    if( sem_Ou_comPivoteamento == 1){
        eliminacaoDeGauss(matriz_A_b);

        cout << "SEM pivoteamento parcial. Portanto, a matriz resultante fica assim:"
             << endl;

    }
    else{
        eliminacaoDeGauss_comPivoteamentoParcial(matriz_A_b);

        cout << "COM pivoteamento parcial. Portanto, a matriz resultante fica assim:"
             << endl;

    }

    imprimirVetorDeVetores(matriz_A_b);
    
	arqDados.close();

	return 0;
}