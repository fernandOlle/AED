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
#define NOME (pBuffer + sizeof(Var) + sizeof(Agenda) * ((NP)-1))
#define TELEFONE (pBuffer + sizeof(Var) + (sizeof(Agenda) * ((NP)-1)) + sizeof(char) * 30)

void *pBuffer;
Var *vars;
Lista *lista;
Agenda *pessoa;

Lista *criaLista();
void insere();
void menu();
void imprimir();
void ordenaPorNome();
void ordenaPorId();
Nodo *buscar();
void deletar();

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

  while (1)
  {
    menu();
    scanf("%d", &vars->op);
    getchar();
    NP = 0;

    switch (vars->op)
    {
    case 1:
      (vars->nPess)++;
      insere();
      break;

    case 2:
      if (vars->nPess == 0)
        printf("\nERROR\n");
      else
        imprimir();
      break;

    case 3:
      if (vars->nPess == 0)
        printf("\nERROR\n");
      else
        buscar();
      break;

    case 4:
      if (vars->nPess == 0)
        printf("\nERROR\n");
      else
        deletar();
      break;

    case 5:
      free(pBuffer);
      exit(0);
      break;

    default:
      printf("\nERROR\n");
      break;
    }
  }
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

Lista *criaLista()
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

Nodo *criaNodo()
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
  scanf("%s", &novo->info.nome);
  printf("Entre o ID : ");
  scanf("%d", &novo->info.id);
}

void insereNaLista()
{
  Nodo *aux = lista->ini;
  Nodo *novo = criaNodo();
  (NP)++;

  if (lista->ini == NULL)
  {
    lista->ini = novo;
    lista->ult = lista->ini;
  }
  else
  {
    while (aux->prox && aux->prox->info.id > novo->info.id)
      aux = aux->prox;

    novo->prox = aux->prox;
    novo->ant = aux;
    if (aux->prox)
      novo->prox->ant = novo;
    aux->prox = novo;
  }
  lista->ult = novo;
}

// void ordenaPorId()
// {
//   if (!lista)
//     return;

//   Nodo *i;
//   Nodo *j;
//   Agenda *aux;

//   for (i = lista->ini->prox; i != NULL; i = i->prox)
//   {
//     for (j = lista->ini; j != lista->ult; j = j->prox)
//     {
//       if (j->prox && j->info.id > j->prox->info.id)
//       {
//         *aux = j->info;
//         j->info = j->prox->info;
//         j->prox->info = *aux;
//       }
//     }
//   }
// }

void ordenaPorNome()
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
      if (j->prox && strcmp(j->info.nome, j->prox->info.nome) < 0)
      {
        *aux = j->info;
        j->info = j->prox->info;
        j->prox->info = *aux;
      }
    }
  }
}

void imprimir()
{
  if (!lista)
    return;

  Nodo *aux = lista->ini;

  printf("1 para ordenar por nome e 2 para ordenar por telefone : ");
  scanf("%d", &vars->op);

  if (vars->op == 1)
    ordenaPorNome();
  else
    ordenaPorNome();

  push(aux, pBuffer);
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

  printf("\n");
  while ((NP))
  {
    printf("\nNome : %s\nTelefone : %d", *(char *)NOME, *(int *)TELEFONE);
    (NP)--;
    pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * (NP));
  }
  printf("\n");
}

void remover()
{
  Nodo *kill = buscar();
  if (!kill)
    return;
  Nodo *aux = lista->ini;

  if (NP == 1)
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
  (NP)--;
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

void imprimeBuscado()
{
  Nodo *aux = busca();

  if (aux)
    printf("\nNome : %s\nTelefone : %d\n", aux->info.nome, aux->info.id);
}

// void insere()
// {
//   pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * (vars->nPess));
//   if (pBuffer == NULL)
//     printf("\nERRO\n");

//   vars = pBuffer;
//   agenda = pBuffer + sizeof(Var) + sizeof(Agenda) * (vars->nPess) - sizeof(Agenda);
// }

// void imprimir()
// {
//   agenda = pBuffer + sizeof(Var);
//   for (vars->i = 0; (vars->i) < (vars->nPess); (vars->i)++)
//   {
//     printf("\nNome: %s\n", agenda->nome);
//     printf("Telefone: %d\n", agenda->id);
//     agenda++;
//   }
// }

// void buscar()
// {
//   printf("\n\nEntre o nome : ");
//   scanf("%s", vars->nome);

//   for (vars->i = 0; (vars->i) < (vars->nPess); (vars->i)++)
//   {
//     agenda = pBuffer + sizeof(Var);
//     agenda += vars->i;
//     if (strcmp(vars->nome, agenda->nome) == 0)
//     {
//       printf("\n\nNome: %s\n", agenda->nome);
//       printf("ID: %d\n", agenda->id);
//       return;
//     }
//   }
//   printf("\nERROR\n");
// }

// void deletar()
// {
//   printf("\n\nEntre o nome : ");
//   scanf("%s", vars->nome);

//   for (vars->i = 0; (vars->i) <= (vars->nPess); (vars->i)++)
//   {
//     agenda = pBuffer + sizeof(Var);
//     agenda += vars->i;
//     aux = pBuffer + sizeof(Var);

//     if (vars->i == vars->nPess)
//     {
//       printf("\nERROR\n");
//       break;
//     }
//     if (strcmp(vars->nome, agenda->nome) == 0)
//     {
//       while (vars->i < (vars->nPess) - 1)
//       {
//         agenda = pBuffer + sizeof(Var);
//         agenda += vars->i;
//         aux = pBuffer + sizeof(Var);
//         aux += vars->i + 1;
//         strcpy(agenda->nome, aux->nome);
//         agenda->id = aux->id;
//         (vars->i)++;
//       }
//       (vars->nPess)--;
//       pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * (vars->nPess));
//       return;
//     }
//   }
// }
