#ifndef LISTELEMENT_H
#define LISTELEMENT_H

typedef struct _element{
	void *data;
	struct _element *next;
}element;

void Element_Init(element*);
element* Element_Create();
void* Element_GetData(element*);
void Element_UpdateData(element*, void* );
void Element_Free(element**);

#endif
