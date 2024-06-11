// stack_testv2.c

#include <assert.h>
#include "stackADTv2.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

void testPila() {
    Pila* miPila = crearPila(destruirEntero);

    // Apilar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        apilar(miPila, nuevoDato);
    }

    // Verificar tamaño
    assert(tamanoPila(miPila) == 5);

    // Desapilar y verificar elementos
    for (int i = 4; i >= 0; i--) {
        int* dato = (int*)desapilar(miPila);
        assert(dato && *dato == i);
    }

    // Verificar si está vacía
    assert(estaVaciaPila(miPila));

    // Destruir pila
    destruirPila(miPila);
}

int main() {
    testPila();
    printf("Todos los tests pasaron exitosamente.\n");
    return 0;
}
