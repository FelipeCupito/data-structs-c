/*
 * listADT.h
 * Contrato del TAD Lista Lineal
 * simplemente encadenada ordenada, sin repeticiones y sin header
 */

#ifndef LISTADT_H_
#define LISTADT_H_

typedef int  elemType;

/* El siguiente tipo define el TAD Lista.
 * Se lo define como puntero a "cierta estructura"
 * para ocultar la real representacion de la misma
 */
typedef struct listCDT *listADT;


/* Funci�n de comparaci�n para ordenar las componentes del TAD.
 * De no servir este c�digo el usuario debe cambiarlo por el
 * que desea. La convenci�n a seguir es que debe devolver
 * n�mero negativo si el primer par�metro debe aparecer antes
 * que el segundo en la lista, o bien devolver n�mero positivo
 * si debe aparecer despu�s, o bien 0 si son elementos equivalentes
 */
static int compare(elemType elem1, elemType elem2 ){
	return elem1 - elem2;		
}

/* Funcion:  		newList
 * Uso:  		list = newList();
 * -------------------------------------------------------------------
 * Descripci�n: 	Inicializa la lista. No hay error posible.
 * -------------------------------------------------------------------
 * Precondicion:		-
 * Postcondicion: 	Lista creada
 */
listADT newList(void);


/* Funcion:  		Insert
 * Uso:  	        res == 	Insert( list, 12.3);
 * -------------------------------------------------------------------
 * Descripci�n: 	Inserta un elemento en la lista ordenada,
 *  			usando la funci�n de comparaci�n Compare.
 * 			Si el elemento ya exist�a, lo ignora y retorna cero.
 * 		        Retorna 1 si lo pudo insertar	
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	Lista con el nuevo elemento,si no estaba repetido.
 */
int insert(listADT  list, elemType element);


/* Funcion:  		delete
 * Uso:  	        res = 	delete(list, 12.3 );
 * -------------------------------------------------------------------
 * Descripci�n: 	Elimina el elemento de la lista ordenada,
 *  			usando la funci�n Compara. Si el elemento
 * 			no exist�a devuelve 0, caso contrario 1
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	Lista sin el elemento
 */
int delete(listADT list, elemType element);


/* Funcion:  		listIsEmpty
 * Uso:  		if ( listIsEmpty( list ) ...
 * -------------------------------------------------------------------
 * Descripci�n: 	Devuelve 1 si la lista est� vac�a o
 * 			0 en caso contrario
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida, previamente creada
 * Postcondicion: 	- (lista invariante).
 */
int listIsEmpty(const listADT list);

/* Funcion:  		elementBelongs
 * Uso:  		if ( elementBelongs( list, 12.3 ))...
 * -------------------------------------------------------------------
 * Descripci�n: 	Devuelve 1 si el elemento pertenece a la lista
 * 					o 0 en caso contrario
 * -------------------------------------------------------------------
 * Precondicion:	Lista previamente creada
 * Postcondicion: 	- (lista invariante).
 */
int elementBelongs(const listADT list, elemType element);


/* Funcion: 		freeList
 * Uso: 		freeList( list );
 * -------------------------------------------------------------------
 * Descripci�n: 	Destruye la lista, liberando recursos alocados.
 * -------------------------------------------------------------------
 * Precondicion:	Lista que sea valida.
 * Postcondicion: 	-
 */
void freeList(listADT list);

/** 
 * Retorna la cantidad de elementos en la lista
 */
int listSize(const listADT list);

/* Reciba un n�mero entero i y devuelve el i-�simo elemento,
 *  donde el primer elemento tiene el �ndice cero
 *  */

elemType search(listADT list, int i);

/* reciba un puntero a funci�n que permita
modificar cada elemento de la list
*/

void map(listADT list, elemType (*pFunc)(const elemType elem));


//devulve el elemento en la posicion idx
elemType get(listADT list, unsigned int idx);

/**
 * Funciones para poder iterar sobre la lista
 */
void toBegin(listADT list);

int hasNext(const listADT list);

elemType next(listADT list);

#endif /* LISTADT_H_ */
