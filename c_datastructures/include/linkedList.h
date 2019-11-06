#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listElement.h"

typedef struct _list{
    struct _element *head;
    struct _element *tail;
    unsigned int length;
} list;


void List_Init(list*);
list* List_Create();
void List_AddHead(list*, void*);
void List_AddTail(list*, void*);
int List_GetLength(list*);
element* List_GetElem(list*, int);

// Returns void pointer to previous Element, 
// if sElem is the Head return void pointer to list.
// Returns NULL if sElem not in list or if any NULL was given
void* List_InList(list*, element*);


void List_Delete(list*, element*);

#endif
