#include "stdio.h"
#include "listaGeneric.h"

typedef struct node{

    void * elem;
    void * next;
}node;

typedef struct conjCDT{
    node* first;
    size_t bytes;
    int (*cmp) (void* e1, void* e2);

}conjCDT;

static void deleteNode(node* n);
static node* addElem(node* n, void* elem, int (*cmp) (void* e1, void* e2), size_t  bytes);
static node* unionNode(node* n1, node* n2, int (*cmp) (void* e1, void* e2), size_t bytes);
static node* interNode(node* n1, node* n2, int (*cmp) (void* e1, void* e2), size_t bytes);
static node* diffNode(node* n1, node* n2, int (*cmp) (void* e1, void* e2), size_t bytes);
static void printRec(node* n,void (*print)(void* n));

conjADT createConj(size_t bytes, int (*cmp) (void* e1, void* e2)){

    conjADT newconj;

    newconj=malloc(sizeof(*newconj));
    newconj->bytes=bytes;
    newconj->cmp = cmp;
    newconj->first=NULL;

    return newconj;

}

void deleteConj(conjADT c){

    deleteNode(c->first);
    free(c);

}

static void deleteNode(node* n){


    if(n == NULL)
        return;

    deleteNode(n->next);


    free(n->elem);
    free(n);

}

void addConj(conjADT c,void* elem){
    c->first=addElem(c->first,elem,c->cmp,c->bytes);
}

static node* addElem(node* n, void* elem, int (*cmp) (void* e1, void* e2), size_t  bytes){

    int ans;
    node* nNew;

    if(n==NULL){
        nNew=malloc(sizeof(*nNew));
        nNew->elem=malloc(bytes);
        memcpy(nNew->elem,elem,bytes);
        nNew->next=NULL;
        return nNew;
    }else{

        ans=cmp(elem,n->elem);

        if(ans<0){
            nNew=malloc(sizeof(*nNew));
            nNew->elem=malloc(bytes);
            memcpy(nNew->elem,elem,bytes);
            nNew->next=n;
            return nNew;
        }else{
            if(ans>0)
            n->next=addElem(n->next, elem, cmp,bytes);

        return n;

        }
    }

    return nNew;


}

conjADT unionConj(conjADT c1, conjADT c2){

    conjADT unionc;

    unionc=malloc(sizeof(*unionc));
    unionc->bytes=c1->bytes;
    unionc->cmp=c1->cmp;
    unionc->first=unionNode(c1->first,c2->first,unionc->cmp,unionc->bytes);

    return unionc;

}

static node* unionNode(node* n1, node* n2, int (*cmp) (void* e1, void* e2), size_t bytes){

    node* nNew;
    int ans;


    if(n1==NULL && n2==NULL)
        return NULL;

    nNew=malloc(sizeof(*nNew));
    nNew->elem=malloc(bytes);

    if(n1==NULL){
        memcpy(nNew->elem, n2->elem,bytes);
        nNew->next=unionNode(n1,n2->next,cmp,bytes);
        return nNew;
    }

    if(n2==NULL){
        memcpy(nNew->elem, n1->elem,bytes);
        nNew->next=unionNode(n1->next,n2,cmp,bytes);
        return nNew;
    }

    ans=cmp(n1->elem,n2->elem);

    if(ans==0){
        memcpy(nNew->elem, n1->elem,bytes);
        nNew->next=unionNode(n1->next,n2->next,cmp,bytes);
     }else if(ans>0){
        memcpy(nNew->elem, n2->elem,bytes);
        nNew->next=unionNode(n1,n2->next,cmp,bytes);

    }else{
        memcpy(nNew->elem, n1->elem,bytes);
        nNew->next=unionNode(n1->next,n2,cmp,bytes);
    }

    return nNew;




}

conjADT interConj(conjADT c1, conjADT c2){
    conjADT interc;

    interc=malloc(sizeof(*interc));
    interc->bytes=c1->bytes;
    interc->cmp=c1->cmp;
    interc->first=interNode(c1->first,c2->first,c1->cmp,c1->bytes);

    return interc;
}

static node* interNode(node* n1, node* n2, int (*cmp) (void* e1, void* e2), size_t bytes){

    node* nNew;
    int ans;

    if(n1==NULL || n2== NULL)
        return NULL;



    ans=cmp(n1->elem,n2->elem);

    if(ans==0){
        nNew=malloc(sizeof(*nNew));
        nNew->elem=malloc(bytes);
        memcpy(nNew->elem,n1->elem,bytes);
        nNew->next=interNode(n1->next,n2->next,cmp,bytes);
    }

    if(ans>0){
        nNew=interNode(n1,n2->next,cmp,bytes);
    }

    if(ans<0){
        nNew=interNode(n1->next,n2,cmp,bytes);
    }

    return nNew;

}

conjADT diffConj(conjADT c1, conjADT c2){

    conjADT diffc;

    diffc=malloc(sizeof(*diffc));
    diffc->bytes=c1->bytes;
    diffc->cmp=c1->cmp;
    diffc->first=diffNode(c1->first,c2->first,c1->cmp,c1->bytes);

    return diffc;

}

static node* diffNode(node* n1, node* n2, int (*cmp) (void* e1, void* e2), size_t bytes){

    node* nNew;
    int ans;

    if(n1==NULL)
        return NULL;

    if(n2==NULL){
        nNew=malloc(sizeof(*nNew));
        nNew->elem=malloc(bytes);
        memcpy(nNew->elem,n1->elem,bytes);
        nNew->next=diffNode(n1->next,n2,cmp,bytes);
        return nNew;
    }

    ans=cmp(n1->elem,n2->elem);

    if(ans==0){
        nNew=diffNode(n1->next,n2->next,cmp,bytes);
    }

    if(ans>0){
        nNew=diffNode(n1,n2->next,cmp,bytes);
    }

    if(ans<0){
        nNew=malloc(sizeof(*nNew));
        nNew->elem=malloc(bytes);
        memcpy(nNew->elem,n1->elem,bytes);
        nNew->next=diffNode(n1->next,n2,cmp,bytes);
    }

    return nNew;

}

void printList(conjADT c,void (*print)(void* n)){
    printRec(c->first,print);
}

static void printRec(node* n,void (*print)(void* n)){

    if(n==NULL)
        return;

    print(n->elem);
    printRec(n->next,print);
}