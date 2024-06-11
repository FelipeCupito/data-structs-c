typedef struct queueCDT * queueADT;

typedef int elementType;

queueADT newQueue(void);

// Agrega un elemento al final de la cola
// Retorna 1 si lo pudo agregar, 0 sino.
int queue(queueADT q, elementType n);

// Remueve un elemento del principio de la cola y lo deja en out
// Retorna 1 si lo pudo remover, 0 sino.
int dequeue(queueADT q, elementType * out);

void freeQueue(queueADT q);

int isEmpty(queueADT q);

/* Iterador */
void toBegin(queueADT q);

int hasNext(queueADT q);

elementType next(queueADT q);