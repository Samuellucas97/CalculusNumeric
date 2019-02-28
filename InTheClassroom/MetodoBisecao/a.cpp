#include <iostream>
#include <cmath>

double pontoMedio(double a, double b){
	return a + ((b-a)/2);
}

double f(double x){
	return x;  /// Aqui deve ficar a função
}

bool verificaCriterioDeParada(	double pMedio, 
								double erro, 
								double pMedioAnterior, 
								int numeroIteracoesAtual
								int numeroIteracaoMaxima){
					
	if( abs(pMedio) < erro )
		return true;
	if( abs( pMedio - pMedioAnterior) < erro )
		return true;
	if( ( abs( pMedio - pMedioAnterior)/ abs(pMedio) ) < erro )
		return true; 
	if( numeroIteracoesAtual > numeroIteracaoMaxima )
		return true;
	
	return false;
}

double metodoBisecao(double pInicial){

	while( verificaCriterioDeParada() != true )
	{
		
	}	
	return pInicial;

}

int main(){

	return 0;
}
