#include <stdio.h>
#include <stdlib.h>
#include "matrixADT.h"

struct matrixCDT {
	struct tFila * filas;
	int dim;
};

struct tFila {
	elementType * elems; // Arreglo dinÃ¡mico de elementos
	char * occupied; // Arreglo dinÃ¡mico para posiciones ocupadas
	int dim; // DimensiÃ³n de los arreglos
};

matrixADT
newMatrix() {
	return calloc(1, sizeof(struct matrixCDT));
}

size_t 
rows(matrixADT m) {
	return m->dim;
}

int 
getElement(matrixADT m, size_t row, size_t col, elementType * out) {
	if(row <= 0 || col <= 0) {
		return 0;
	}
	row--;
	col--;
	// Si la fila row no existe o es vacÃ­a
	if(row > rows(m) || m->filas[row].dim == 0) {
		return 0;
	}
	// Si la columna col no existe o es vacÃ­a
	if(col > m->filas[row].dim || m->filas[row].occupied[col] == 0) {
		return 0;
	}
	// El elemento en la posiciÃ³n m[row][col] existe
	*out = m->filas[row].elems[col];
	return 1;
}

int 
setElement(matrixADT m, size_t row, size_t col, elementType elem) {
	if(row <= 0 || col <= 0) {
		return 0;
	}
	row--;
	col--;
	// La fila row no existe
	if(row >= rows(m)) {
		m->filas = realloc(m->filas, (row + 1) * sizeof(struct tFila));
		for(int i = rows(m); i <= row; i++) {
			m->filas[i].elems = NULL;
			m->filas[i].occupied = NULL;
			m->filas[i].dim = 0;
		} 
		m->dim = row + 1;
	}
	// La columna col no existe
	if(col >= m->filas[row].dim) {
		m->filas[row].elems = realloc(m->filas[row].elems, (col + 1) * sizeof(elementType));
		m->filas[row].occupied = realloc(m->filas[row].occupied, (col + 1) * sizeof(char));
		// Seteo con 0 las nuevas posiciones para indicar que estÃ¡n vacÃ­as
		for(int i = m->filas[row].dim; i <= col; i++) {
			m->filas[row].occupied[i] = 0;
		}
		m->filas[row].dim = col + 1;
	}
	// Guardo el elemento elem en m[row][col]
	m->filas[row].elems[col] = elem;
	// Guardo la posiciÃ³n m[row][col] como ocupada
	m->filas[row].occupied[col] = 1;
	return 1;	
}

void
freeMatrix(matrixADT m) {
	for(int i = 0; i < rows(m); i++) {
		free(m->filas[i].elems); // Libero el arreglo dinÃ¡mico de elementos
		free(m->filas[i].occupied); // Libero el arreglo dinÃ¡mico para posiciones ocupadas
	}
	free(m->filas); // Libero el arreglo de estructuras tColumna
	free(m); // Libero la estructura del TAD
}

int
main(void) {
	matrixADT m = newMatrix();
	int aux;
	setElement(m, 1, 2, 9);
	getElement(m, 1, 2, &aux);
	printf("m[1][2] = %d\n", aux);
	setElement(m, 1, 3, 11);
	getElement(m, 1, 3, &aux);
	printf("m[1][3] = %d\n", aux);
	setElement(m, 1, 3, 12);
	getElement(m, 1, 3, &aux);
	printf("m[1][3] = %d\n", aux);
	setElement(m, 3, 3, 10); 
	getElement(m, 3, 3, &aux);
	printf("m[3][3] = %d\n", aux);
	setElement(m, 3, 4, 23);
	getElement(m, 3, 4, &aux);
	printf("m[3][4] = %d\n", aux);
	printf("m[2][7] = %d\n", getElement(m, 2, 7, &aux)); // m[2][7] vacÃ­o
	printf("%ld\n", rows(m)); // 3 filas: [1, 2, 3]
	freeMatrix(m);
}