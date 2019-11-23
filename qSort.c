#include   <time.h>
#include  <stdio.h>
#include <stdlib.h> 

void quickSort ( int * array, int left, int right );
void imprimir ( int * array, int n );

int main ( ) {

    int array[100];
    srand(time(NULL));

    for ( int i = 0; i < 100; i ++ )
        array[i] = rand() % 1000;

    imprimir ( array, sizeof(array)/4 );
    printf ("\n");printf ("\n");
    quickSort ( array, 0, sizeof(array)/4 );
    imprimir ( array, sizeof(array)/4 );

    return 0;
}

void quickSort ( int * array, int left, int right ) {
    int pivot, i, j, mid, temp;
    mid = (left + right) /2;
    pivot = array[mid];
    i = left;
    j = right;

    do {
        while ( array[i] < pivot ) 
            i ++;
        
        while ( array[j] > pivot ) 
            j --;
        
        if ( i <= j ) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i ++;
            j --;
        }
    } while ( i <= j );

    if ( left < j )
        quickSort ( array, left, j );

    if ( right > i )
        quickSort ( array, i, right );
}

void imprimir ( int * array, int n ) {
    int i;
    for ( i = 0; i < n; i ++ )
        printf ( "%d\n", array[i] );
}