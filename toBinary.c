#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**************************************************
//  toBinary
//
// date: 26.10.2019
// name: Yahya Guezide
// Simple Binary converter
//
***************************************************/

int main( int argc, char **argv ){
	int c, num = 0;

	while( (c= getchar()) != '\n' && c != EOF )
		if( isdigit(c) )
			num = num * 10 + c - '0';

	while( num != 0 ){
		putchar( '0' + (num % 2) );
		num /= 2;
	}
	putchar( '\n' );

    return 0;
}

