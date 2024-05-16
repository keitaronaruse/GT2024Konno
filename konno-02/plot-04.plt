set terminal png
set output 'plot-04.png'

set xrange [ 0: 10 ]
set yrange [ -4: 12 ]

set xlabel 'time [s]'
set xlabel font "Arial,12"

set ylabel 'Position [m]'
set ylabel font "Arial,12"

set title 'Position of Leader and Follower at k = 20.0'
set title font'Arial,12'

plot 'out-04.txt' u 1:3 w lp t 'Leader', 'out-04.txt' u 1:5 w lp t 'Follower-1', 'out-04.txt' u 1:7 w lp t 'Follower-2'

set terminal qt
set output
