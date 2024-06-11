// bagADT.h

#ifndef BAGADT_H
#define BAGADT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Bag {
    void** items;
    int capacity;
    int size;
    void (*destructor)(void*);
} Bag;

// Prototipos de funciones
Bag* crearBag(int capacity, void (*destructor)(void*));
void destruirBag(Bag* bag);
void agregarElementoBag(Bag* bag, void* item);
void* obtenerElementoBag(Bag* bag, int index);
void eliminarElementoBag(Bag* bag, void* item, int (*comparador)(void*, void*));
int tamanoBag(Bag* bag);
void imprimirBag(Bag* bag, void (*impresor)(void*));

#endif // BAGADT_H
