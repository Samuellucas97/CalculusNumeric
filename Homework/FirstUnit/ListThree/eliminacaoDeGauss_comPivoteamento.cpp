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

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

int main(int argc, char* argv[] ){

    string nomeDoArquivo;
    string tamanhoMatriz_string;
    string conteudoDoArquivo;
    int tamanhoMatriz;

    if( argc != 2 || ( atoi(argv[1]) != 1 && atoi(argv[1]) != 2 && atoi(argv[1]) != 3 ) ){
        cerr << "Voce so pode adicionar junto ao ./exe os seguintes argumento: 1, 2 ou 3..." << endl;
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
	arqDados.open(nomeDoArquivo);

	if(arqDados.is_open() == 0){ /// VERIFICANDO SE O ARQUIVO FOI ABERTO
		cerr << "O arquivo nao foi aberto" << endl;
		exit(1);
	}

    arqDados >> tamanhoMatriz_string;

    int A[tamanhoMatriz][tamanhoMatriz + 1];

    arqDados >> conteudoDoArquivo;

	arqDados.close();

	return 0;
}
