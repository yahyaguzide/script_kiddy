//#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "linkedlist.h"

/*****************************************************************
//  quicksort
//
// date: 05.10.2019
// name: Yahya Guezide
// simple sorting algorithm
// with O(n*log(n)) worst case O(sqrt(n))
//
*****************************************************************/


void quicksort_rekursiv( List *list, Element *low, Element *high ){
    Element *pivot= high;

    if( low != high ){
    //** partition
    Element *elemi, *elemj;
    elemi= low;
    for( elemj= low; elemj != high; elemj = elemj->next){
        if( elemj->c < pivot->c ){
            swapC( list, elemi, elemj);

            elemi = elemi->next;
        }
        swapC( list, elemi->next, pivot );
    }
    //** 
    
    quicksort_rekursiv( list, low, elemi );
    quicksort_rekursiv( list, elemi->next, high );

    }
}

