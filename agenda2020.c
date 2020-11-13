#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct agenda
{
  char nome[30];
  int id;
} Agenda;

typedef struct var
{
  int nPess, i, j, op;
  char nome[30];
} Var;

typedef struct nodo
{
  Agenda info;
  struct nodo *prox;
  struct nodo *ant;
} Nodo;

typedef struct lista
{
  Nodo *ult;
  Nodo *ini;
} Lista;

#define I vars->i
#define J vars->j
#define NP vars->nPess
#define OP vars->op
#define NOME ((char *) pBuffer + sizeof(Var) + sizeof(Agenda) * ((NP)-1))
#define TELEFONE *(int *) (pBuffer + sizeof(Var) + (sizeof(Agenda) * ((NP)-1)) + sizeof(char) * 30)

void *pBuffer;
Var *vars;
Lista *lista;
Agenda *pessoa;

void menu();
void imprimir();
void ordenaPorNome();
void liberar();
Nodo *buscar();
void remover();
Lista *criarLista();
Nodo *criarNodo();
void inserirNaLista();
void pop();
void push();
void ordenaPorId();
void imprimirBuscado();


int main()
{
  pBuffer = malloc(sizeof(Var));
  if (pBuffer == NULL)
  {
    printf("ERROR");
    return 0;
  }
  vars = pBuffer;
  vars->op = 0;
  vars->nPess = 0;
  vars->i = 0;
  vars->j = 0;
  lista = criarLista();

  do
  {
    menu();
    scanf("%d", &vars->op);
    getchar();
 

    switch (vars->op)
    {
    case 1:
      inserirNaLista();
      break;

    case 2:
      imprimir();
      break;

    case 3:
      imprimirBuscado();
      break;

    case 4:
      remover();
      break;

    case 5:
      liberar();
      free(pBuffer);
      break;

    default:
      printf("\nERROR(in)\n");
      break;
    }
  } while ((OP) != 5);
  return 0;
}

void menu()
{
  printf("\n");
  printf("1: Insere\n");
  printf("2: Lista\n");
  printf("3: Busca\n");
  printf("4: Apaga\n");
  printf("5: Sair\n");
  printf("Op.: ");
}

Lista *criarLista()
{
  if (lista)
  {
    printf("\nERROR(seq)\n");
    exit(0);
  }
  lista = (Lista *)malloc(sizeof(Lista));

  if (!lista)
  {
    printf("\nERROR(mem)\n");
    exit(0);
  }

  lista->ini = lista->ult = NULL;

  return lista;
}

Nodo *criarNodo()
{
  Nodo *novo;

  novo = (Nodo *)malloc(sizeof(Nodo));
  if (!novo)
  {
    printf("\nERROR(mem)\n");
    exit(0);
  }
  novo->prox = novo->ant = NULL;
  printf("\n\nEntre o nome : ");
  scanf("%s", novo->info.nome);
  printf("Entre o ID : ");
  scanf("%d", &novo->info.id);

  return novo;
}

void inserirNaLista()
{
  Nodo *aux = lista->ini;
  Nodo *novo = criarNodo();
  (vars->nPess)++;

  if (lista->ini == NULL)
  {
    lista->ini = novo;
    lista->ult = lista->ini;
  }
  else
  {
    while (aux->prox)
      aux = aux->prox;

    novo->ant = aux;
    aux->prox = novo;
    lista->ult = novo;
  }
}

void ordenaPorNome()
{
  Nodo *i;
  Nodo *j;
  Agenda *aux;
  if (!lista)
    return;

  for (i = lista->ini->prox; i; i = i->prox)
  {
    for (j = lista->ini; j != lista->ult; j = j->prox)
    {
      if (strcmp(j->info.nome, j->prox->info.nome) < 0)
      {
        printf("ordenou");
        aux = &j->info;
        j->info = j->prox->info;
        j->prox->info = *aux;
      }
    }
  }
}

void imprimir()
{
  if (!lista)
  {
    printf("\nERROR(in)\n");
    return;
  }
  printf("1 para ordenar por nome e 2 para ordenar por telefone : ");
  scanf("%d", &vars->op);

  if (vars->op == 1)
    ordenaPorNome();
  else if (OP == 2)
    ordenaPorId();
  
  push();
  pop();
}

void push()
{
  pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * (NP));
  Nodo *aux = lista->ini;

  I = 0;
  while (aux)
  {
    *(Agenda *)(pBuffer + sizeof(Var) + sizeof(Agenda) * I) = aux->info;
    (I)++;
    aux = aux->prox;
  }
}

void pop()
{
  Agenda *agenda = pBuffer +sizeof(Var) + sizeof(Agenda)*((vars->nPess) -1); 

  printf("\nestou aqui");
  while ((vars->nPess))
  {
    printf("\nNome : %s\nTelefone : %d", agenda->nome, agenda->id);
    (vars->nPess)--;
    agenda--;
    pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * (vars->nPess));
    agenda = pBuffer +sizeof(Var) + sizeof(Agenda)*((vars->nPess));
  }
  printf("\nsai aqui");
}

void remover()
{
  Nodo *kill = buscar();
  if (!kill)
    return;
  Nodo *aux = lista->ini;

  if ((vars->nPess) == 1)
  {
    free(lista->ini);
    lista->ini = lista->ult = NULL;
  }
  else if (!kill->ant && kill->prox)
  {
    lista->ini = lista->ini->prox;
    lista->ini->ant = NULL;
    free(kill);
  }
  else if (!kill->prox)
  {
    lista->ult = lista->ult->ant;
    aux = kill->ant;
    aux->prox = NULL;
    free(kill);
  }
  else
  {
    aux = kill->ant;
    aux->prox = kill->prox;
    aux->prox->ant = aux;
    free(kill);
  }
  (vars->nPess)--;
}

Nodo *buscar()
{
  Nodo *aux = lista->ini;

  printf("\nEntre o nome  : ");
  scanf("%s", vars->nome);

  while (aux && strcmp(vars->nome, aux->info.nome) != 0)
    aux = aux->prox;

  if (!aux)
  {
    printf("\nERROR(in)\n");
    return NULL;
  }
  else
    return aux;
}

void liberar()
{
  Lista *aux = lista;

  if (!aux->ini->prox)
  {
    free(aux->ini); 
  } 
  else 
  {
    while (aux->ini && aux->ini != aux->ult)
    {
      free(aux->ini->ant);
      aux->ini = aux->ini->prox;
    } 
    free(aux->ini);
  }
  free(aux);
}

void imprimirBuscado()
{
  Nodo *aux = buscar();

  if (aux)
    printf("\nNome : %s\nTelefone : %d\n", aux->info.nome, aux->info.id);
}

void ordenaPorId()
{
  if (!lista)
    return;

  Nodo *i;
  Nodo *j;
  Agenda *aux;

  for (i = lista->ini->prox; i != NULL; i = i->prox)
  {
    for (j = lista->ini; j != lista->ult; j = j->prox)
    {
      if (j->prox && j->info.id > j->prox->info.id)
      {
        aux = &j->info;
        j->info = j->prox->info;
        j->prox->info = *aux;
      }
    }
  }
}



