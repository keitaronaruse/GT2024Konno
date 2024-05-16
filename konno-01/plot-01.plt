set terminal png
set output 'plot-01.png'

set xrange [ 0: 10 ]
set yrange [ -4: 12 ]

set xlabel 'time [s]'
set xlabel font "Arial,12"

set ylabel 'Position [m]'
set ylabel font "Arial,12"

set title 'Position of Leader and Follower at k = 0.1'
set title font'Arial,12'

plot 'out-01.txt' u 1:3 w lp t 'Leader', 'out-01.txt' u 1:5 w lp t 'Follower'

set terminal qt
set output
