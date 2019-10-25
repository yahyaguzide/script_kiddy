//#include <stdlib.h>
#include <stdio.h>

#include "algos_sorting.h"

/*****************************************************************
//  algos_test
//
// date: 07.10.2019
// name: Yahya Guezide

*****************************************************************/

#define MAXARR 100
int main( int argc, char **argv ){
    int arr[MAXARR];
    for(int i= 0; i < MAXARR; i++)
        arr[i] = MAXARR - i;
    
    printf("quicksort n: %d\n", quicksort( arr, 0, MAXARR ));

    return 0;
}

