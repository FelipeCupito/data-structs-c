# Matriz Genérica

Esta es una implementación de una matriz genérica en C. La matriz permite almacenar cualquier tipo de dato usando punteros void y proporciona funciones para crear, destruir, establecer y obtener elementos, así como verificar el tamaño.

## Archivos

- `matrixADT.h`: Archivo de encabezado que define la estructura y los prototipos de funciones.
- `matrixCDT.c`: Archivo de implementación que contiene las funciones definidas en el encabezado.

## Funciones

- **crearMatriz**: Crea una nueva matriz con filas y columnas especificadas.
- **destruirMatriz**: Destruye la matriz y libera la memoria.
- **establecerElemento**: Establece un elemento en una posición específica.
- **obtenerElemento**: Obtiene un elemento de una posición específica.
- **filasMatriz**: Obtiene el número de filas de la matriz.
- **columnasMatriz**: Obtiene el número de columnas de la matriz.

## Uso

Consulta el archivo `example_matrix.c` para ver un ejemplo completo de uso.

## Pruebas

Consulta el archivo `matrix_test.c` para ver pruebas unitarias de la implementación.
