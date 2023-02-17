#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lineReader( char **line ){
	size_t lenBuffer;
	if( getline( line, &lenBuffer, stdin ) < 0 ){
		if( feof( stdin ) ){
			free( *line );
			return 0;
		} else {
			free( *line );
			perror( "Read line" );
			return 0;
		}
	}
	return 1;
}

int charReader( char **line ){
	int c, position = 0; /* getchar and position buffer */
	//{{{ Allocation buffer memory
	size_t lenBuffer = 256;
	char *buffer = ( char* )malloc( sizeof( char )*lenBuffer );
	if( !buffer ){
		fprintf( stderr, "cli: allocation error\n" );
		return 0;
	}
	// End: Allocation buffer memory }}}
	//{{{ getchar loop
	while( 1 ){
		c = getchar(  );
		if( c == EOF || c == '\n' ){
			buffer[ position ] = '\n';
			buffer[ position+1 ] = '\0';
			*line = realloc( *line, lenBuffer+1 );
			if( !*line ){
				fprintf( stderr, "cli: allocation error" );
			}
			strcpy( *line, buffer );
			return position;
		} else {
			buffer[ position ] = c;
		}
		position++;
		//{{{ realloc buffer
		if( position >= lenBuffer ){
			lenBuffer += 256;
			buffer = realloc( buffer, lenBuffer );
			if( !buffer ){
				fprintf( stderr, "cli: allocation error\n" );
				return 0;
			}
		}
		// End: realloc buffer }}}
	}
	// End: getchar loop }}}
}

int enterTerminal( char *infoDisp ){
	int status;
	char *line = NULL;
	printf( "Testing Software Inc.\n" );
	do{
		printf( "%s> ", infoDisp );
		status = charReader( &line );
		printf( "%d: %s", strlen( line ), line );
		free( line );
	} while( status );
	return !status;
}


