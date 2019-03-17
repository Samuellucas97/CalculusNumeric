set terminal png size 600, 400 enhanced
set output 'exercicio3.png'
set xzeroaxis
set yzeroaxis
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
plot x - ((x**3)/2) + ((x**5)/24) - ((7/5040)*(x**7)) + ((9/362880)*(x**9)) - ((11/39916800)*(x**11)) title 'serie de taylor', x*cos(x)
