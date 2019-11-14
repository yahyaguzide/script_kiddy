#include <stdio.h>


int main(){
	
#pragma omp parallel
{
	printf("Dude that shit dope!\n");
}

int n= 0;
#pragma omp parallel for
for( int i= 0; i< 100; i++ ){
	n += i;
}
	
	printf("%d \nI am The fucking Parent\n", n);

	return 0;
}
