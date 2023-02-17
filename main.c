#include <stdio.h>
#include <stdlib.h>
#define SINE_TABLE_SIZE 48

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

int main( int argc, char **argv ){
	short sinetable[ SINE_TABLE_SIZE ] = {
		1300, 2580, 3820, 5000, 6080, 7070, 7930, 8660,
		9230, 9650, 9910, 10000, 9910, 9650, 9230, 8660,
		7930, 7070, 6080, 5000, 3820, 2580, 1300, 0,
		-1300, -2580, -3820, -5000, -6080, -7070, -7930, -8660,
		-9230, -9650, -9910, -10000, -9910, -9650, -9230, -8660,
		-7930, -7070, -6080, -5000, -3820, -2580, -1300, 0
	};
	char *shortMessage = ( char* )malloc( sizeof( char )*10 );
	for( int i=0 ; i < SINE_TABLE_SIZE ; i++ ){
		short2hex( sinetable[ i ], shortMessage );
		printf( "%s", shortMessage );
		printf( "\n" );
	}
	return 0;
}
