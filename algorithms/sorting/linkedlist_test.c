//#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

/*****************************************************************
//  linkedlist_test
//
// date: 05.10.2019
// name: Yahya Guezide
// to test linked list
//
*****************************************************************/

int main( int argc, char **argv ){
    List list;
    INITLIST(list);

    int i;
    for( i= 4; i >= 0; i-- )
        pushElem(&list, i);

//    quicksort_rekursiv( &list, list.start, getElem( &list, list.length-1 ) );

    printf( " element %p\n", getElem(&list, list.length-1));

    printf( "\tlist length: %d\n", list.length );
    for( i= 0; i < 5; i++ )
       printf( "%-d : %d\n", i, popElem(&list));


    return 0;
}

