// example_vector.c

#include <stdio.h>
#include "vectorADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

int main() {
    Vector* miVector = crearVector(10, destruirEntero);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarVector(miVector, nuevoDato);
    }

    // Obtener y mostrar elementos
    for (int i = 0; i < 5; i++) {
        int* dato = (int*)obtenerVector(miVector, i);
        if (dato) {
            printf("Elemento en el índice %d: %d\n", i, *dato);
        }
    }

    // Verificar tamaño y capacidad
    printf("Tamaño del vector: %d\n", tamanoVector(miVector));
    printf("Capacidad del vector: %d\n", capacidadVector(miVector));

    // Destruir vector
    destruirVector(miVector);

    return 0;
}
