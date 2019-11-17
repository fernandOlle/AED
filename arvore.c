#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pessoa {
  char nome[10];
  int cpf;
} Pessoa;

typedef struct Cel * pCel;

typedef struct Cel {
  Pessoa pessoa;
  pCel ant, prox;
} Cel;

void reset (Cel * ini);
void push (Pessoa sPessoa, pCel * pPessoa);
int busca (Cel * pCelIni, Pessoa sPessoaBusca);

int main ( ) {
  

  return 0;
}

void reset (Cel * ini) {
  
}
// PUSH incompleto !
void push (Pessoa sPessoa, pCel * pPessoa) {
  if ( *pPessoa == NULL ) {
    *pPessoa = (pCel) malloc (sizeof(Cel));

    (*pPessoa)-> pessoa = sPessoa;
    (*pPessoa)-> ant = NULL;
    (*pPessoa)-> prox = NULL;
  } else {
    
  }
}
//////
int busca (Cel * pCelIni, Pessoa sPessoaBusca) {

}
