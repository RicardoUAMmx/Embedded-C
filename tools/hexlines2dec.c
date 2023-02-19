#include <stdio.h>

int powerInt( int value, int power ){
	int v = value;
	for( int i = power ; i > 1 ; i-- ){
		v = v*value;
	}
	return v;
}

int pwri( int value, int power ){
	if( power > 1 ){
		return powerInt( value, power );
	} else if( power == 1 ){
		return value;
	} else {
		return 1;
	}
}

int hex2dec( char c ){
	if( ( c-48 >= 0 ) && ( c-48 <= 9 ) ){
		return c-48;
	} else if( ( c-55 >= 10 ) && ( c-55 <= 15 ) ){
		return c-55;
	} else {
		return -1;
	}
}

int dec2short( int dec ){
	if( dec >= 32768 ){
		return -( 65536 - dec );
	} else {
		return dec;
	}
}

int main( int argc, char **args ){
	FILE *fp;
	int value = 0;
	if( ( fp = fopen( args[ 1 ], "r" ) ) == NULL ){
		printf( "Error: file failed to open.\n" );
	} else {
		while( !feof( fp ) ){
			for( int i = 3 ; i >= 0 ; i-- ){
				value += hex2dec( fgetc( fp ) )*pwri( 16, i );
			}
			printf( "%d%c", dec2short ( value ), fgetc( fp ) );
			value = 0;
		}
		fclose( fp );
	}
	return 0;
}
