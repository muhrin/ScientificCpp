reset
set term x11 noraise
set xrange[0:100]
set yrange[0:100]
plot "fractal_forest.dat" u 1:2:3:4:5 w vectors nohead lc rgb variable
pause 1
reread
