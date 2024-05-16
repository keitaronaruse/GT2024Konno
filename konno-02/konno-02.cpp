/**
 * @file konno-02.cpp
 * @brief 1-Leader and 2-Follower in a 1D world, uni-directional
 * @author Keitaro Naruse
 * @date 2024-05-16
 * @copyright MIT License
 * @details
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main( int argc, char* argv[] ) {
    //  argv[ 1 ] = { 0.1, 1.0, 10.0, 20.0 }
    //  Simulation settings::Time
    const double t0 = 0.0, tT = 10.0, dT = 0.1;
    const int T = ( int ) ( ( tT - t0 ) / dT );
    //  Taeget distance between robots
    const double d = 1.0;
    //  Control
    const double k = ( argc == 1 ) ? 0.0 : std::stod( argv[ 1 ] );
    //  Leader-0
    std::vector< double > v0( T + 1 ), x0( T + 1 );
    v0.at( 0 ) = 1.0;
    x0.at( 0 ) = 0.0;
    //  Follower-1
    std::vector< double > v1( T + 1 ), x1( T + 1 );
    v1.at( 0 ) = 0.0;
    x1.at( 0 ) = -1.0;
    //  Follower-2
    std::vector< double > v2( T + 1 ), x2( T + 1 );
    v2.at( 0 ) = 0.0;
    x2.at( 0 ) = -2.0;

    //  Simulation:: Kinematics
    for( int t = 1; t <= T; t++ ) {
        //  Leader-0
        v0.at( t ) = v0.at( t - 1 );
        x0.at( t ) = x0.at( t - 1 ) + dT * v0.at( t );
        //  Follower-1
        v1.at( t ) = k * ( x0.at( t - 1 ) - x1.at( t - 1 ) - d );
        x1.at( t ) = x1.at( t - 1 ) + dT * v1.at( t );
        //  Follower-2
        v2.at( t ) = k * ( x1.at( t - 1 ) - x2.at( t - 1 ) - d );
        x2.at( t ) = x2.at( t - 1 ) + dT * v2.at( t );
    }

    //  Output a simulation result
    std::cout << "# k = " << std::fixed << std::setprecision( 3 ) << k << std::endl;
    std::cout << "# t, v0, x0, v1, x1, v2, x2" << std::endl;
    for( int t = 0; t <= T; t++ ) {
        std::cout << std::fixed << std::setprecision( 3 ) << ( double ) t * dT << ", " << v0.at( t ) << ", "
                  << x0.at( t ) << ", " << v1.at( t ) << ", " << x1.at( t ) << ", " << v2.at( t ) << ", " << x2.at( t )
                  << std::endl;
    }

    return 0;
}