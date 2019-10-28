#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**************************************************
//  fequal
//
// date: 28.10.2019
// name: Yahya Guezide
// Simple program to ceck if two Files are equal.
// It does not consider space Characters!
//
***************************************************/

#define ERRMSG(e) { printf( "ERROR: %s", e ); }

int main( int argc, char **argv ){
	if( argc < 3 ){
		ERRMSG( "No Args given" );
		return 0;
	}

	FILE *fpt[2];

	fpt[0] = fopen( argv[1], "r" );
	fpt[1] = fopen( argv[2], "r" );

	int cfpt[2];
	while( !feof(fpt[0]) && !feof(fpt[1]) ){
		for(int i= 0; i < 2; i++ ){
			while( isspace(cfpt[i]= fgetc(fpt[i])) );
		}

		if( cfpt[0] != cfpt[1] ){
			printf( "Files %s and %s are not equal\n", argv[1], argv[2] );	
			return 0;
		}

	}
	fclose( fpt[0] );
	fclose( fpt[1] );

	printf( "Files %s and %s are equal\n", argv[1], argv[2] );	


    return 0;
}



