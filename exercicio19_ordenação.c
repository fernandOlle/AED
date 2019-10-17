#include  <stdio.h>
#include <string.h>
#include <stdlib.h>

void selectionSort ( char ** nomes, int qtd );
void imprimir ( char ** nomes, int qtd );

int main ( ) {
    char ** nomes;
    int qtd;

    scanf ("%d", &qtd);

    nomes = (char **) malloc(sizeof(char) * qtd );

    for ( int i = 0; i < qtd; i ++ ) {
        nomes[i] = (char*) malloc(sizeof(char)*10);
        scanf ("%s", nomes[i]);
    }
    selectionSort ( nomes, qtd );
    imprimir ( nomes, qtd );

    return 0;
}

void selectionSort ( char ** nomes, int qtd ) {
    int i, j, min;
    char * temp;

    for ( i = 0; i < qtd; i ++ ) {
        min = i;
        for ( j = i +1; j < qtd; j ++ ) {
            if ( strcmp (nomes[min], nomes[j]) > 0 )
                min = j;
        }
        temp = nomes[min];
        nomes[min] = nomes[i];
        nomes[i] = temp;
    }
}
void imprimir ( char ** nomes, int qtd ) {
    printf ("\n");
    for ( int i = 0; i < qtd; i ++ )
        printf ("%s\n", nomes[i]);
}