set terminal png size 600, 400 enhanced
set output 'exercicio3.png'
set xzeroaxis
set yzeroaxis
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
f(x)= x*cos(x) 
df1(x) = cos(x) -x*sin(x)  
df2(x) = (-2*sin(x) -x*cos(x))  
df3(x) = (-3*cos(x) +x*sin(x))  
df4(x) = (4*sin(x) +x*cos(x))
df5(x) = (5*cos(x) -x*sin(x) )  
df6(x) = (-6*sin(x) -x*cos(x) )


plot f(0) + (df1(0)*(x-0)**1)/1! + (df2(0)*(x-0)**2)/2! + (df3(0)*(x-0)**3)/3! + (df4(0)*(x-0)**4)/4! + (df5(0)*(x-0)**5)/5!+ (df6(0)*(x-0)**6)/6! title 'serie de taylor', x*cos(x)
