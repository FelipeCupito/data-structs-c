# Lista Genérica

Esta es una implementación de una lista genérica en C. La lista permite almacenar cualquier tipo de dato usando punteros void y proporciona funciones para crear, destruir, agregar y eliminar elementos, así como verificar el tamaño y si está vacía.

## Archivos

- `listaADT.h`: Archivo de encabezado que define la estructura y los prototipos de funciones.
- `listaCDT.c`: Archivo de implementación que contiene las funciones definidas en el encabezado.

## Funciones

- **crearLista**: Crea una nueva lista.
- **destruirLista**: Destruye la lista y libera la memoria.
- **agregarElemento**: Agrega un elemento a la lista.
- **eliminarElemento**: Elimina un elemento de la lista.
- **buscarElemento**: Busca un elemento en la lista.
- **tamanoLista**: Obtiene el tamaño actual de la lista.
- **estaVaciaLista**: Verifica si la lista está vacía.

## Uso

Consulta el archivo `example_lista.c` para ver un ejemplo completo de uso.

## Pruebas

Consulta el archivo `lista_test.c` para ver pruebas unitarias de la implementación.
