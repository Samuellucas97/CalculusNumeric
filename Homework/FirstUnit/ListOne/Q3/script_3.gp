set terminal png size 600, 400 enhanced
set output 'exercicio3.png'
set encoding utf8
set xr [-10:10]
set yr [-10:10]
set xzeroaxis
set yzeroaxis
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
plot x - ((x**3)/2) + ((x**5)/24) title 'série de taylor em a=0' lw 3, x*cos(x) lw 3 