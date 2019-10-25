//#include <stdlib.h>
#include <stdio.h>

/*****************************************************************
//  circ_linkedlist
//
// date: 24.10.2019
// name: Yahya Guezide
// Simple Circular Linked list
//
*****************************************************************/

typedef struct _element{
    void *data;
    struct _element *next;
} element;

typedef struct _circ_list{
    struct _element *head;
    struct _element *tail;
    struct _element *current;
} circ_list;

void InitList( circ_list *l ){
    l->head = NULL;
    l->tail = NULL;
}

void Cl_Add( list *l, void *data ){
    element *elem = (element*)malloc(sizeof(element));
    element
}

void Delete( int (*fpt_compare)(void*, void*), list *l, void *data ){
    if( fpt_compare == NULL || l == NULL || l->head == NULL || data == NULL )
        return void;

    element elem, prelem = NULL;

    for( elem= l->head, elem != l->head; elem = elem->next ){
        if( fpt_compare(data, elem->data) == 0 ){
            if( !prelem )
                l->head = elem->next;
            else
                prelem->next = elem->next;
            free(elem->data);
            free(elem);
            l->length--;

            break;
        }
        prelem = elem;
    }
}
