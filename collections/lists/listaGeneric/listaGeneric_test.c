// listaGeneric_test.c

#include <assert.h>
#include "listaGeneric.h"

// Función de comparación para enteros
int compararEnteros(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

void testListaGeneric() {
    Lista* miLista = crearLista(destruirEntero);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarElemento(miLista, nuevoDato);
    }

    // Verificar tamaño
    assert(miLista->tamano == 5);

    // Buscar un elemento
    int buscado = 3;
    int* encontrado = (int*)buscarElemento(miLista, &buscado, compararEnteros);
    assert(encontrado && *encontrado == 3);

    // Eliminar un elemento
    eliminarElemento(miLista, &buscado, compararEnteros);
    assert(miLista->tamano == 4);

    // Verificar eliminación
    encontrado = (int*)buscarElemento(miLista, &buscado, compararEnteros);
    assert(encontrado == NULL);

    // Destruir lista
    destruirLista(miLista);
}

int main() {
    testListaGeneric();
    printf("Todos los tests pasaron exitosamente.\n");
    return 0;
}
