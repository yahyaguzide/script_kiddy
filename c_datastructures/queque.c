//#include <stdlib.h>
#include <stdio.h>

/*****************************************************************
//  queque
//
// date: 24.10.2019
// name: Yahya Guezide
// Simple queque with help of a linkedlist
//
*****************************************************************/

typedef struct _element element;
typedef struct _list list;

void InitList(list*);
void AddHead(list*, element*);
void Delete( int (*fpt_compare)(void*,void*), list*, element* );

void AddQue( list *l, elment *elem ){
    AddHead( l, elem );
}

void* PopQue( list *l ){
    if( l == NULL || l->head == NULL )
        return void;

    element *tmp = l->head;
    void *tmpdata = tmp->data;

    l-head = tmp->next;
    free(tmp);
    return tmpdata;
}
