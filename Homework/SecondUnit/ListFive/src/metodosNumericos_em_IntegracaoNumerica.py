#!/usr/bin/env python
# coding: utf-8

# # Métodos numéricos em _Integração numérica_
# 
# ### Autor   
# _Samuel Lucas de Moura Ferino_ ( samuellucas97@ufrn.edu.br )  
# IMD/UFRN 2019.   

# ## Introdução
# 
# 
# Tendo em vista que queremos calcular $\int_{-5}^{5}  \! x sen(x) \, dx$ , utilizaremos os seguintes métodos numéricos:  
# * [Método do trapézio](método-do-trapézio) 
# * [Método 1/3 de Simpson](metodo-1/3-de-simpson)
# * [Método 3/8 de Simpson](metodo-3/8-de-simpson)
# 
# *Obs.: O valor resultante do cálculo da respectiva integral definida é $-10cos(5) +2sen(5) \approx -4.75447 $.*

# In[27]:


from scipy.integrate import quad
from numpy import sin

print( "Confirmando que o resultado do cálculo dessa integral é " + str( quad( lambda x: x*sin(x), -5, 5 )[0] ) )


# ## Método do trapézio

# In[44]:


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

print( "Aproximação obtida: "+ str(compositeTrapezoidMethod( lambda x: x*sin(x), -5, 5 ) ) )


# ## Método 1/3 de Simpson

# In[40]:


def methodSimpson1_3(function_f, a, b, numberOfIntervals = 6):
    """
    Numerical integration using the Simpson 1/3 Rule.

    integral = methodSimpson1_3(function_f, a, b, numberOfIntervals = 6)

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
    return (h/3)*( function_f(a) + sum([ 2*function_f(a + i*h) if i%2 == 0 else 4*function_f(a + i*h) for i in range(1, numberOfIntervals) ]) + function_f(b) )

print( "Aproximação obtida: "+ str(methodSimpson1_3( lambda x: x*sin(x), -5, 5 ) ) )


# ## Método 3/8 de Simpson

# In[70]:


def methodSimpson3_8(function_f, a, b, numberOfIntervals = 6):
    h = (b - a) / numberOfIntervals
    return ((3*h)/8)*( function_f(a) + sum([ 2*function_f(a + i*h) if i%3 == 0 else 3*function_f(a + i*h) for i in range(1, numberOfIntervals) ]) + function_f(b) )

print( "Aproximação obtida: "+ str(methodSimpson3_8( lambda x: x*sin(x), -5, 5 ) ) )

