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
  Agenda agendaAux;
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
void ordenarPorNome();
void ordenarPorId();
void liberar();
Nodo *buscar();
void remover();
Lista *criarLista();
Nodo *criarNodo();
void inserirNaLista();
void pop();
void push();
void imprimirBuscado();


int main()
{
  pBuffer = malloc(sizeof(Var));
  if (pBuffer == NULL)
  {
    printf("ERROR(mem)");
    return 0;
  }
  vars = pBuffer;
  vars->op = 0;
  vars->nPess = 0;
  vars->i = 0;
  vars->j = 0;
  lista = criarLista();
  NP = 0;

  do
  {
    menu();
    scanf("%d", &vars->op);
    getchar();
    I = 0;
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
  } while (OP != 5);
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
  printf("Entre o telefone : ");
  scanf("%d", &novo->info.id);

  return novo;
}

void inserirNaLista()
{
  Nodo *aux = lista->ini;
  Nodo *auxAnt = aux;
  Nodo *novo = criarNodo();
  (NP)++;

  if (lista->ini == NULL)
  {
    lista->ini = novo;
    lista->ult = lista->ini;
  }
  else
  {
    lista->ult = lista->ini;
    
    while (aux->prox)
    {
      aux = aux->prox;
      aux->ant = auxAnt;
      auxAnt = auxAnt->prox;
      lista->ult = lista->ult->prox;
    }
    aux->prox = novo;
    aux = aux->prox;
    aux->ant = auxAnt;
    lista->ult = lista->ult->prox;
  }
}

void ordenarPorNome()
{
  if (!lista)
    return;
  Nodo *i;
  Nodo *j;
  
  for (i = lista->ini->prox; i; i = i->prox)
  {
    for (j = lista->ini; j != lista->ult; j = j->prox)
    {
      if (strcmp(j->info.nome, j->prox->info.nome) < 0)
      {
        printf("ordenou");
        vars->agendaAux = j->info;
        j->info = j->prox->info;
        j->prox->info = vars->agendaAux;
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
    ordenarPorNome();
  else if (vars->op == 2)
    ordenarPorId();
  else 
  {
    printf("\nERROR(in)\n");
    return;
  }
  
  push();
  pop();
}

void push()
{
  pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * (NP));
  Nodo *aux = lista->ini;
  vars = pBuffer;

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
  Agenda *agenda = pBuffer +sizeof(Var) + sizeof(Agenda)*((NP) -1); 
  I = NP;
  printf("\n");
  printf("\n começou a printar");
  while ((NP))
  {
    printf("\nNome : %s\nTelefone : %d", agenda->nome, agenda->id);
    (NP)--;
    agenda--;
    pBuffer = realloc(pBuffer, sizeof(Var) + sizeof(Agenda) * (NP));
    vars = pBuffer;
  }
  NP = I;
  printf("\n");
}

void ordenarPorId()
{
  if (!lista)
    return;
  Nodo *i;
  Nodo *j;
  
  for (i = lista->ini->prox; i; i = i->prox)
  {
    for (j = lista->ini; j != lista->ult; j = j->prox)
    {
      if (j->info.id < j->prox->info.id)
      {
        printf("ordenou");
        vars->agendaAux = j->info;
        j->info = j->prox->info;
        j->prox->info = vars->agendaAux;
      }
    }
  }
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



