set terminal png size 600, 400 enhanced
set output 'exercicio1.png'
set encoding utf8
f(x) = x**3 - 2*(x**2) -x + 2
df(x) = 3*(x**2) - 4*x -1
set xrange[-1.5:2.5]
g(x) = f(1) - df(1)*(x-1)
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
set xzeroaxis
set yzeroaxis
plot f(x) title 'funcao cúbica' lw 3, g(x) title 'reta tangente em x=1' lw 3, "< echo '1 0'" with points ls 4 lw 7 lc 5 title "( 1, f(1) )", (2*x) -2