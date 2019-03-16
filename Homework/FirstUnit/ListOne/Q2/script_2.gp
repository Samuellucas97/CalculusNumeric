set terminal png size 600, 400 enhanced
set output 'exercicio2.png'
set title "Exercicio 2"
set grid
set xrange[-6:6]
set xzeroaxis
set yzeroaxis
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
plot 'dados_Q2.pts' with lp, x*cos(x)+1
