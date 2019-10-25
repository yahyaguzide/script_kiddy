//#include <stdlib.h>
#include <stdio.h>

/*****************************************************************
//  selection
//
// date: 20.10.2019
// name: Yahya Guezide
// Finds the minimum element and puts it at the begining
// will hold two subarray's first one will be sorted the second one unsorted,
// the max index of the first subarray is going to be increassed 
// after every sorting process
//
*****************************************************************/

void mswitch(int*, int*);
unsigned int Selection( int *arr, int maxIndex ){
    int *subArr, minElem;
    subArr = minElem = arr;

    for(; subArr-arr < maxIndex; subArr++ ){
        minElem = subArr;
        for( int i= 0; i < maxIndex - (subArr - arr); i++ ){
            if( *(subArr+i) < *minElem )
                minElem = (subArr+i);
        }
        mswitch( subArr, minElem );
    }

}


void mswitch(int *p1, int *p2){
    int buf = *p1;

    *p1 = *p2;
    *p2 = buf;
}
