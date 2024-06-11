// example_stackv2.c

#include <stdio.h>
#include "stackADTv2.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

int main() {
    Pila* miPila = crearPila(destruirEntero);

    // Apilar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        apilar(miPila, nuevoDato);
    }

    // Obtener y mostrar elementos
    while (!estaVaciaPila(miPila)) {
        int* dato = (int*)desapilar(miPila);
        if (dato) {
            printf("Elemento desapilado: %d\n", *dato);
        }
    }

    // Verificar tamaño y si está vacía
    printf("Tamaño de la pila: %d\n", tamanoPila(miPila));
    printf("¿Está vacía? %s\n", estaVaciaPila(miPila) ? "Sí" : "No");

    // Destruir pila
    destruirPila(miPila);

    return 0;
}
