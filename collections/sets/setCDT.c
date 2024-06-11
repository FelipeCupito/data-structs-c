#include <stdio.h>
#include <stdlib.h>
#include "setADT.h"

typedef struct node{
    struct node *tail;
    elemType head;
}node;

struct setCDT{
    node* first;
    size_t size;
};

static node * addRec(node* first, elemType elem, size_t * size);
static node * removeRec(node* first, elemType elem, size_t * size);
static node * intRec(node * n1, node * n2, setADT s);
static node * unionRec(node * n1, node * n2, setADT s);
static node * restaRec(node * n1, node * n2, size_t * size);
static int cmp(node * n1, node* n2);
void printList(setADT s);
void printRec(node * n);

setADT newSet(void){
    return calloc(1,sizeof(struct setCDT));
}

static node * addRec(node* first, elemType elem, size_t * size){
    int c;
    if(first == NULL||(c=compare(elem, first->head))<0){
        node * aux = malloc(sizeof(struct node));
        aux->head = elem;
        aux->tail = first;
        (*size)++;
        return aux;
    }
    if(c==0){
        return first;
    }
    first->tail = addRec(first->tail, elem, size);
    return first;
}

void addElem(setADT set, elemType elem){
    set->first = addRec(set->first, elem, &(set->size));
    return;
}

static node * removeRec(node* first, elemType elem, size_t * size){
    int c;
    if(first==NULL||(c=compare(elem, first->head))<0){
        return first;
    }
    if(c==0){
        node * aux = malloc(sizeof(struct node));
        aux = first->tail;
        free(first);
        (*size)--;
        return aux;
    }
    first->tail = removeRec(first->tail, elem, size);
    return first;
}

void removeElem(setADT set, elemType elem){
    set->first = removeRec(set->first, elem, &(set->size));
    return;
}

static int cmp(node * n1, node* n2){
    if(n1==NULL){
        return 1;
    }
    if(n2==NULL){
        return -1;
    }
    int c = compare(n1->head, n2->head);
    if(c<0){
        return -1;
    }
    if(c>0){
        return 1;
    }
    return 0;
}

static node * unionRec(node * n1, node * n2, setADT s){
    if(n1==NULL && n2==NULL){
        return NULL;
    }
    node * aux=malloc(sizeof(struct node));
    s->size++;
    int c = cmp(n1,n2);
    if(c==-1){
        aux->head = n1->head;
        aux->tail=unionRec(n1->tail, n2, s);
        return aux;
    }
    if(c==0){
        aux->head = n1->head;
        aux->tail = unionRec(n1->tail, n2->tail, s);
        return aux;
    }
    aux->head = n2->head;
    aux->tail = unionRec(n1, n2->tail,s);
    return aux;
}

setADT setUnion(setADT s1, setADT s2){
    setADT s=newSet();
    s->first=unionRec(s1->first,s2->first, s);
    return s;
}

static node * intRec(node * n1, node * n2, setADT s){
    if(n1==NULL||n2==NULL){
        return NULL;
    }
    int cmp=compare(n1->head, n2->head);
    if(cmp==0){
        node* aux = malloc(sizeof(node));
        aux->head=n1->head;
        aux->tail = intRec(n1->tail, n2->tail, s);
        s->size++;
        return aux;
    }
    if(cmp<0){
        return intRec(n1->tail, n2, s);
    }
    return intRec(n1, n2->tail,s);
}

setADT setInter(setADT s1, setADT s2){
    setADT s=newSet();
    s->first=intRec(s1->first,s2->first, s);
    return s;
}

static node * restaRec(node * n1, node * n2, size_t * size){
    if(n1==NULL){
        return NULL;
    }
    if(n2==NULL){
        return n1;
    }
    int cmp=compare(n1->head, n2->head);
    if(cmp<0){
        return restaRec(n1->tail,n2,size);
    }
    if(cmp>0){
        return restaRec(n1, n2->tail, size);
    }
    node* aux = n1->tail;
    n1=aux;
    free(aux);
    (*size)--;
    n1 = restaRec(n1,n2->tail,size);
    return n1;
}

setADT setResta(setADT s1, setADT s2){
    setADT s = s1;
    s->first = restaRec(s->first, s2->first, &(s->size));
    return s;
}

void printRec(node * n){
    if(n==NULL){
        printf("NULL");
        return;
    }
    printf("%d ->", n->head);
    printRec(n->tail);
}

void printList(setADT s){
    printRec(s->first);
}

int main(void){
    setADT s1 = newSet();
    addElem(s1,1);
    addElem(s1,2);
    addElem(s1,5);
    addElem(s1,4);
    addElem(s1,9);
    addElem(s1,10);
    printList(s1);
    putchar('\n');
    setADT s2 = newSet();
    addElem(s2,2);
    addElem(s2,3);
    addElem(s2,6);
    addElem(s2,7);
    addElem(s2,9);
    printList(s2);
    putchar('\n');
    setADT s1Us2 = setUnion(s1,s2);
    printf("Union\n");
    printList(s1Us2);
    putchar('\n');
    setADT inter = setInter(s1,s2);
    printf("Interseccion\n");
    printList(inter);
    putchar('\n');
    setADT resta = setResta(s1,s2);
    printf("Resta\n");
    printList(resta);
    putchar('\n');
    // removeElem(s1,11);
    // printList(s1);
    // putchar('\n');
    // removeElem(s2,3);
    // printList(s2);
    // putchar('\n');
    return 0;
}
