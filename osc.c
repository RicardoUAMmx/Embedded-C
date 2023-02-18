#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fn( double amplitude, double period, double x ){
	amplitude = amplitude/10;
	int result = ( int )amplitude*sin( 2*M_PI*( 1/period )*x );
	return 10*result;
}

int main( int argc, char **args ){
	int A = atoi( args[ 1 ] );
	int T = atoi( args[ 2 ] );
	for( int i=1 ; i<=T ; i++ ){
		printf( "%d\n", fn( A,T,i ) );
	}
	return 0;
}
