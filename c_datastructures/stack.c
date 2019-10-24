//#include <stdlib.h>
#include <stdio.h>

/*****************************************************************
//  stack.c
//
// date: 24.10.2019
// name: Yahya Guezide
// Simple Stack with the help of LinkedList
//
*****************************************************************/

typedef struct _element element;
typedef struct _list list;

void InitList(list*);
void AddHead(list*, void*);
void Delete( int (*fpt_compare)(void*,void*), list*, void* );

void PushStack( list *l, void *data ){
    AddHead(l, data);
}

void* PopStack( list *l ){
    if( l == NULL || l->head == NULL )
        return void;

    element *tmp = l->head;
    void *tmpdata = tmp->data;

    l-head = tmp->next;
    free(tmp);
    return tmpdata;
}


