#include <stdio.h>
#include <stdlib.h>
#include "bagADT.h"

struct node{
    elemType head;
    unsigned int count;
    struct node *tail;
};

typedef struct node *nodeP;

struct bagCDT{
    nodeP first;
    unsigned int size;
};

static void Error(const char *s){
    fprintf(stderr, "%s", s);
    exit(EXIT_FAILURE);
}

bagADT newBag(void){
    return calloc(1, sizeof(struct bagCDT));
}

static unsigned int countRec(nodeP first, elemType elem){
    int c;
    if (first == NULL || (c = compare(first->head, elem)) > 0)
        return 0;

    if (c == 0)
        return first->count;
    return countRec(first->tail, elem);
}

unsigned int count(const bagADT bag, elemType elem){
    return countRec(bag->first, elem);
}

static nodeP addRec(nodeP first, elemType elem, int *countElem){
    int c;
    if (first == NULL || (c = compare(first->head, elem)) > 0)
    {
        nodeP aux = malloc(sizeof(struct node));
        if (aux == NULL)
            Error("No hay lugar para otro nodo\n");
        aux->tail = first;
        aux->head = elem;
        aux->count = 1;
        *countElem = 1;
        return aux;
    }
    if (c < 0)
        first->tail = addRec(first->tail, elem, countElem);
    else
        *countElem = ++(first->count);
    return first;
}

unsigned int add(bagADT bag, elemType element){
    int countElem;
    bag->first = addRec(bag->first, element, &countElem);
    if (countElem == 1) // es el primero
        bag->size++;
    return countElem;
}

void freeBag(bagADT bag){
    nodeP curr = bag->first, aux;
    while (curr != NULL)
    {
        aux = curr->tail;
        free(curr);
        curr = aux;
    }
    free(bag);
}

unsigned int size(const bagADT bag){
    return bag->size;
}

elemType mostPopular(const bagADT bag){
    elemType ans;
    if (bag->size == 0)
    {
        errno = 1;
    }
    else
    {
        nodeP aux = bag->first;
        int cant = aux->count;
        ans = aux->head;
        aux = aux->tail;
        while (aux != NULL)
        {
            if (aux->count > cant)
            {
                ans = aux->head;
                cant = aux->count;
            }
            aux = aux->tail;
        }
    }
    return ans;
}
