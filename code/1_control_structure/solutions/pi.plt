reset
set term x11 noraise
set xrange[0:1]
set yrange[0:1]
plot "pi.dat" u 1:2
pause 1
reread
