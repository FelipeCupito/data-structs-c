// example_lista.c

#include <stdio.h>
#include "listaADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

// Función de comparación para enteros
int compararEnteros(void* a, void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    Lista* miLista = crearLista(destruirEntero);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarElemento(miLista, nuevoDato);
    }

    // Buscar y mostrar elementos
    for (int i = 0; i < 5; i++) {
        int* dato = (int*)buscarElemento(miLista, &i, compararEnteros);
        if (dato) {
            printf("Elemento encontrado: %d\n", *dato);
        } else {
            printf("Elemento no encontrado: %d\n", i);
        }
    }

    // Verificar tamaño y si está vacía
    printf("Tamaño de la lista: %d\n", tamanoLista(miLista));
    printf("¿Está vacía? %s\n", estaVaciaLista(miLista) ? "Sí" : "No");

    // Destruir lista
    destruirLista(miLista);

    return 0;
}
