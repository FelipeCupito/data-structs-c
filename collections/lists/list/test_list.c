// lista_test.c

#include <assert.h>
#include "listaADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

// Función de comparación para enteros
int compararEnteros(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

void testLista() {
    Lista* miLista = crearLista(destruirEntero);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarElemento(miLista, nuevoDato);
    }

    // Verificar tamaño
    assert(tamanoLista(miLista) == 5);

    // Buscar y verificar elementos
    for (int i = 0; i < 5; i++) {
        int* dato = (int*)buscarElemento(miLista, &i, compararEnteros);
        assert(dato && *dato == i);
    }

    // Eliminar un elemento y verificar tamaño
    int elementoAEliminar = 2;
    eliminarElemento(miLista, &elementoAEliminar, compararEnteros);
    assert(tamanoLista(miLista) == 4);

    // Verificar si está vacía
    assert(!estaVaciaLista(miLista));

    // Destruir lista
    destruirLista(miLista);
}

int main() {
    testLista();
    printf("Todos los tests pasaron exitosamente.\n");
    return 0;
}
