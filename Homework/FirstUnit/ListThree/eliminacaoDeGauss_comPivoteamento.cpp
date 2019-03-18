/**
 * @file	eliminacaoDeGauss_comPivoteamento.cpp
 * @brief	Contém o método de eliminação de Gauss com pivoteamento
 * @author 	Samuel Lucas de Moura Ferino
 * @version	0.0.1
 */

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <cstdlib>

#include <fstream>
using std::ifstream;

#include <string>
using std::string;
using std::stoi;

#include <vector>
using std::vector;

int main(int argc, char* argv[] ){

    vector< vector<int> > matriz_A_b;
    vector<int> linha_de_matriz_A_b;

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
    
    for( int i = 0; i < stoi(tamanhoMatriz_string); ++i){

        for(int j = 0; j < stoi(tamanhoMatriz_string) + 1; ++j){    
          arqDados >> conteudoDoArquivo;
          linha_de_matriz_A_b.push_back( stoi(conteudoDoArquivo) );  

        }    

        matriz_A_b.push_back( linha_de_matriz_A_b);
        linha_de_matriz_A_b.clear();

    }  

    for(auto& n: matriz_A_b){ /// IMPRIMINDO MATRIZ (A | b)
        for(auto& j: n){
            cout << j << " ";
        }
        cout << endl;
    }


	arqDados.close();

	return 0;
}
