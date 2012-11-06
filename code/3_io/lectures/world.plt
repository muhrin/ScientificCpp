# set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 500, 350 
# set output 'world.1.png'
set yzeroaxis linetype 0 linewidth 1.000
plot 'world.dat' with lines lt 3 , 'world.cor' with points lt 1 pt 2
