#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"

typedef struct node {
		int elem;
		struct node *tail;
} TNode;

TList arrayToList(int elements[], int dim) {
	TList nodes[dim];
	for(int i = dim - 1; i >= 0; i--) {
		nodes[i] = calloc(1,sizeof(*(nodes[i])));
		nodes[i]->elem = elements[i];
		if(i != dim - 1) {
			nodes[i]->tail = nodes[i+1];
		}
	}
	return nodes[0];
}

void printList(TNode * list) {
	if(list == NULL) {
		printf("NULL\n");
		return ;
	}
	printf("%d -> ", list->elem);
	printList(list->tail);
}

/*
Una lista vacia se representa con el valor NULL.
Escribir una funcion recursiva que reciba como unico parametro es una lista ordenada pero con repetidos y elimine de la misma las repeticiones. 
Por ejemplo si la lista es {1, 3, 3, 3, 4, 5, 5, 6, 6, 6} la lista quede {1, 3, 4, 5, 6}
*/
TList eliminaRepetidas(TList l) {
	if(l == NULL || l->tail == NULL) {
		return l;
	}
	if(l->elem == l->tail->elem) {
		TList aux = l->tail;
		free(l);
		return eliminaRepetidas(aux);
	} 
	l->tail = eliminaRepetidas(l->tail);
	return l;
}

int main(void) {
	int v[] = {1, 3, 3, 3, 4, 5, 5, 6, 6, 6};
	int dim = sizeof(v) / sizeof(v[0]);
	printList(arrayToList(v,dim));
	printList(eliminaRepetidas(arrayToList(v, dim)));
}