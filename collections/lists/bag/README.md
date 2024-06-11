# Bag (Bolsa) Genérico

Esta es una implementación de una bolsa genérica (bag) en C. La bolsa permite almacenar cualquier tipo de dato usando punteros void y proporciona funciones para crear, destruir, agregar y obtener elementos, así como verificar el tamaño y si está vacía.

## Archivos

- `bagADT.h`: Archivo de encabezado que define la estructura y los prototipos de funciones.
- `bagCDT.c`: Archivo de implementación que contiene las funciones definidas en el encabezado.

## Funciones

- **crearBag**: Crea una nueva bolsa con una capacidad inicial.
- **destruirBag**: Destruye la bolsa y libera la memoria.
- **agregarBag**: Agrega un elemento a la bolsa.
- **obtenerBag**: Obtiene un elemento de la bolsa (sin eliminarlo).
- **tamanoBag**: Obtiene el tamaño actual de la bolsa.
- **estaVacioBag**: Verifica si la bolsa está vacía.

## Uso

### Crear una bolsa

```c
Bag* miBag = crearBag(10, miDestructor);
```

### Agregar un elemento

```c
int* miDato = (int*)malloc(sizeof(int));
*miDato = 42;
agregarBag(miBag, miDato);
```

### Obtener un elemento

```c
int* dato = (int*)obtenerBag(miBag);
```

### Verificar tamaño y si está vacía

```c
int tamano = tamanoBag(miBag);
int vacio = estaVacioBag(miBag);
```

### Destruir la bolsa

```c
destruirBag(miBag);
```