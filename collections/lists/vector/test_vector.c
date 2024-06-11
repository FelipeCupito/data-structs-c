// vector_test.c

#include <assert.h>
#include "vectorADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

void testVector() {
    Vector* miVector = crearVector(10, destruirEntero);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarVector(miVector, nuevoDato);
    }

    // Verificar tamaño
    assert(tamanoVector(miVector) == 5);

    // Obtener y verificar elementos
    for (int i = 0; i < 5; i++) {
        int* dato = (int*)obtenerVector(miVector, i);
        assert(dato && *dato == i);
    }

    // Eliminar un elemento y verificar tamaño
    eliminarVector(miVector, 2);
    assert(tamanoVector(miVector) == 4);

    // Destruir vector
    destruirVector(miVector);
}

int main() {
    testVector();
    printf("Todos los tests pasaron exitosamente.\n");
    return 0;
}
