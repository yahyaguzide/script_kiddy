#include <stdlib.h>

#include "include/listElement.h"

/**************************************************
//  listELement
//
// date: 04.11.2019
// name: Yahya Guezide
// Simple Element for a List
//
***************************************************/

typedef struct _element element;

void Element_Init( element *elem ){
	elem->data = NULL;
	elem->next = NULL;
}

element* Element_Create(){
	element *elem= (element*)malloc(sizeof(element));
	Element_Init(elem);
	return elem;
}


void* Element_GetData( element *elem ){
	if( !elem )
		return NULL;

	return elem->data;
}

void Element_UpdateData( element *elem, void *data ){
	if( !elem && !data )
		return;

	if( elem->data )
		free(elem->data);

	elem->data = data;
}

void Element_Free( element **elem ){
	if( !elem && !*elem )
		return;

	free(*elem);
	*elem = NULL;
}
