
#include <stdlib.h>
typedef struct vectorCDT * vectorADT;

typedef int elemType;

vectorADT newVector(void);
int put(vectorADT v, elemType * elems, size_t dim, size_t index);
int getIdx(vectorADT v, elemType elem);
void deleteElement(vectorADT v, size_t index);
int elementCount(vectorADT v);