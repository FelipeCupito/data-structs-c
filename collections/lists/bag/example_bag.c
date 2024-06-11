// example_bag.c

#include <stdio.h>
#include "bagADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

int main() {
    Bag* miBag = crearBag(10, destruirEntero);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarBag(miBag, nuevoDato);
    }

    // Obtener y mostrar elementos
    for (int i = 0; i < 5; i++) {
        int* dato = (int*)obtenerBag(miBag);
        if (dato) {
            printf("Elemento obtenido: %d\n", *dato);
        }
    }

    // Verificar tamaño y si está vacía
    printf("Tamaño de la bolsa: %d\n", tamanoBag(miBag));
    printf("¿Está vacía? %s\n", estaVacioBag(miBag) ? "Sí" : "No");

    // Destruir bolsa
    destruirBag(miBag);

    return 0;
}
