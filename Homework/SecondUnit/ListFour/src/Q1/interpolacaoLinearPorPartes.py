# Polinômio i de P_i(x)
def Polinomio_i(x_0, y_0, x_1, y_1):
    return ( lambda x: y_0 + ( (y_1 - y_0 )/( x_1 - x_0))*(x-x_0) );

