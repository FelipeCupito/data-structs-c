// queue_test.c

#include <assert.h>
#include "queueADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

void testCola() {
    Cola* miCola = crearCola(destruirEntero);

    // Encolar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        encolar(miCola, nuevoDato);
    }

    // Verificar tamaño
    assert(tamanoCola(miCola) == 5);

    // Desencolar y verificar elementos
    for (int i = 0; i < 5; i++) {
        int* dato = (int*)desencolar(miCola);
        assert(dato && *dato == i);
    }

    // Verificar si está vacía
    assert(estaVaciaCola(miCola));

    // Destruir cola
    destruirCola(miCola);
}

int main() {
    testCola();
    printf("Todos los tests pasaron exitosamente.\n");
    return 0;
}
