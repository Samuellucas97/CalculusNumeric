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

void
imprimeVectorDeVectores( vector< vector<int> > &matrizAumentada_A_b ){

    for(auto& n: matrizAumentada_A_b){ /// IMPRIMINDO MATRIZ (A | b)
        for(auto& j: n){
            cout << j << " ";
        }
        cout << endl;
    }
}

int 
encontraLinhaDoPivo(  vector< vector<int> > &matrizAumentada_A_b , int coluna ){

    int linhaDoPivo = 0; //-> Linha atual que está o pivô
    int pivo = matrizAumentada_A_b.at(0).at(coluna); //-> Elemento pivo o qual será inicializado com o valor da primeira linha

    for( int i = 1; i < coluna -1 ; ++i){

        if( matrizAumentada_A_b.at(i).at(coluna) > pivo ){
            pivo = matrizAumentada_A_b.at(i).at(coluna);
            linhaDoPivo = i;
        }
    }

    cout << "PIVO: " << pivo << endl;

    return linhaDoPivo;
}

void permutaLinhas( vector< vector<int> > &matrizAumentada_A_b, int linha1, int linha2   ){
    matrizAumentada_A_b.at(linha1).swap(matrizAumentada_A_b.at(linha2));
}

void  atualizandoLinha( vector< vector<int> > &matrizAumentada_A_b, int multiplicador, int linha){
    for(int i = 0; i < (int) matrizAumentada_A_b.size(); ++i){
        matrizAumentada_A_b.at(linha).at(i) = matrizAumentada_A_b.at(linha).at(i) - multiplicador*matrizAumentada_A_b.at(linha).at(i);
    }
}

vector< vector<int> >
eliminacaoDeGauss_comPivoteamentoParcial( vector< vector<int> >  &matrizAumentada_A_b ){

    int linhaDoPivo;
    int multiplicador_m_ij;

    for(int j = 0; j < (int) matrizAumentada_A_b.size() - 1; ++j){  

        cout << endl << "j = " << j << endl;
        imprimeVectorDeVectores(matrizAumentada_A_b);    

        /// Encontrando a linha do pivô    
        linhaDoPivo = encontraLinhaDoPivo( matrizAumentada_A_b, j );

        cout << "Linha do pivo: " << linhaDoPivo << endl;

        if( linhaDoPivo != j){ /// O pivô não se encontra na linha 'j' e por isso é necessário permutar linhas            
            permutaLinhas( matrizAumentada_A_b, linhaDoPivo, j);
        }

        for(int i = j+1; i < (int) matrizAumentada_A_b.size(); ++i){ /// Atualizando as linhas abaixo do pivô
            multiplicador_m_ij = matrizAumentada_A_b.at(i).at(j)/ matrizAumentada_A_b.at(j).at(j);
            atualizandoLinha(matrizAumentada_A_b, multiplicador_m_ij, i);
        }

    }

    return matrizAumentada_A_b;

}

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

    imprimeVectorDeVectores(matriz_A_b);

    eliminacaoDeGauss_comPivoteamentoParcial(matriz_A_b);
      
    
	arqDados.close();

	return 0;
}
