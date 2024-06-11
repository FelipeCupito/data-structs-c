#ifndef SETADT_H_
#define SETADT_H_

typedef int elemType;

typedef struct setCDT* setADT;

void addElem(setADT set, elemType elem);

void removeElem(setADT set, elemType elem);

setADT setUnion(setADT s1, setADT s2);

setADT setInter(setADT s1, setADT s2);

setADT setResta(setADT s1, setADT s2);

setADT newSet(void);

elemType compare(elemType e1, elemType e2){
    return e1-e2;
}

#endif

