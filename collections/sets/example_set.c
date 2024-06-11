// example_set.c

#include <stdio.h>
#include "setADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

// Función de comparación para enteros
int compararEnteros(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    Conjunto* miConjunto = crearConjunto(destruirEntero, compararEnteros);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarConjunto(miConjunto, nuevoDato);
    }

    // Verificar y mostrar elementos
    for (int i = 0; i < 5; i++) {
        int* dato = (int*)malloc(sizeof(int));
        *dato = i;
        if (contieneConjunto(miConjunto, dato)) {
            printf("El conjunto contiene: %d\n", *dato);
        } else {
            printf("El conjunto no contiene: %d\n", *dato);
        }
        free(dato);
    }

    // Verificar tamaño
    printf("Tamaño del conjunto: %d\n", tamanoConjunto(miConjunto));

    // Destruir conjunto
    destruirConjunto(miConjunto);

    return 0;
}
