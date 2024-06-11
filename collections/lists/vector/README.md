# Vector Genérico

Esta es una implementación de un vector genérico en C. El vector permite almacenar cualquier tipo de dato usando punteros void y proporciona funciones para crear, destruir, agregar, obtener y eliminar elementos, así como verificar el tamaño y la capacidad.

## Archivos

- `vectorADT.h`: Archivo de encabezado que define la estructura y los prototipos de funciones.
- `vectorCDT.c`: Archivo de implementación que contiene las funciones definidas en el encabezado.

## Funciones

- **crearVector**: Crea un nuevo vector con una capacidad inicial.
- **destruirVector**: Destruye el vector y libera la memoria.
- **agregarVector**: Agrega un elemento al vector.
- **obtenerVector**: Obtiene un elemento del vector por su índice.
- **eliminarVector**: Elimina un elemento del vector por su índice.
- **tamanoVector**: Obtiene el tamaño actual del vector.
- **capacidadVector**: Obtiene la capacidad actual del vector.

## Uso

Consulta el archivo `example_vector.c` para ver un ejemplo completo de uso.

## Pruebas

Consulta el archivo `vector_test.c` para ver pruebas unitarias de la implementación.
