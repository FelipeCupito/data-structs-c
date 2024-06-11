#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct conjCDT* conjADT;

/*Devuelve -1 si es menor, 0 si son iguales, 1 si es mayor*/
conjADT createConj(size_t bytes, int (*cmp) (void* e1, void* e2));

void deleteConj(conjADT c);

void addConj(conjADT c, void* elem);

conjADT unionConj(conjADT c1, conjADT c2);

conjADT interConj(conjADT c1, conjADT c2);

conjADT diffConj(conjADT c1, conjADT c2);

void printList(conjADT c,void (*print)(void* n));