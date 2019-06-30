set terminal png size 900, 600 enhanced
set output 'interpolacaoGeometrica.png'
set encoding utf8
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
set xzeroaxis
set yzeroaxis
plot  title "interpolacao de Newton",\
'dados.pts' lw 8 title "Pontos dados",\
x lw 3 lc 4 title "interpolacao linear",\
x>=2 && x<=4 ?( 3 + (-2)*(x-2)):1/0 lw 3 lc 4  title "interpolacao linear",\
x>= 4 && x<=7 ? (-1 + (5.0/3.0)*(x-4)):1/0 lw 3 lc 4  title "interpolacao linear" 