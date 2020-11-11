#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct agenda {
  char nome[30];
  int id;
} Agenda;

typedef struct var{
    int nPess, i, j, op, intCount;
    char nome[30];
} Var;

void *pBuffer;
Var *vars;
Agenda *aux;
Agenda *agenda;

void insere ( );
void imprimir ( );
void buscar ( );
void deletar ( );

int main ( ) {
  pBuffer = malloc(sizeof(Var));
  if (pBuffer == NULL) {
    printf ("ERROR");
    return 0;
  }
  vars = pBuffer;
  vars->op = 0;
  vars->nPess = 0;
  vars->i = 0;
  vars->j = 0;

  while ( 1 ) {
      printf("\n");
      printf("1: Insere\n");
      printf("2: Lista\n");
      printf("3: Busca\n");
      printf("4: Apaga\n");
      printf("5: Sair\n");
      printf("Op.: ");
      scanf("%d", &vars->op);
      getchar();

    switch (vars->op) {
      case 1: (vars->nPess) ++;
        insere ( );
      break;

      case 2: if (vars->nPess == 0) 
        printf ("\nERROR\n");
          else
        imprimir ( );
      break;

      case 3: if (vars->nPess == 0) 
          printf ("\nERROR\n");    
        else
          buscar ( );
      break;

      case 4: if (vars->nPess == 0)
          printf ("\nERROR\n");
        else 
          deletar ( );
      break;

      case 5: free(pBuffer);
        exit(0);
      break;

      default: printf ("\nERROR\n");
      break;
    }
  }
  return 0;
}

void insere ( ) {
  pBuffer = realloc ( pBuffer, sizeof(Var) +sizeof(Agenda) *(vars->nPess) );
  if ( pBuffer == NULL )
    printf("\nERRO\n");

  vars = pBuffer;
  agenda = pBuffer + sizeof(Var)+ sizeof(Agenda) *(vars->nPess) - sizeof(Agenda);
  printf ("\n\nEntre o nome : ");
  scanf ("%s", agenda->nome);
  printf ("Entre o ID : ");
  scanf ("%d", &agenda->id);
}

void imprimir ( ) {
  agenda = pBuffer + sizeof(Var);
  for ( vars->i = 0; (vars->i) < (vars->nPess); (vars->i) ++ ) {
    printf("\nNome: %s\n", agenda->nome);
    printf("Telefone: %d\n", agenda->id);
    agenda ++;
  }
}

void buscar ( ) {
  printf ("\n\nEntre o nome : ");
  scanf ("%s", vars->nome);

  for ( vars->i = 0 ; (vars->i) < (vars->nPess); (vars->i) ++ ) {
    agenda = pBuffer + sizeof(Var);
    agenda += vars->i;
    if ( strcmp (vars->nome, agenda->nome) == 0 ) {
      printf("\n\nNome: %s\n", agenda->nome);
      printf("ID: %d\n", agenda->id);
      return;
    }
  }
  printf ("\nERROR\n");
}

void deletar ( ) {
  printf ("\n\nEntre o nome : ");
  scanf ("%s", vars->nome);

  for ( vars->i = 0; (vars-> i) <= (vars->nPess); (vars->i) ++ ) {
    agenda = pBuffer + sizeof(Var);
    agenda += vars->i;
    aux = pBuffer + sizeof(Var);

    if ( vars->i == vars->nPess) {
      printf ("\nERROR\n");
      break;
    }
    if ( strcmp( vars->nome, agenda->nome ) == 0 ) {
      while ( vars->i < (vars->nPess) -1) { 
        agenda = pBuffer + sizeof(Var);
        agenda += vars->i;
        aux = pBuffer + sizeof(Var);
        aux += vars->i +1;
        strcpy(agenda->nome, aux->nome);
        agenda->id = aux->id;
        (vars-> i) ++;
      }
      (vars-> nPess) --;
      pBuffer = realloc(pBuffer, sizeof(Var) +sizeof(Agenda) *(vars->nPess) );
      return;
    }
  }
}
