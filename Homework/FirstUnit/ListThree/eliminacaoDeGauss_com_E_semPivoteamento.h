/**
 * @file	eliminacaoDeGauss_com_E_semPivotemento.h
 * @brief	Biblioteca com a implementação dos métodos diretos
 *          de eliminação de Gauss com e sem pivoteamento parcial
 * @author 	Samuel Lucas de Moura Ferino
 * @version	0.0.9
 */

#ifndef ELIMINACAODEGAUSS_COM_E_SEMPIVOTEAMENTO_H
#define ELIMINACAODEGAUSS_COM_E_SEMPIVOTEAMENTO_H

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <cmath>

#include <vector>
using std::vector;

void imprimirVetorDeVetores(vector< vector<double> >&  matrizAumentada_A_b ){

    for(auto& n: matrizAumentada_A_b){ /// IMPRIMINDO MATRIZ AUMENTADA (A | b)
        for(auto& j: n){
            cout << j << " ";
        }
        cout << endl;
    }

}    

void eliminacaoDeGauss( vector< vector<double> >& matrizAumentada_A_b ){

    double multiplicador_m_ij;
    int quantidadeDeLinhas_matrizAumentada_A_b = (int) matrizAumentada_A_b.size();

    for( int coluna = 0; coluna < quantidadeDeLinhas_matrizAumentada_A_b - 1; ++coluna){

        for( int linha = coluna + 1; linha < quantidadeDeLinhas_matrizAumentada_A_b; ++linha){
            
            multiplicador_m_ij = matrizAumentada_A_b.at(linha).at(coluna) / matrizAumentada_A_b.at(coluna).at(coluna);                
            matrizAumentada_A_b.at(linha).at(coluna) = 0;

            for( int colunaVetor = coluna + 1; colunaVetor < quantidadeDeLinhas_matrizAumentada_A_b; ++colunaVetor){

                matrizAumentada_A_b.at(linha).at(colunaVetor) = 
                matrizAumentada_A_b.at(linha).at(colunaVetor) - multiplicador_m_ij * matrizAumentada_A_b.at(coluna).at(colunaVetor) ;

            }

            matrizAumentada_A_b.at(linha).at(quantidadeDeLinhas_matrizAumentada_A_b) = 
            matrizAumentada_A_b.at(linha).at(quantidadeDeLinhas_matrizAumentada_A_b) - multiplicador_m_ij * 
            matrizAumentada_A_b.at(coluna).at(quantidadeDeLinhas_matrizAumentada_A_b) ;

        }

    }

}


void 
eliminacaoDeGauss_comPivoteamentoParcial( vector< vector<double> > &matrizAumentada_A_b ){
    
    double multiplicador_m_ij;
    double pivoAtual;
    int linha_pivoAtual;
    int quantidadeDeLinhas_matrizAumentada_A_b = (int) matrizAumentada_A_b.size();

    for( int coluna = 0; coluna < quantidadeDeLinhas_matrizAumentada_A_b - 1; ++coluna){

        pivoAtual = matrizAumentada_A_b.at(coluna).at(coluna);
        linha_pivoAtual = coluna;

        for( int linha = coluna + 1; linha < quantidadeDeLinhas_matrizAumentada_A_b; ++linha){
            if ( fabs(matrizAumentada_A_b.at(linha).at(coluna) ) > fabs(pivoAtual) ){
                pivoAtual = matrizAumentada_A_b.at(linha).at(coluna);
                linha_pivoAtual = linha;
            }
        }
        
        if( pivoAtual == 0 ){
            cerr << "Trata-se de uma matriz singular (det(A) = 0)"
                 << endl;

            exit(1);
        }

        if( linha_pivoAtual != coluna )
            matrizAumentada_A_b.at(linha_pivoAtual).swap( matrizAumentada_A_b.at(coluna) );
    
        for( int linha = coluna + 1; linha < quantidadeDeLinhas_matrizAumentada_A_b; ++linha){
            
            multiplicador_m_ij = matrizAumentada_A_b.at(linha).at(coluna) / matrizAumentada_A_b.at(coluna).at(coluna);                
            matrizAumentada_A_b.at(linha).at(coluna) = 0;

            for( int colunaVetor = coluna + 1; colunaVetor < quantidadeDeLinhas_matrizAumentada_A_b; ++colunaVetor){

                matrizAumentada_A_b.at(linha).at(colunaVetor) = 
                matrizAumentada_A_b.at(linha).at(colunaVetor) 
                - multiplicador_m_ij * matrizAumentada_A_b.at(coluna).at(colunaVetor);

            }

            matrizAumentada_A_b.at(linha).at(quantidadeDeLinhas_matrizAumentada_A_b) = 
            matrizAumentada_A_b.at(linha).at(quantidadeDeLinhas_matrizAumentada_A_b) - multiplicador_m_ij * 
            matrizAumentada_A_b.at(coluna).at(quantidadeDeLinhas_matrizAumentada_A_b) ;

        }
    }

}

vector<double>&
resolverSistemaLinearTriangularSuperior( vector< vector<double> >& matrizAumentada_A_b ){
    
    double somatorio;
    int quantidadeDeLinhas_matrizAumentada_A_b = (int) matrizAumentada_A_b.size();
    double vetorSolucao[quantidadeDeLinhas_matrizAumentada_A_b];
    vector<double> vetorSolucaoAproximada;

    vetorSolucao[ quantidadeDeLinhas_matrizAumentada_A_b - 1 ] = (
        matrizAumentada_A_b.at(quantidadeDeLinhas_matrizAumentada_A_b).at(quantidadeDeLinhas_matrizAumentada_A_b+1) 
                            / 
        matrizAumentada_A_b.at(quantidadeDeLinhas_matrizAumentada_A_b).at(quantidadeDeLinhas_matrizAumentada_A_b)
                          ) ;
    
    for(int linha = quantidadeDeLinhas_matrizAumentada_A_b - 1;linha > 0;--linha){
        
        somatorio = 0;

        for(int coluna = linha + 1; coluna < quantidadeDeLinhas_matrizAumentada_A_b ; --coluna){
            somatorio = somatorio + matrizAumentada_A_b.at(linha).at(coluna) * vetorSolucao[coluna];       
        }

        vetorSolucao[linha] =(
        (  matrizAumentada_A_b.at(quantidadeDeLinhas_matrizAumentada_A_b).at(quantidadeDeLinhas_matrizAumentada_A_b+1) - somatorio )
                                / 
            matrizAumentada_A_b.at(quantidadeDeLinhas_matrizAumentada_A_b).at(quantidadeDeLinhas_matrizAumentada_A_b)
                            ) ;
    }

    for(int i = quantidadeDeLinhas_matrizAumentada_A_b; i > 0; --i)
        vetorSolucaoAproximada.push_back(vetorSolucao[i]);

    return vetorSolucaoAproximada;
}  

#endif