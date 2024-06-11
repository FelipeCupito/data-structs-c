#include <stdio.h>
#include <stdlib.h>
#include "vectorADT.h"

struct vectorCDT{
    size_t size;
    elemType *vec;
    char * occupied;
};

vectorADT newVector(void){
    vectorADT aux = calloc(1,sizeof(struct vectorCDT));
    if(aux==NULL){
        return NULL;
    }
    return aux;
}

int put(vectorADT v, elemType * elems, size_t dim, size_t index){
    size_t total = index+dim;
    if(total>=v->size){
        v->vec = realloc(v->vec,total*sizeof(elemType));
        v->occupied = realloc(v->occupied, total*sizeof(elemType));
        if(index>v->size){
            for(int i=v->size; i<index; i++){
                v->occupied[i]=0;
            }
        }
    }
    v->size=total;
    int cont=0, esta;
    for(int i=index, j=0; j<dim; j++, i++){
        esta =0;
        if(v->occupied[i]==1){
            esta=1;
        }
        if(!esta){
            v->occupied[i]=1;
            v->vec[i]=elems[j];
            cont++;
        }
    }
    return cont;
}

int getIdx(vectorADT v, elemType elem){
    for(int i=0; i<v->size; i++){
        if(v->vec[i]==elem){
            return i;
        }
    }
    return -1;
}

void deleteElement(vectorADT v, size_t index){
    if(index>=v->size){
        return;
    }
    v->occupied[index]=0;
    return;
}

int elementCount(vectorADT v){
    int cont=0;
    for(int i=0; i<v->size; i++){
        if(v->occupied[i]==1){
            cont++;
        }
    }
    return cont;
}

int main(void){
    vectorADT v=newVector();
    elemType elems[]={1,2,3,4,5};
    size_t index=0;
    size_t dim =5;
    int guardados=put(v,elems,dim,index);
    int cant = elementCount(v);
    printf("%d %d\n", guardados, cant);
    printf("%d\n", getIdx(v,2));
    elemType elems1[]={4,5,6,7,8};
    index = 3;
    dim = 5;
    guardados=put(v,elems1,dim,index);
    cant = elementCount(v);
    printf("%d %d\n", guardados, cant);
    deleteElement(v,4);
    cant = elementCount(v);
    printf("%d\n", cant);
    return 0;
}
