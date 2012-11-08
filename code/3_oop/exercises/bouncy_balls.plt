reset
set term x11 noraise
set xrange[0:100]
set yrange[0:100]
plot "bouncy_balls.dat" u 1:2 w l
pause 1
reread
