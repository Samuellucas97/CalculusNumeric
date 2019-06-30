__author__ = 'Samuel Lucas de Moura Ferino'
__email__ = 'samuellucas97@ufrn.edu.br'

import pandas as pd

if __name__ == '__main__': 
    dataPesos = pd.read_csv('pesos.txt', sep=" ", header=None)
    
    ## 1. Calculando-se quantidade de pesos
    print( 'n = ', len(dataPesos))

    ## 2. Somando-se as variáveis 'x' usadas
    print('somatorio de x = ', dataPesos[0].sum() )
    
    ## 3. Somando-se as variáveis 'y' usadas    
    print('somatorio de y = ', dataPesos[1].sum() )

    ## 4. Somando-se os 'x^2' usados  
    x_2 = 0
    for i in range(len(dataPesos[0])):
        x_2 += dataPesos[0][i]*dataPesos[0][i] 
    print('somatorio de x^2 =', x_2)

    ## 5. Somando-se os 'x*y' usados
    xy = 0
    for i in range(len(dataPesos[0])):
        xy += dataPesos[0][i]*dataPesos[1][i] 
    print('somatorio de xy =', xy)
    