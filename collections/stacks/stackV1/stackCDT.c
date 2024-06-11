#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackADT.h"
#define BLOQUE 5

struct stackCDT{
    void * v;
    size_t bytes;
    int dim;
    int size;
};

int isEmpty ( stackADT s ){
    return (s->dim <= 0 );
    
}


void push ( stackADT s, void * elem )
{
    if ( s->dim == s->size)
    {
        s->v = realloc(s->v,(s->size+BLOQUE)*s->bytes);
        if (s->v == NULL )
            exit(1);
        
        s->size += BLOQUE;
    }
    
    memcpy(s->v+s->dim*s->bytes, elem, s->bytes);
    s->dim++;
}

void * pop ( stackADT s )
{
    void * p;
    
    if ( isEmpty(s) )
        exit(1);
    
    p = malloc(s->bytes);
    memcpy(p, s->v+(s->dim-1)*s->bytes, s->bytes);
    
    return p;

}