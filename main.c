#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PERIOD 48
#define AMPLITUDE 10000

char nibble2hex( char value ){
	switch( value ){
		case( 0x00 ):
			return( '0' );
		case( 0x01 ):
			return( '1' );
		case( 0x02 ):
			return( '2' );
		case( 0x03 ):
			return( '3' );
		case( 0x04 ):
			return( '4' );
		case( 0x05 ):
			return( '5' );
		case( 0x06 ):
			return( '6' );
		case( 0x07 ):
			return( '7' );
		case( 0x08 ):
			return( '8' );
		case( 0x09 ):
			return( '9' );
		case( 0x0A ):
			return( 'A' );
		case( 0x0B ):
			return( 'B' );
		case( 0x0C ):
			return( 'C' );
		case( 0x0D ):
			return( 'D' );
		case( 0x0E ):
			return( 'E' );
		default:
			return( 'F' );
	}
}

void short2hex( short value, char *string ){
	char nibble;
	string[ 4 ] = '\0';
	for( int i=0 ; i < 4 ; i++ ){
		nibble = ( char )( ( value >> ( 4*( 3-i ) ) ) & 0x000F );
		string[ i ] = nibble2hex( nibble );
	}
}

short fx_sin( double amplitude, double period, double x ){
	amplitude = amplitude/10;
	short result = ( short )amplitude*sin( 2*M_PI*( 1/period )*x );
	return 10*result;
}

int main( int argc, char **argv ){
	char *shortMessage = ( char* )malloc( sizeof( char )*10 );
	for( int i=1 ; i <= PERIOD ; i++ ){
		printf( "%hd,", 4*fx_sin( AMPLITUDE, PERIOD, i ) );
		short2hex( 4*fx_sin( AMPLITUDE, PERIOD, i ), shortMessage );
		printf( "%s", shortMessage );
		printf( "\n" );
	}
	return 0;
}
