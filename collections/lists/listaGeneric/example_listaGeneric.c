#include <stdio.h>
#include "listaGeneric.h"

// Función de comparación para enteros
int compararEnteros(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

// Función de impresión para enteros
void imprimirEntero(void* dato) {
    printf("%d\n", *(int*)dato);
}

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

int main() {
    
    Lista* miLista = crearLista(destruirEntero);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarElemento(miLista, nuevoDato);
    }

    // Imprimir lista
    printf("Lista inicial:\n");
    imprimirLista(miLista, imprimirEntero);

    // Buscar un elemento
    int buscado = 3;
    int* encontrado = (int*)buscarElemento(miLista, &buscado, compararEnteros);
    if (encontrado) {
        printf("Elemento %d encontrado.\n", *encontrado);
    } else {
        printf("Elemento %d no encontrado.\n", buscado);
    }

    // Eliminar un elemento
    eliminarElemento(miLista, &buscado, compararEnteros);
    printf("Lista después de eliminar %d:\n", buscado);
    imprimirLista(miLista, imprimirEntero);

    // Destruir lista
    destruirLista(miLista);

    return 0;
}
