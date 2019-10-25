#include <stdlib.h>

#include "linkedlist.h"

Element *pushElem( List *list, int var ){
    Element *elem, *new_elem;

    if( !(new_elem= allocElem()) )
    { return NULL; }

    new_elem->c= var;
    new_elem->next= NULL;

    if( list->start == NULL )
        list->start = new_elem;
    else{
        if( !(elem= getElem(list, list->length - 1)) ){
            free(new_elem);
            return NULL;
        }
        elem->next = new_elem;
    }

    ++(list->length);
    return new_elem;
}

int popElem( List *list ){
    if( !list || list->length == 0 || !list->start ){ return -1; }

    Element *tmp;
    int c;
    if( list->length == 1 ){
        tmp= list->start;
        c= tmp->c;
        list->start = NULL;
    }else{
        Element *elem= getElem(list, list->length-2);
        if( !elem ){ return -1; }
        
        tmp= elem->next;
        c= tmp->c;
        elem->next = NULL;
    }

    free(tmp);
    --(list->length);
    return c;
}

static Element *allocElem( void ){
    return (Element*)malloc(sizeof(Element));
}

Element *getElem( List *list, int i ){
    if( !list || i >= list->length ){ return NULL; }
    
    Element *elem = list->start;
    for(; i-- > 0; elem = elem->next );
    return elem;
}

void swapC( List *list, Element *elemi, Element *elemj ){
    if( elemi != elemj && elemi && elemj && list && list->length>1 ){
        int tmp = elemi->c;
        elemi->c = elemj->c;
        elemj->c = tmp;
    }
}
