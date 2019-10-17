/* Crie um programa que dado uma string, coloque as letras dela em ordem decrescente
usando o algoritmo quick sort. */

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

void quickSort ( char * array, int start, int end );
void imprimir ( char * array ); 

int main ( ) {
    char array[50];

    scanf ("%s", array);

    quickSort ( array, 0, strlen(array) -1 );
    printf ("%s", array);

    return 0;
}
void quickSort ( char * array, int start, int end ) {
    int i = start, j = end;
    int meio = (start + end) /2;
    char pivot = array[meio];
    char temp;

    do{    
        while ( pivot < array[i] ) 
            i ++;
        
        while ( pivot > array[j]) 
            j --;
        
        if ( i <= j ) {
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            i ++;
            j --;
        }
    }while ( i <= j );

    if ( start < j ) {
        quickSort ( array, start, j );
    }
    if ( i < end ) {
        quickSort ( array, i, end);
    }
}