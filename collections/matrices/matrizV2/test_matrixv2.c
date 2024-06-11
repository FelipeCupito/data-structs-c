// matrix_testv2.c

#include <assert.h>
#include "matrixADTv2.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

void testMatriz() {
    Matriz* miMatriz = crearMatriz(3, 3, destruirEntero);

    // Establecer elementos
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int* nuevoDato = (int*)malloc(sizeof(int));
            *nuevoDato = i * 3 + j;
            establecerElemento(miMatriz, i, j, nuevoDato);
        }
    }

    // Verificar elementos
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int* dato = (int*)obtenerElemento(miMatriz, i, j);
            assert(dato && *dato == i * 3 + j);
        }
    }

    // Verificar tamaño
    assert(filasMatriz(miMatriz) == 3);
    assert(columnasMatriz(miMatriz) == 3);

    // Destruir matriz
    destruirMatriz(miMatriz);
}

int main() {
    testMatriz();
    printf("Todos los tests pasaron exitosamente.\n");
    return 0;
}
