#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

typedef struct node {
    elementType value;
    struct node * next;
} tNode;

struct queueCDT {
    tNode * first;
    tNode * last;
    tNode * iterator;
};

static void freeRec(tNode *);

queueADT 
newQueue(void){
    return calloc(1, sizeof(struct queueCDT));
}

/**
 * Se agrega un elemento al final de la lista
**/
int queue(queueADT queue, elementType element) {
    tNode * node = calloc(1, sizeof(tNode));
    if(node == NULL) {
        return 0;
    }
    node->value = element;
    if (isEmpty(queue)){
        queue->first = node;
        queue->last = node;
    } else {
        queue->last->next = node;
        queue->last = node;
    }
    return 1;
}

/**
 * Se puede comparar con NULL first o last. 
**/
int 
isEmpty(queueADT q) {
    return q->first == NULL;
}

/**
 * Se remueve un elemento al principio de la lista
**/
int dequeue(queueADT queue, elementType * element) {
    if (isEmpty(queue)) {
        return 0;
    }
    *element = queue->first->value;
    tNode * currentFirst  = queue->first;
    if(currentFirst == queue->last) {
        queue->first = queue->last = NULL;
    } else {
        queue->first = queue->first->next;
    }
    free(currentFirst);
    return 1;
}

void 
freeQueue(queueADT q) {
	freeRec(q->first);
	free(q);
}

static void
freeRec(tNode * l) {
    if(l == NULL) {
        return ;
    }
    freeRec(l->next);
    free(l);
}

void
toBegin(queueADT q) {
    q->iterator = q->first;
}

int
hasNext(queueADT q) {
    return q->iterator != NULL;
}

elementType
next(queueADT q) {
    elementType element = q->iterator->value;
    q->iterator = q->iterator->next;
    return element;
}

int main(void) {
    queueADT q = newQueue();
    queue(q, 5);
    queue(q, 9);
    queue(q, 3);
    toBegin(q);
    while(hasNext(q)) { // 5 9 3
        printf("%d ", next(q));
    }
    printf("\n");
    int aux;
    dequeue(q, &aux);
    printf("%d\n", aux); // 5
    dequeue(q, &aux);
    printf("%d\n", aux); // 9
    queue(q, 1);
    dequeue(q, &aux);
    printf("%d\n", aux); // 3
    dequeue(q, &aux);
    printf("%d\n", aux); // 1
    printf("%d\n", isEmpty(q)); // 1
    freeQueue(q);}