
typedef struct node * listADT;

listADT newList ();

void freeList( listADT l );

listADT insert( listADT l, int n );

listADT delet( listADT l, int n );

int belongs( listADT l, int n );

int isEmpty( listADT l );

int head( listADT l ); /* devuelve cabeza */

listADT tail( listADT l ); /* devuelve cola */

