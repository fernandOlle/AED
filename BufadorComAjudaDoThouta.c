/* 
 * https://github.com/thomaziogiacobbe/tgiacobbe/blob/master/agendapbuffer.c
 * https://github.com/MatheusFukuda/codigos/blob/master/codigofoda.c
 * 
 */

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

#define auxInt pBuffer+0
#define forI pBuffer+sizeof(int)
#define forJ pBuffer+sizeof(int)*2
#define qtdNomes pBuffer+sizeof(int)*3
#define pbSize pBuffer+sizeof(int)*4
#define auxInt2 pBuffer+sizeof(int)*5
#define pStrcutAux pBuffer+sizeof(int)*6
#define pInicio pBuffer+sizeof(int)*7+sizeof(agenda)
#define pBMalloc 7 
void * pBuffer;

typedef struct Agenda {
    char nome[10];
    int cod;
} agenda;

void menu ( );
void inserir ( );
void buscar ( );
void deletar ( );
void imprimir ( agenda ini, int aux, int nomes );
void sair ( );
void arrumarPonteiro ( int ** aux, int ** nomes, int ** size, int ** iFor, int ** jFor,
                       int ** aux2, int ** esturtura, agenda ** ini );
int main ( ) {
    pBuffer = malloc( (pBMalloc*sizeof(int)) + sizeof(agenda) * 2 );
    int * aux; int * nomes; int * size; int * iFor; int * jFor;
    int * aux2; int * esturtura;
    agenda * ini = pInicio;

    arrumarPonteiro ( &aux, &nomes, &size, &iFor, &jFor, &aux2, &esturtura, &ini );
    * nomes = 0;
    * size = 0;

    while ( 2756 ) {
        printf ("\n");
        menu ( );
        scanf ( "%d", aux );
        printf ("\n");
        switch ( * aux ) {
            case 1 :
                inserir ( );
                arrumarPonteiro ( &aux, &nomes, &size, &iFor, &jFor, &aux2, &esturtura, &ini );
                break;
            case 2 :
                imprimir ( *ini, *aux, *nomes );
                break;
            case 3 :
                deletar ( );
                arrumarPonteiro ( &aux, &nomes, &size, &iFor, &jFor, &aux2, &esturtura, &ini );
                break;
            case 4 :
                buscar ( );
                break;
            case 5:
                sair ( );
                exit (0);
                break;
            default :
                break; 
        }
    }
    return 0;
}
/*     ============     */
void menu ( ) {
    printf("Case 1 : Inserir\n");
    printf("Case 2 : Listar\n");
    printf("Case 3 : Deletar\n");
    printf("Case 4 : Buscar\n");
    printf("Case 5 : SAIR\n");
}
void inserir ( ) {
    int * nomes = qtdNomes, * size = pbSize; 
    agenda * novo;
    novo = pInicio;
    novo += (* nomes); 

    printf("nome :");
    scanf("%s", novo-> nome);

    printf("numero:");
    scanf("%d", &novo-> cod);

    *nomes += 1;
    size = (*nomes + 1) * sizeof(agenda) + pInicio;

    pBuffer = realloc( pBuffer, (*size) * sizeof(pBuffer) ); 
}
void buscar ( ) {

}
void deletar ( ) {

}
void imprimir ( agenda ini, int aux, int nomes ) {
    for ( aux = 0; aux < nomes; aux ++ , &ini + sizeof(ini) )
        printf ("%s %d\n",ini.nome, ini.cod);
}
void sair ( ) {
    free (pBuffer);
}
void arrumarPonteiro ( int ** aux, int ** nomes, int ** size, int ** iFor, int ** jFor,
                       int ** aux2, int ** esturtura, agenda ** ini ) 
{
    * aux = auxInt;
    * iFor = forI; 
    * jFor = forJ; 
    * nomes = qtdNomes; 
    * size = pbSize; 
    * aux2 = auxInt2; 
    * esturtura = pStrcutAux;  
    * ini = pInicio;
}