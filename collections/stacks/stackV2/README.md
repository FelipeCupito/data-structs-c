# Pila Genérica v2

Esta es una versión mejorada de la implementación de una pila genérica en C. La pila permite almacenar cualquier tipo de dato usando punteros void y proporciona funciones para crear, destruir, apilar y desapilar elementos, así como verificar el tamaño y si está vacía.

## Archivos

- `stackADTv2.h`: Archivo de encabezado que define la estructura y los prototipos de funciones.
- `stackADTv2.c`: Archivo de implementación que contiene las funciones definidas en el encabezado.

## Funciones

- **crearPila**: Crea una nueva pila.
- **destruirPila**: Destruye la pila y libera la memoria.
- **apilar**: Agrega un elemento a la pila.
- **desapilar**: Elimina y obtiene el elemento del tope de la pila.
- **topePila**: Obtiene el elemento del tope de la pila sin eliminarlo.
- **tamanoPila**: Obtiene el tamaño actual de la pila.
- **estaVaciaPila**: Verifica si la pila está vacía.

## Uso

Consulta el archivo `example_stackv2.c` para ver un ejemplo completo de uso.

## Pruebas

Consulta el archivo `stack_testv2.c` para ver pruebas unitarias de la implementación.
