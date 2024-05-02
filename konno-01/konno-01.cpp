/**
 * @file konno-01.cpp
 * @brief 1-Leader and 1-Follower in a 1D world
 * @author Keitaro Naruse
 * @date 2024-05-02
 * @copyright MIT License
 * @details
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main( int argc, char* argv[] ) {
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

    //  Simulation:: Kinematics
    for( int t = 0; t < T; t++ ) {
        //  Leader-0
        v0.at( t + 1 ) = v0.at( t );
        x0.at( t + 1 ) = x0.at( t ) + dT * v0.at( t );
        //  Follower-1
        v1.at( t + 1 ) = k * ( x0.at( t ) - x1.at( t ) - d );
        x1.at( t + 1 ) = x1.at( t ) + dT * v1.at( t );
    }

    //  Output a simulation result
    std::cout << "# k = " << std::fixed << std::setprecision( 3 ) << k << std::endl;
    std::cout << "# t, v0, x0, v1, x1" << std::endl;
    for( int t = 0; t <= T; t++ ) {
        std::cout << std::fixed << std::setprecision( 3 ) << ( double ) t * dT << ", " << v0.at( t ) << ", "
                  << x0.at( t ) << ", " << v1.at( t ) << ", " << x1.at( t ) << std::endl;
    }

    return 0;
}