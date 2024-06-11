// set_test.c

#include <assert.h>
#include "setADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

// Función de comparación para enteros
int compararEnteros(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

void testConjunto() {
    Conjunto* miConjunto = crearConjunto(destruirEntero, compararEnteros);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarConjunto(miConjunto, nuevoDato);
    }

    // Verificar tamaño
    assert(tamanoConjunto(miConjunto) == 5);

    // Verificar y eliminar elementos
    for (int i = 0; i < 5; i++) {
        int* dato = (int*)malloc(sizeof(int));
        *dato = i;
        assert(contieneConjunto(miConjunto, dato));
        eliminarConjunto(miConjunto, dato);
        assert(!contieneConjunto(miConjunto, dato));
        free(dato);
    }

    // Verificar si está vacío
    assert(tamanoConjunto(miConjunto) == 0);

    // Destruir conjunto
    destruirConjunto(miConjunto);
}

int main() {
    testConjunto();
    printf("Todos los tests pasaron exitosamente.\n");
    return 0;
}
