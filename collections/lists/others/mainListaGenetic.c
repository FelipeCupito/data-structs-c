#include "listaGeneric.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

int compareint(void* n1, void* n2);
void printInt(void* n1);
void printChar(void *c);
int comparechar(void* n1, void* n2);
int comparedouble(double* n1, double* n2);
void printDouble(void *c);
void printName(void *c);
int comparestrings(void* n1, void* n2);

int main(){
    srand(time(0));
    conjADT listA;
    conjADT listB;
    conjADT listC;
    conjADT listD;
    conjADT listN;
    conjADT listN2;
    conjADT listNUNION;
    conjADT listUNION;
    conjADT listINTER;
    conjADT listREST;

    char* auxname;
    char aux,i;
    int auxint;
    double auxdouble;

   printf("\n--------CHARACTERES A------------\n");

    listA=createConj(sizeof(char),comparechar);

    for(i=0;i<15;i++){
    aux=rand()%26+'A';
    addConj(listA,&aux);
    }

    printList(listA,printChar);


    printf("\n--------CHARACTERES B------------\n");

    listC=createConj(sizeof(char),comparechar);

    for(i=0;i<15;i++){
    aux=rand()%26+'A';
    addConj(listC,&aux);
    }
    printList(listC,printChar);



    printf("\n----------UNION----------\n");

    listUNION=unionConj(listA,listC);

    printList(listUNION,printChar);

    printf("\n----------INTERSECCION----------\n");


    listINTER=interConj(listA,listC);

    printList(listINTER,printChar);

    printf("\n----------DIFERENCIA----------\n");


    listREST=diffConj(listA,listC);

    printList(listREST,printChar);


    printf("\n---------ENTEROS-----------\n");

    listB=createConj(sizeof(int),compareint);

    for(i=0;i<15;i++){
    auxint=rand()%50-25;
    addConj(listB,&auxint);
    }
    printList(listB,printInt);

    printf("\n------DOUBLES------------\n");

    listD=createConj(sizeof(double),(int(*)(void*,void*))comparedouble);

    for(i=0;i<15;i++){
    auxdouble=(rand()%500-250)/7.0;
    addConj(listD,&auxdouble);
    }


    printList(listD,printDouble);

    printf("\n------NOMBRES------------\n");

    listN=createConj(sizeof(char*),comparestrings);

    char* names[]={"JUAN","FRANCO","CARACCIOLO","HOLA","ADIOS","tortilla","jamon","Ubuntu","razer","COMIDA","PI","a veces","chau"};
    for(i=0;i<9;i++){
    auxname=names[rand()%13];
    addConj(listN,&auxname);
    }

    printList(listN,printName);


    printf("\n------NOMBRES 2------------\n");

    listN2=createConj(sizeof(char*),comparestrings);

    for(i=0;i<9;i++){
    auxname=names[rand()%13];
    addConj(listN2,&auxname);
    }

    printList(listN2,printName);

     printf("\n----------NOMBRES inter----------\n");

    listNUNION=interConj(listN,listN2);

    printList(listNUNION,printName);


/*
    conjADT listA;
    conjADT listB;
    conjADT listC;
    conjADT listD;
    conjADT listN;
    conjADT listN2;
    conjADT listNUNION;
    conjADT listUNION;
    conjADT listINTER;
    conjADT listREST;
*//*
    deleteConj(listA);
    deleteConj(listB);
    deleteConj(listC);
    deleteConj(listD);
    deleteConj(listN);
    deleteConj(listN2);
    deleteConj(listNUNION);
    deleteConj(listUNION);
    deleteConj(listINTER);
    deleteConj(listREST);
*/

 return 0;
}


int comparechar(void* n1, void* n2){

    return *((char*)n1) - *((char*)n2);
}


int comparestrings(void* n1, void* n2){

    return strcmp(*((char**)n1),*((char**)n2));
}


int comparedouble(double* n1, double* n2){

    return *n1 - *n2;
}

int compareint(void* n1, void* n2){

    return *((int*)n1) - *((int*)n2);
}

void printDouble(void *c){

    printf("**%f**\n",*((double*)c));
}
void printName(void *c){

    printf("**%s**\n",*((char**)c));
}


void printChar(void *c){

    printf("**%c**\n",*((char*)c));
}
void printInt(void* n1){

    printf("||%d||\n",*((int*)n1));
}