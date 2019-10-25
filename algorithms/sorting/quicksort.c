//#include <stdlib.h>
#include <stdio.h>

/*****************************************************************
//  quicksort
//
// date: 07.10.2019
// name: Yahya Guezide
// the quick sort algorithm wiht
// worst case O(sqrt2) ~O(nlog(n))
//
*****************************************************************/

void swap(int*, int, int);
int quicksort( int *p, int low, int high ){
    static int n= 0;
    if( low != high ){
        int pivot = high;

        int j, i= low-1;
        for(j= low; j < high; j++  ){
            if( p[i] < p[pivot]){
                i++;
                swap(p, i , j);
            }
            n++;
        }
        swap(p, i+1, pivot);

        quicksort(p, low, i);
        quicksort(p, i+1, high);
    }
    return n;
}

void swap( int *p, int i, int j){
    int tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}




