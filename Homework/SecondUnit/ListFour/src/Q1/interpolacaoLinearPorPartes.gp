set terminal png size 900, 600 enhanced
set output 'interpolacaoLinearPorPartes.png'
set encoding utf8
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
set xzeroaxis
set yzeroaxis
plot x>=0 && x<=2 ? (1 +x):1/0,\
x>=2 && x<=4 ?( 3 + (-2)*(x-2)):1/0,\
x>= 4 && x<=7 ? (-1 + (5/3)*(x-4)):1/0,\
'dados.pts' lw 8