set terminal png size 900, 600 enhanced
set output 'interpolacaoPolinomialDeNewton.png'
set encoding utf8
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
set xzeroaxis
set yzeroaxis
plot  x>=0 && x<=7 ? 1 + x + (-3/4)*((x**2) - 2*x) + (16/21)*((x**2)-2*x)*(x-4):1/0,\
'dados.pts' lw 8