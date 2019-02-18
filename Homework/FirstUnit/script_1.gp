set terminal png font 'Helvetica,12', size 600, 400 enhanced
set output 'exercicio1.png'
set title "Exercicio 1"
set encoding utf8
f(x) = x*x*x - 2*x*x - x +2
df(x) = 3*x*x - 4*x -1
set xrange[-1.5:2.5]
g(x) = f(1) - df(1)*(x-1)
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
set xzeroaxis
set yzeroaxis
plot f(x) title 'funcao cubica', g(x) title 'reta tangente em x=1'