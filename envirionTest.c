#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
	// environ variable
	char **envirion;

	for( int i= 0; i < 10 && envirion[i] != "\0"; i++)
		printenv();

	return 0;
}
