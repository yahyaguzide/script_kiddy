#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct _element element;
typedef struct _list list;

void List_Init(list*);
list* List_Create();
void List_AddHead(list*, void*);
void List_AddTail(list*, void*);

// Returns void pointer to previous Element, 
// if sElem is the Head return void pointer to list.
// Returns NULL if sElem not in list or if any NULL was given
void* List_InList(list*, sElem);

void List_Delete(list*, elem*);

#endif
