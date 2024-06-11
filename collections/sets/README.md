# Conjunto Genérico

Esta es una implementación de un conjunto genérico en C. El conjunto permite almacenar cualquier tipo de dato usando punteros void y proporciona funciones para crear, destruir, agregar y eliminar elementos, así como verificar si un elemento está en el conjunto y obtener el tamaño.

## Archivos

- `setADT.h`: Archivo de encabezado que define la estructura y los prototipos de funciones.
- `setCDT.c`: Archivo de implementación que contiene las funciones definidas en el encabezado.

## Funciones

- **crearConjunto**: Crea un nuevo conjunto.
- **destruirConjunto**: Destruye el conjunto y libera la memoria.
- **agregarConjunto**: Agrega un elemento al conjunto.
- **eliminarConjunto**: Elimina un elemento del conjunto.
- **contieneConjunto**: Verifica si un elemento está en el conjunto.
- **tamanoConjunto**: Obtiene el tamaño actual del conjunto.

## Uso

Consulta el archivo `example_set.c` para ver un ejemplo completo de uso.

## Pruebas

Consulta el archivo `set_test.c` para ver pruebas unitarias de la implementación.
