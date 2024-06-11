// example_matrix.c

#include <stdio.h>
#include "matrixADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

int main() {
    Matriz* miMatriz = crearMatriz(3, 3, destruirEntero);

    // Establecer elementos
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int* nuevoDato = (int*)malloc(sizeof(int));
            *nuevoDato = i * 3 + j;
            establecerElemento(miMatriz, i, j, nuevoDato);
        }
    }

    // Obtener y mostrar elementos
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int* dato = (int*)obtenerElemento(miMatriz, i, j);
            if (dato) {
                printf("Elemento en la posición (%d, %d): %d\n", i, j, *dato);
            }
        }
    }

    // Verificar tamaño
    printf("Filas de la matriz: %d\n", filasMatriz(miMatriz));
    printf("Columnas de la matriz: %d\n", columnasMatriz(miMatriz));

    // Destruir matriz
    destruirMatriz(miMatriz);

    return 0;
}
