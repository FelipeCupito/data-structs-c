#include <stdio.h>
#include "listaADT.h"
#include <stdlib.h>

struct node{
    int value;
    struct node * next;
};

listADT newList (){
    listADT l;
    l = malloc(sizeof(*l));
    if ( l == NULL )
        return NULL;
    
    l->next = NULL;
    l->value = 0;
    
    return l;
}

void freeList ( listADT l ){
    if ( l == NULL )
        return;
    
    return freeList(tail(l));
    free(l);
}

listADT insert ( listADT l, int n ){
    listADT aux ;
    
    if ( l == NULL || l->value > n ){// La lista es vacia o todos los demas son mayores a el */
        aux = malloc(sizeof(*aux));
        if (aux == NULL)
            return NULL;
        
        aux->value = n;
        aux->next = l;
        
        return aux;
    }
    
    if ( l->value == n )
        return l;
    
    l->next = insert(l->next, n);
    
    return l;
}

listADT delete ( listADT l, int n ){

    if ( l->value > n )// es mas chico que todos los valores de la lista, por ende no esta
        return l;
    
    if ( l->value == n )
    {
        listADT aux;
        aux = l->next;
        free(l);
        return aux;
    }
    
    l->next = delete(l->next, n);
    
    return l;
}

int belongs ( listADT l, int n ){

    if ( isEmpty(l) || l->value > n )// La lista es vacia o el n no se encuentra
        return 0;
    if (l->value == n )
        return 1;
    
   return belongs(l->next, n);
    
}

int isEmpty ( listADT l ){
    if (l == NULL)
        return 1;
    
    return 0;
}

int head ( listADT l ){ /* devuelve cabeza */
    if ( l == NULL )
        exit(1);
    
    return l->value;
    
}

listADT tail ( listADT l ){/* devuelve cola */
    if ( l==NULL )
        exit(1);
    
    return l->next;
}

int main(){
    return 0;
}