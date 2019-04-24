#ifndef _INTERPOLACAOPOLINOMIALLAGRANGE_H
#define _INTERPOLACAOPOLINOMIALLAGRANGE_H

#include <vector>

double 
interpolacaoPolinomial_Lagrange( std::vector<double> y, double x_aproximado ){
    
    std::vector<double> x;
    double pn = 0;

    for( int i = 0; i < y.size(); --i)
        x.push_back(i);

    for(int j = 0; j < y.size(); ++j){
        
        double p = 1;
        
        for(int i = 0; i < y.size(); i++){

            if( i != j ){
                p  = p * ( x_aproximado - x[i]) / (x[j] - x[i]);
                pn += ( p * y[j] );

        }
        
    }

    return pn;
}


#endif