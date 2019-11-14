#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MAXTHREAD 3

void *runner(void *param);

int main(){
pthread_t tids[MAXTHREAD];
pthread_attr_t attr;

pthread_attr_init(&attr);

for( int i = 0; i< MAXTHREAD; i++ ){
	pthread_create(&tids[i], &attr, runner, &i);
	pthread_join( tids[i], NULL);
}

return 0;
}

void *runner( void *param ){
	switch( *((int *)param) ){
		case 0:
			printf("Hello");
			break;
		case 1:
			printf("World");
			break;
		case 2:
			printf("!\n");
			break;
	}
	pthread_exit(0);
}
