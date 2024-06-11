// bag_test.c

#include <assert.h>
#include "bagADT.h"

// Función de destrucción para enteros
void destruirEntero(void* dato) {
    free(dato);
}

void testBag() {
    Bag* miBag = crearBag(10, destruirEntero);

    // Agregar elementos
    for (int i = 0; i < 5; i++) {
        int* nuevoDato = (int*)malloc(sizeof(int));
        *nuevoDato = i;
        agregarBag(miBag, nuevoDato);
    }

    // Verificar tamaño
    assert(tamanoBag(miBag) == 5);

    // Obtener y verificar elementos
    for (int i = 4; i >= 0; i--) {
        int* dato = (int*)obtenerBag(miBag);
        assert(dato && *dato == i);
    }

    // Verificar si está vacía
    assert(!estaVacioBag(miBag));

    // Destruir bolsa
    destruirBag(miBag);
}

int main() {
    testBag();
    printf("Todos los tests pasaron exitosamente.\n");
    return 0;
}
