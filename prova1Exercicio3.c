#include<stdio.h>

int menores ( int * vet, int n );

int main ( ) {
    int vet[5] = { 2,2,2,2,1 };

    printf ("%d\n", menores(vet, 5));

    return 0;
}

int menores ( int * vet, int n ) {
  int menor = vet[n -1], count = 0;

  while (n > 0) {
    n --;
    if (vet[n] > menor) 
      count ++;
    else if (vet[n] < menor)
      menor = vet[n];
  }
  return count;
}