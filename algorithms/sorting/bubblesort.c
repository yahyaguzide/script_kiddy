//#include <stdlib.h>
//#include <stdio.h>

/*****************************************************************
//  bubblesort
//
// date: 20.10.2019
// name: Yahya Guezide
// Sort's arrays in switching two neighboring Element
// if they are not inorder
//
*****************************************************************/

void mswitch(int*,int*);
unsigned int bubblesort(int *arr, int maxIndex){
    int *arrIndex= arr;
    unsigned int counter = 0;
    _Bool sorted = 0;

    while( !sorted ){
        sorted = 1;
        for(; arrIndex-arr < maxIndex-1; arrIndex++ ){
            counter++;
            if( *arrIndex > *(arrIndex+1) ){
                sorted = 0;
                mswitch( arrIndex, arrIndex+1 );
            }
        }
    }
    return counter;
}

void mswitch( int *p1, int *p2 ){
    int buf = *p1;

    *p1 = *p2;
    *p2 = buf;
}
