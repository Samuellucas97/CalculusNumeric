set terminal png size 900, 600 enhanced
set output 'exercicio2.png'
set grid
set xzeroaxis
set yzeroaxis
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
plot [-6:6] 'arquivos.pts' title 'aproximação de x*cos(x) + 1'with lp lc 2 lw 2,\
 x*cos(x)+1 lc 5 lw 3 
