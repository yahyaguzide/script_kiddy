#include <stdlib.h>

/*****************************************************************
//  linkedlist
//
// date: 24.10.2019
// name: Yahya Guezide
//  Simple Linked List 
//
*****************************************************************/

typedef struct _element{
    void *data;
    struct _element *next;
} element;

typedef struct _list{
    struct _element *head;
    struct _element *tail;
    unsigned int length;
} list;

void InitList( list *l ){
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;
}

void AddHead( list *l, void *data ){
    if( l == NULL || data == NULL )
        return void;

    element *elem = (element*)malloc(sizeof(element));
    elem->next = l->head;
    l->head = elem;

    if( l->tail == NULL )
        l->tail = elem;

    elem->data = data; 
    l->length++;
}

void Add( list *l, void *data ){
    if( l == NULL || data == NULL)
        return void;

    element *elem = (element*)malloc(sizeof(element));
    elem->next = NULL;

    if( l->head == NULL )
        l->head = elem;
    else
        l->tail->next = elem;

    elem->data = data;
    l->tail = elem;
    l->length++;
}

void Delete( int (*fpt_compare)(void*, void*), list *l, void *data ){
    if( fpt_compare == NULL || l == NULL || l->head == NULL || data == NULL )
        return void;

    element elem = l->head, prelem = NULL;

    for( int i= 0, i < l->length && elem != NULL; i++, elem = elem->next ){
        if( fpt_compare(*data, *elem->data) == 0 ){
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
