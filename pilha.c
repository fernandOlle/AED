#include <stdio.h>

void insertionSort ( int * vet, int max );
void imprimir ( int * vet );

int main ( ) {
    int vet[10] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    imprimir ( vet );
    printf ("\n");
    insertionSort ( vet, 10 );
    imprimir ( vet );

    return 0;
}
void insertionSort ( int * vet, int max ) {
    int i, j, temp;

    for ( i = 1; i < max; i ++ ) {
        j = i - 1;
        temp = vet[i];
        while ( j >= 0 && temp < vet[j] ){
            vet[j+1] = vet[j];
            j --;
        } 
        vet[j+1] = temp;
    }
}
void imprimir ( int * vet ) {
    for ( int i = 0; i < 10; i++ )
        printf ("%d\n", vet[i] );
}