# Cola Genérica v2

Esta es una versión mejorada de la implementación de una cola genérica en C. La cola permite almacenar cualquier tipo de dato usando punteros void y proporciona funciones para crear, destruir, encolar y desencolar elementos, así como verificar el tamaño y si está vacía.

## Archivos

- `queueADTv2.h`: Archivo de encabezado que define la estructura y los prototipos de funciones.
- `queueCDTv2.c`: Archivo de implementación que contiene las funciones definidas en el encabezado.

## Funciones

- **crearCola**: Crea una nueva cola.
- **destruirCola**: Destruye la cola y libera la memoria.
- **encolar**: Agrega un elemento a la cola.
- **desencolar**: Elimina y obtiene el elemento del frente de la cola.
- **frenteCola**: Obtiene el elemento del frente de la cola sin eliminarlo.
- **tamanoCola**: Obtiene el tamaño actual de la cola.
- **estaVaciaCola**: Verifica si la cola está vacía.

## Uso

Consulta el archivo `example_queuev2.c` para ver un ejemplo completo de uso.

## Pruebas

Consulta el archivo `queue_testv2.c` para ver pruebas unitarias de la implementación.
