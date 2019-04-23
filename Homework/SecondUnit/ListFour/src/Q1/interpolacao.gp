set terminal png size 900, 600 enhanced
set output 'interpolacaoPolinomialDeNewton.png'
set encoding utf8
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
set xzeroaxis
set yzeroaxis
plot  x>=0 && x<=7 ? 1 + x + (3.0/2)*x + (89.0/420)*8*x - (3.0/4)*(x**2) - (89.0/420)*6*(x**2) + (89.0/420)*(x**3) :1/0,\
'dados.pts' lw 8,\
x>=0 && x<=2 ? (1 +x):1/0,\
x>=2 && x<=4 ?( 3 + (-2)*(x-2)):1/0,\
x>= 4 && x<=7 ? (-1 + (5/3)*(x-4)):1/0 