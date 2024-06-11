// example_queue.c

#include <stdio.h>
#include "queueADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

int main() {
    Cola* miCola = crearCola(destruirEntero);

    // Encolar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        encolar(miCola, nuevoDato);
    }

    // Obtener y mostrar elementos
    while (!estaVaciaCola(miCola)) {
        int* dato = (int*)desencolar(miCola);
        if (dato) {
            printf("Elemento desencolado: %d\n", *dato);
        }
    }

    // Verificar tamaño y si está vacía
    printf("Tamaño de la cola: %d\n", tamanoCola(miCola));
    printf("¿Está vacía? %s\n", estaVaciaCola(miCola) ? "Sí" : "No");

    // Destruir cola
    destruirCola(miCola);

    return 0;
}
