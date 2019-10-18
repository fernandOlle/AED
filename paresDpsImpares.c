#include <stdio.h>

int ordena ( int * array, int n );
int imprimir ( int * pares, int p, int * impares, int ip );

int main ( ) {
  int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  
  ordena ( array, 10 );
  return 0;
}
int ordena ( int * array, int n ) {
  int pares[10], impares[10];
  int p, ip;
  p = ip = 0;

  for ( int i = 0; i < 10; i ++ )
    for ( int j = i +1; j < 9; j ++)
      if ( array[i] > array[j] ) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
  
  for ( int i = 0; i < 10; i ++ ) 
    if ( !(array[i]%2) )
      pares[p ++] = array[i];
    else impares[ip ++] = array[i];

  imprimir ( pares, p, impares, ip );
}
int imprimir ( int * pares, int p, int * impares, int ip ) {
  for ( int i = 0; i < p; i ++ )
    printf ("%d\n", pares[i]);

  printf ("\n");

  for ( int i = 0; i < ip; i ++ )
    printf ("%d\n", impares[i]);
}