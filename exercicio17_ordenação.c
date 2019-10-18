/* Fac¸a um programa que leia n nomes inserindo-os em uma lista de forma ordenada 
utilizando a ideia do algoritmo insertion sort. No final, o programa deve mostrar todos os
nomes ordenados alfabeticamente. */

#include  <stdio.h>
#include <string.h>
#include <stdlib.h>

void inserirOrdenado ( char ** array, int n );
void imprimir ( char ** array, int n );

int main ( ) {
  char ** array;
  int n;

  scanf ("%d", &n);
  array = (char **) malloc(sizeof(char *) *n);    
  
  for ( int i = 0; i < n; i ++ ) {
    array[i] = (char *) malloc(sizeof(char) *10);
    scanf ("%s", array[i]);
    inserirOrdenado ( array, n );
  }
  imprimir ( array, n );

  return 0;
}
void inserirOrdenado ( char ** array, int n ) {
  int i, j;
  char temp[10];

  for ( i = 1; i < n; i ++ ) {
    j = i -1;
    strcpy(temp, array[i]);
    while ( j >= 0 && strcmp(temp, array[j]) < 0 ) {
      strcpy(array[j+1], array[j]);
      j --;
    }
    strcpy(array[j+1], temp);
  }
}
void imprimir ( char ** array, int n ) {
  for ( int i = 0; i < n; i ++ )
    printf ("%s\n", array[i]);
}