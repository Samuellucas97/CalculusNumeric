set title "Exercicio 2"
set grid
set xrange[-6:6]
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
plot 'dados.pts' with lp, x*cos(x)+1