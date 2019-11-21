#include   <time.h>
#include  <stdio.h>
#include <stdlib.h>

void qSort ( int * array, int left, int right );
void bSort ( int * array, int n );
void sSort ( int * array, int n );
void iSort ( int * array, int n );
void print ( int * array, int n );

int main ( ) {
  int array[100];
  srand(time(NULL));

  for ( int i = 0; i < 100; i ++ )
    array[i] = rand( ) % 1000;
  
  print ( array, sizeof(array) /4 );
  printf ("\n\n");
  qSort ( array, 0, sizeof(array) /4 );
  // bSort ( array, sizeof(array) /4 );
  // sSort ( array, sizeof(array) /4 );
  // iSort ( array, sizeof(array) /4 );
  print ( array, sizeof(array) /4 );

  return 0;
}
void qSort ( int * array, int left, int right ) {
  int pivot, mid, i, j;
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
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i ++;
      j --;
    }
  } while ( i <= j );
  
  if ( left < j ) 
    qSort ( array, left,j );
  if ( i < right )
    qSort ( array, i, right ); 
}
void bSort ( int * array, int n ) {
  int i, j;

  for ( i = 0; i < n-1; i ++ )
    for ( j = 0; j < n-i-1; j ++ )
      if ( array[j] > array[j +1] ) {
        int temp = array[j];
        array[j] = array[j +1];
        array[j +1] = temp;  
      }
}
void sSort ( int * array, int n ) {
  int temp, min, i, j;

  for ( i = 0; i < n-1; i ++ ) {
    min = i;
    for ( j = i +1; j < n; j ++ )
      if ( array[min] > array[j] ) 
        min = j;

    temp = array[min];
    array[min] = array[i];
    array[i] = temp;
  }
}
void iSort ( int * array, int n ) { 
  int i, j, temp;

  for ( i = 1; i < n; i ++ ) { 
    temp = array[i];
    j = i -1;
    while ( j >= 0 && array[j] > temp ) {
      array[j +1] = array[j];
    }
    array[j +1] = temp;
  }
}
void print ( int * array, int n ) {
  for ( int i = 0; i < n; i ++ )
    printf ("%d\n", array[i]);
}