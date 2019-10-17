#include <stdio.h>

void swap ( int * a, int * b);
void qsort ( int * a, int low, int high );
void praticionar ( int * a, int low, int high, int * i, int *j );
void imprimir ( int * a );

int main ( ) {
    int a[] = { 0, 9, 8, 8, 6, 5, 4, 3, 2, 1 }; 
    int size = sizeof( a ) / sizeof( int );
    imprimir ( a );
    qsort ( a, 0, size - 1 );
}
/* ============== */
void swap ( int * a, int * b) {

}
void qsort ( int * a, int low, int high ) {

}
void praticionar ( int * a, int low, int high, int * i, int *j ) {

}
void imprimir ( int * a ) {

}
