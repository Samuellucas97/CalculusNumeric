#ifndef _INTERPOLACAOPOLINOMIALNEWTON_H
#define _INTERPOLACAOPOLINOMIALNEWTON_H

#include <vector>

double 
interpolacaoPolinomial_Lagrange( std::vector<double> y, double x_aproximado ){
    
    std::vector<double> x;
    double pn = 0;

    for( int i = (y.size() - 1); i >= 0; --i)
        x.push_back(i);

    for(int j = 0; j < y.size(); ++j){
        
        double p = 1;
        
        for(int i = 0; i < y.size(); i++){

            if( i != j ){
                p  = p * ( x_aproximado - x[i]) / (x[j] - x[i]);
                pn += ( p * y[j] );

        }
        
    }

    return 0;
}


#endif