#include <stdio.h>
#include <stdlib.h>

float *retCop ( float *vector, int *numCount );
float *inserir ( float *vector, int numCount );
void imprimir ( float *vector, int numCount );

int main () {
  int op = 0;;
  scanf ("%d", &op);
  
  if (op <= 0) {
    printf("error");
    exit (0);
  }

  float *vector = (float *) malloc(sizeof(float) *op);
  
  vector = inserir(vector, op);
  vector = retCop(vector, &op);
  imprimir ( vector, op );
  free (vector);
  return 0;
}

float *inserir ( float *vector, int numCount ) {
  if (numCount == 1){
    scanf ( "%f", vector );
  } else {
  for (int i = 0; i < numCount; i ++)
    scanf ("%f", &vector[i]);
  }
  return vector;
}

float *retCop ( float *vector, int *numCount ) {
  if ( numCount > 1) {
  int i = 0, j = 0, k;

  for ( ; i < *numCount -1; i ++ )
    for ( j = i +1; j < *numCount;) 
      if ( vector[i] == vector[j] ) {
        for( k = j; k < *numCount; k++ )
          vector[k -1] = vector[k]; 
        *numCount = *numCount -1;
      } else
        j ++;

  vector = (float *) realloc(vector, sizeof(float) * (*numCount));
  }

  return (float *) vector;
}

void imprimir ( float *vector, int numCount ) {
  if ( numCount > 1 )  
    for ( int i = 0; i < numCount; i ++ )
      printf ( "%.2f  ", vector[i] );
  else 
    printf ( "%.2f ", *vector );
}