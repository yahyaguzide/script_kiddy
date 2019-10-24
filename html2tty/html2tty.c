//#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*****************************************************************
//  html2tty
//
// date: 15.10.2019
// name: Yahya Guezide
// A simple Program to display html on the Terminal
//
*****************************************************************/

#define MAXTOKENS 15
#define FREE(ptr) {\
    if(ptr)\
        free(ptr);\
}


struct {
    static tid;
    char *tokens[MAXTOKENS];

    void Push( char *t ){
        if( tid < MAXTOKENS )
            tokens[tid++] = t;
    }
    void Pull( char *buffer ){
        strncpy(buffer, tokens[--tid], sizeof(*buffer));
        FREE(tokens[tid+1]);
    }
    void FreeTop(){
        if( (tid-1)>0 ){
            tid--;
            FREE( tokens[tid] );
        }
    }
    char *Top(){
        return tid? NULL:  tokens[tid-1];
    }
} tokenStack;

int (*fpt)(void);

int main( /*int argc, char **argv*/ ){
    
    
    return 0;
}



char* getToken(void);
int printTable(void){
    enum {tr, th, td};
    char **tableTokens= {"tr", "th", "td"};
    
}


// NOTE: don't  forget to FREE token after using it
#define MAXBUF 50
char* getToken(){
    int c, buffer[MAXBUF], bid= 0;

    while( (c= getchar()) != '<' );
    while( isspace(c= getchar()) );

    buffer[bid++] = c;
    while( (c= getchar()) != EOF ){
        if( !isspace(c) && bid < MAXBUF )
            buffer[bid++] = c;
        else
            break;
    }
    while( (c= getchar()) != '>' );
   
    buffer[bid++] = '\0';
    char *t= (char*)malloc( (bid) * sizeof(char) );
    strncpy(t, buffer, bid * sizeof(char));
    return t;
}
