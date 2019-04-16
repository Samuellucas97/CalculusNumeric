def interpolacaoNewton( lista_x, lista_y):
    polinomioInterpoladorNewton = []
    for i in range( len(lista_x) ):
        f_ij = []
        f_ij.append(lista_y[i])
        for j in range( i ):
            f_ij.append( lambda x: x - lista_x[j])
        polinomioInterpoladorNewton.append( f_ij)    
    return polinomioInterpoladorNewton
