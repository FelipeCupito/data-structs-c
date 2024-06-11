#include <stdio.h>
#include <stdlib.h>
#include "listADTv2.h"

struct node {
	elemType value;
	struct node * next;
};

typedef struct node * nodeP;

struct listCDT {
	nodeP first;
	unsigned int size;
	nodeP iteradorNext;
};

elemType doble(const elemType elem){
	return 2 * elem;
}

static void Error(const char* s){
	fprintf(stderr, "%s", s);
	exit(EXIT_FAILURE);
}

listADT newList( void ){
	return calloc(1, sizeof(struct listCDT));
}


int listIsEmpty( listADT list){
	return list->size == 0;
}

static int contains(nodeP first, elemType elem) {
	int c;

	if(first == NULL || (c=compare(first->value, elem)) > 0)
		return 0;
	
	if ( c == 0 )
		return 1;

	return contains( first->next, elem);
}

int elementBelongs( listADT list, elemType element){
	return contains(list->first, element);
}


static nodeP insertRec(nodeP first, elemType elem, int * added) {
	int c;
	if( first == NULL || (c=compare(first->value, elem)) > 0 ){
		nodeP aux = malloc(sizeof( struct node ));
		if (aux == NULL)
			Error("No hay lugar para otro nodo\n");
		aux->next = first;
		aux->value = elem;
		*added = 1;
		return aux;
	}
	if( c < 0 )
		first->next = insertRec( first->next, elem, added);
	return first;
}

int insert( listADT list, elemType element){
	/* Una mala solucion seria primero llamar a elementBelongs, y si retorna 1 no hacer nada porque ya pertenece
	 * a la lista. Y si retorna cero volver a recorrer para insertar */

	int added =0 ;
	list->first = insertRec(list->first, element, &added);
	if (added)
		list->size++;
	return added;
}

static nodeP delRec(nodeP first, elemType elem, int * res) {

	int c;
	if( first==NULL || (c=compare(first->value, elem)) > 0 )
		return first;

	if( c == 0 )
	{
		nodeP aux = first->next;
		free(first);
		*res = 1;
		return aux;
	}
	first->next = delRec(first->next, elem, res);
	return first;

}

int delete( listADT list, elemType element){
	int del=0;
	list->first = delRec(list->first, element, &del);
	if ( del )
		list->size--;
	return del;
}

void freeList( listADT list){
	nodeP curr=list->first, aux;

	while (curr != NULL) {
		aux = curr->next;
		free(curr);
		curr = aux;
	}
	free(list);
}

int listSize(const listADT list) {
	return list->size;
}

void toBegin(listADT list) {
	list->iteradorNext = list->first;
}

// iterador
int hasNext(const listADT list) {
	return list->iteradorNext != NULL;
}

elemType next(listADT list) {
	if (list->iteradorNext==NULL)
		Error("No hay mas elementos a recorrer");
	elemType ans = list->iteradorNext->value;
	list->iteradorNext = list->iteradorNext->next;

	return ans;
}
//---------- 

static elemType searchRec(nodeP first, int i){
	if(i==0){
		return first->value;
	}
	return searchRec(first->next, i-1);
}

elemType search(listADT list, int i){
	if(i>=list->size){
		exit(1);
	}
	return searchRec(list->first, i);
}

elemType get(listADT list, unsigned int idx){
 	int i;
 	nodeP auxi;
 	if ( idx >= list->size )
 		return NULL;
 	auxi = list->first;
 	for(i=0; i<idx; i++)
 		auxi = auxi->next;
 	return auxi->value;
}

static nodeP mapRec(nodeP first, elemType (*pFunc)(const elemType elem)){
	if(first==NULL){
		return NULL;
	}
	nodeP aux= malloc(sizeof(struct node));
	aux->value=(*pFunc)(first->value);
	aux->next=mapRec(first->next,pFunc);
	return aux;
}

void map(listADT list, elemType (*pFunc)(const elemType elem)){
	list->first=mapRec(list->first,pFunc);
	return;
}




int main(void){
	listADT list = newList();
	insert(list,0);
	insert(list,1);
	insert(list,2);
	insert(list,3);
	insert(list,4);
	insert(list,5);
	int i;
	for (i = 0; i < list->size; i++){
		printf("El elemento %d vale: %d\n", i + 1, search(list, i));
	}
	putchar('\n');
	map(list,doble);
	for (i = 0; i < list->size; i++){
		printf("El elemento %d vale: %d\n", i + 1, search(list, i));
	}
	return 0;
}