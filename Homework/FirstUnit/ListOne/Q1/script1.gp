set terminal png size 900, 600 enhanced
set output 'exercicio1.png'
set encoding utf8
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
set xzeroaxis
set yzeroaxis
plot [-1.5:2.5] x**3 - 2*(x**2) -x + 2 title 'função cúbica' linestyle 7 with linespoint,\
-2*x + 2 title 'reta tangente em x = 1' lw 3 lc "grey",\
(14*sqrt(7) - 34)/27 + 2 title 'reta tangente em x = (2 - sqrt(7))/3' lw 2 lc "green",\
(-14*sqrt(7) - 34)/27 + 2 title 'reta tangente em x = (2 + sqrt(7))/3' lw 2 lc "magenta",\
'dados_1_0.pts' title '( 1, 0 )' lw 8,\
'dados_pontoCritico_1.pts' title '( (2 - sqrt(7))/3, 14*sqrt(7) - 34)/27 + 2 )' lw 8,\
'dados_pontoCritico_2.pts' title '( (2 + sqrt(7))/3, -14*sqrt(7) - 34)/27 + 2 )' lw 8,\