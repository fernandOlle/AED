#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ** criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int* colunaMatriz(int ** mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor (int *vet, int n);

int main ( ) {
  int ** matriz = NULL, op = 0, linha = 0, coluna = 0, opColunm = 0;

  while ( op != 6 ) {
    printf ("1) Criar e redimencionar uma matriz m x n, onde n e m são fornecidos pelo usuário;\n");
    printf ("2) Realizar a leitura dos elementos da matriz;\n");
    printf ("3) Fornecer a soma dos elementos da matriz;\n");
    printf ("4) Retornar em um vetor (utilizando ponteiros) os elementos de uma determinada coluna da matriz;\n");
    printf ("5) Imprimir a matriz;\n");
    printf ("6) Sair do programa : ");
    scanf ("%d", &op);

    switch ( op ) {
      case 1:
        printf ("\n\n");

        printf ("Entre numero de linha : ");
        scanf ("%d", &linha);
        printf ("Entre numero de colunas : ");
        scanf ("%d", &coluna);
        
        if ( matriz != NULL )
          free (matriz);

        matriz = criaMatriz ( linha, coluna );
        
        printf ("\n\n");
      break; 

      case 2:
        leiaMatriz ( matriz, linha, coluna );
      break;

      case 3:
        printf ("\n\n");
        printf ("A soma da sua matriz : %d", somaMatriz( matriz, linha, coluna ));
        printf ("\n\n");
      break;

      case 4:
        printf ("\n\n");
        printf ("Que coluna estas precisando ver : ");
        scanf ("%d", &opColunm);
        
        if ( (opColunm >= 0) && (opColunm < coluna) ) 
          imprimeVetor ( colunaMatriz(matriz, linha, coluna, opColunm), linha );
        else 
          printf ("ERROR\n\n");      
      break;

      case 5:
        imprimeMatriz ( matriz, linha, coluna );
      break;

      case 6:
        liberaMatriz ( matriz, linha );
      break;

      default:
      break;
    }
  }

  return 0;
}

int ** criaMatriz(int m, int n) {
  int ** matriz;
  matriz = ( int ** ) malloc( sizeof(int *) *m );

  if ( matriz ==  NULL ) {
    printf ("ERROR");  
    exit (0);
  }

  for ( int i = 0; i < m; i ++) 
    matriz[i] = ( int * ) malloc( sizeof(int) *n);

  return ( int ** ) matriz;
}

void leiaMatriz(int **mat, int m, int n) {
  printf("Entre os numeros :\n");
  
  for ( int linha = 0; linha < m; linha ++ )
    for ( int coluna = 0; coluna < n;coluna ++ )
      scanf("%d", &mat[linha][coluna] );  
}

int somaMatriz(int **mat, int m, int n) {
  int lineSum, totalSum;
  lineSum = totalSum = 0;

  for ( int linha = 0; linha < m; linha ++ ) {
    for ( int coluna  = 0; coluna < n; coluna ++ )
      lineSum += mat[linha][coluna];

    totalSum += lineSum;
    lineSum = 0;
  }

  return totalSum;
}

int* colunaMatriz(int ** mat, int m, int n, int ncoluna) {
  if ( n <= ncoluna ) {
    printf ("ERROR");
    ncoluna = n -1;
  }
  int * retorno = ( int * ) malloc(sizeof(int) *m);
  
  for ( int linha = 0; linha < m; linha ++ ) 
    retorno[linha] = mat[linha][ncoluna];
  
  return ( int * ) retorno;  
}

void liberaMatriz(int **mat, int ncoluna) {
  for ( int i = 0; i < ncoluna; i ++ )
    free( mat[i] );
  free ( mat );
}

void imprimeMatriz(int **mat, int m, int n) {
  printf ("\n\n");

  for ( int linha  = 0; linha < m; linha ++ ) {
    for( int coluna = 0; coluna < n; coluna ++ )
      printf ("%d ", mat[linha][coluna]);
    printf ("\n");
  }

  printf ("\n\n");
}

void imprimeVetor (int *vet, int n) { 
  printf ("\n\n");
  
  for ( int i = 0; i < n; i ++ )
    printf("%d \n", vet[i]);
  
  printf ("\n\n");
}
