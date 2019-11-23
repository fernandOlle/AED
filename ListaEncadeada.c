#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
  char nome[10];
  int iCod;
} Aluno;

typedef struct No * Prox;
typedef struct No {
  Aluno aluno;
  Prox prox;
} No;

void start (No *ini);
void push (No *ini);
void pop (No *ini);
void listar (No *ini);
void search (No ini);
void clear (No *ini);
void reset (No *ini); 

int main () {
  No ini;
  start (&ini);
  int i = 0;

  do {
    scanf ("%d", &i);
    switch (i) {
      case 1:
        push(&ini);
        break;
      case 2:
        pop (&ini);
        break;
      case 3:
        listar (&ini);
        break;
      case 4: 
        reset (&ini);
      case 5:
        clear(&ini);
        break;
      
      default:
        printf("invslido");
        break;
    }
  } while (i != 5);

  return 0;
}

void start (No *ini) {
  Aluno cabeca;
  strcpy(cabeca.nome, "CONTROLE");
  cabeca.iCod = atoi(cabeca.nome) -32;
  
  ini = (No *) malloc(sizeof(No));
  ini->prox = NULL;
  ini->aluno = cabeca;
}
void push (No *ini) {
  Prox busca, nova;

  nova = (No *) malloc (sizeof(No));

  printf("entre o nome :");
  scanf ("%s", nova->aluno.nome);

  for (busca = ini; busca->prox != NULL && 
    busca->aluno.iCod < nova->aluno.iCod ; busca = busca-> prox);

  nova-> prox = busca-> prox;
  busca-> prox = nova;
}
void pop (No *ini) {
  Prox atual, anterior;
  int iCod;

  printf("entre icod :");
  scanf("%d", &iCod);

  for (anterior = ini, atual = anterior->prox; atual-> prox != NULL &&
   atual->aluno.iCod != iCod; atual = atual->prox, anterior = anterior-> prox);

  if (atual->aluno.iCod != iCod) {
    printf("iCod nao esta na lista");
    return;
  } else {
    anterior->prox = atual->prox;
    free(atual);
    printf("nome removido com sucesso");
  }
}
void listar (No *ini) {
  for ( ; ini != NULL; ini = ini-> prox){
    printf ("%s", ini->aluno.nome);
    printf ("%d", ini->aluno.iCod);
  }
}
/*
void search (No ini) {

}
*/
void clear (No *ini) {
  while(ini-> prox != NULL) {
    clear (ini);
    free (ini);
  }
}
void reset (No *ini) {
  clear (ini);
  if ( ini != NULL && ini-> prox != ini )
    free (ini);
  else if (ini == NULL && ini->prox == NULL)
    start (ini);
}