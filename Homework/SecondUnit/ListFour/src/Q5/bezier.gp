set terminal png size 900, 600 enhanced
set output 'bezier.png'
set encoding utf8
set grid
set xlabel "Coordenada X"
set ylabel "Coordenada Y"
set key below
set xzeroaxis
set yzeroaxis
set parametric 
plot ((1-t)**3)*(-1) + 3*t*(t-1)**2 + 3*(t**2)*(t-1)*2 + t**3,\
((1-t)**3)*(2) + 3*t*(t-1)**5 + 3*(t**2)*(t-1)*5 + (t**3)*2
