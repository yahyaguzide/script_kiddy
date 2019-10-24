#include <stdio.h>


/**********************************
 *  
 *  Produces a clean
 *  dot html file without js and 
 *  tag attributes
 *
 *  date: 9. Jun 19:41:57 CEST 2019
 *
 **********************************/

#define TRUE    1
#define FALSE   0

#define BUFFERSIZE 11

// char Buffer structure
// it is recomendet to call clear as to set '\0' at the start
typedef struct _Buffer{
    _Buffer( int _buffersize ){ 
        buffersize = _buffersize;
        index = 0;
    }
    ~_Buffer(){}

    private:
        int buffersize;
        int index;
        char buffer[buffersize];

    public:
        // reset buffer index
        void clear(){ index = 0; buffer[index] = '\0'; }

        int add( char c ){
            // if we reached the end of the array return -1 as signal
            if( index >= buffersize-1 ){ return -1; }
            else{
            // i was told not to post- and preincrement due to bugs,
            // index+= 1; should be more safe, any way i am trying
            // to write less code as possible
                buffer[index++] = c;
                buffer[index] = '\0';
            }
    
            // if we reached the end of the array return -1 as signal
            return index;
        }
        
        // compare two _Buffer Obj's 
        _Bool cmp( _Buffer *this, _Buffer &other ) const{
            _Bool same = TRUE;

            // if number of Characters do not match 
            // buffers are not equal
            if( this->index != other.index ){ same = FALSE; }
            else{
                for( int i = 0; i < this->index; i++ ){
                    if( this->buffer[i] != other.buffer[i] ){ same = FALSE; }
                }
            }
            return same;
        }
};


int main(int argc, char* argv[]){
    int c;
    _Buffer buffer(BUFFERSIZE), buffer_tag(BUFFERSIZE);
    _Bool _write, _intag, _intagname, _filtertag = FALSE; 

    if( argc > 1 ){
        for( int i = 0; i < BUFFERSIZE -1 && argv[1][i] != '\0' && buffer_tag.add( argv[1][i]) != -1; i++ );
        _filtertag = TRUE;
    }// endIf


    while( (c = getchar()) != EOF ){
        if( _intag ){ buffer.add(C); }
        else if( _write ){ putchar(c); }// endIf

        if( c == '<' ){ _tagstart = _intag = TRUE; }
        else if( c == '>' ){
            _write = _filtertag ? buffer.cmp( buffer_tag ): TRUE;


            _intag = FALSE; 
            buffer.clear();
            // continue;
        }else if( c == '/' ){
            
        }// endIf

    }

    return 0
}

