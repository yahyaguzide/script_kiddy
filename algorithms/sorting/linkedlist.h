#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//#ifndef NULL
//#define NULL ((void*)0)
//#endif

#ifndef INITLIST
#define INITLIST(var) {var.length= 0;var.start= NULL;}
#endif

struct Element{
    int c;
    struct Element *next;
};

struct List{
    int length;
    struct Element *start;
};

typedef struct Element Element;
typedef struct List List;

Element *pushElem(List *, int);

int popElem(List *);

static Element *allocElem( void );

Element *getElem(List *, int);

void swapC(List *, Element *, Element *);

#endif
