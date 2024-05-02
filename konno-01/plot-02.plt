plot 'out-02.txt' u 1:3 w lp t 'Leader', 'out-02.txt' u 1:5 w lp t 'Follower'
set xrange [ 0: 10 ]
set yrange [ -2: 12 ]

set xlabel 'time [s]'
set xlabel font "Arial,12"

set ylabel 'Position [m]'
set ylabel font "Arial,12"

set title 'Position of Leader and Follower at k = 1.0'
set title font'Arial,12'

set terminal png
set output 'plot-02.png'
plot 'out-02.txt' u 1:3 w lp t 'Leader', 'out-02.txt' u 1:5 w lp t 'Follower'
set terminal qt
