from scipy.integrate import quad
from numpy import sin

def compositeTrapezoidMethod( function_f, a,  b, numberOfIntervals = 6):
    """
    Numerical integration using the composite trapezoid Rule.

    integral = compositeTrapezoidMethod(function_f, a, b, numberOfIntervals = 6)

    INPUT:
      * function_f: function to be integrated
      * a: beginning of integration interval
      * b: end of integration interval
      * numberOfIntervals: number of interval divisions

    return: \int_{a}^{b} f(x)

    Author: Samuel Lucas
    
    April 2019
    """
    h = (b - a) / numberOfIntervals 
    return (h/2)*( function_f(a) + sum([ 2*function_f(a + i*h) for i in range(1, numberOfIntervals) ]) + function_f(b) )

# ## Método 1/3 de Simpson

# In[40]:

def methodSimpson1_3(function_f, a, b, numberOfIntervals = 3):
    """
    Numerical integration using the Simpson 1/3 Rule.

    integral = methodSimpson1_3(function_f, a, b, numberOfIntervals = 3)

    INPUT:
      * function_f: function to be integrated
      * a: beginning of integration interval
      * b: end of integration interval
      * numberOfIntervals: number of interval divisions

    return: \int_{a}^{b} f(x)

    Author: Samuel Lucas
    
    April 2019
    """
    h = (b - a) / (2*numberOfIntervals)
    return (h/3)*( function_f(a) + sum([ 2*function_f(a + (i*h)) if i%2 == 0 else 4*function_f(a + (i*h)) for i in range(1, numberOfIntervals*2) ]) + function_f(b) )

# ## Método 3/8 de Simpson

# In[70]:

def methodSimpson3_8(function_f, a, b, numberOfIntervals = 2):
    """
    Numerical integration using the Simpson 3/8 Rule.

    integral = methodSimpson3_8(function_f, a, b, numberOfIntervals = 2)

    INPUT:
      * function_f: function to be integrated
      * a: beginning of integration interval
      * b: end of integration interval
      * numberOfIntervals: number of interval divisions

    return: \int_{a}^{b} f(x) dx

    Author: Samuel Lucas
    
    May 2019
    """
    h = (b - a)  / (3*numberOfIntervals)
    return ((3*h)/8)*( function_f(a) + sum([ 2*function_f(a + i*h) if i%3 == 0 else 3*function_f(a + i*h) for i in range(1, 3*numberOfIntervals - 1 ) ]) + function_f(b) )


print( "Calculando-se analiticamente, temos que: " + str( quad( lambda x: x*sin(x), -5, 5 )[0] ) )

for i in range(1,7):
    print( "Aproximação obtida para i = " + str(i) + ": "+ str(compositeTrapezoidMethod( lambda x: x*sin(x), -5, 5, i*6 ) )  + ": "+ str(methodSimpson1_3( lambda x: x*sin(x), -5, 5, i*3 ) ) + ": "+ str(methodSimpson3_8( lambda x: x*sin(x), -5, 5, i*2 ) ) + "\n" )

