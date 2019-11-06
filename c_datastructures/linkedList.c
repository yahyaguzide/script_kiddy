#include <stdlib.h>

#include "include/linkedList.h"
#include "include/listElement.h"

/*****************************************************************
//  linkedlist
//
// date: 24.10.2019
// name: Yahya Guezide
//  Simple Linked List 
//
*****************************************************************/

typedef struct _list list;

void List_Init( list *l ){
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;
}

list* List_Create(){
	list *l = (list*)malloc(sizeof(list));
	List_Init(l);
	return l;
}

void List_AddHead( list *l, void *data ){
    if( l == NULL || data == NULL )
        return;

    element *elem = (element*)malloc(sizeof(element));
    elem->next = l->head;
    l->head = elem;

    if( l->tail == NULL )
        l->tail = elem;

    elem->data = data; 
    l->length++;
}

void List_AddTail( list *l, void *data ){
    if( l == NULL || data == NULL )
        return;

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

int List_GetLength( list *l ){
	return l->length;
}

element* List_GetElem( list *l, int index ){
	if( l->length <= index && !l )
		return NULL;

	element *elem = l->head;
	for(; index > 0; index-- )
		elem = elem->next;
	return elem;
}

void* List_InList( list *l, element *sElem ){
	if( !l && !sElem )
		return NULL;

	if( l->head == sElem )
		return (void*)l;

	element *elem = l->head;
	for(; elem->next != NULL; elem= elem->next )
		if( elem->next == sElem )
			return (void*)elem;
	return NULL;
}

void List_Delete( list *l, element *dElem ){
	void *preElem;
	element *tmp;
	if( !l && !dElem && !(preElem= List_InList( l, dElem )) )
		return;

	// The given Element is the Head
	if( (void*)l == preElem ){
		tmp = l->head;
		l->head = tmp->next;
	}else{ // Element is in the List but not The Head
		tmp = ((element*)preElem)->next;
		((element*)preElem)->next = tmp->next;
	}
	l->length--;
	free(tmp);
}
