#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data {
  int number;
  char name[30];
} data;

typedef struct list {
  data data;
  struct list *next, *prev;
} List;

List * start (List *list);
void pop (List *list);
void push (List *list);
void clear (List *list);
void print (List *list);
bool empty (List *list);
void menu ();

int main () {
  int i;
  List *list = start (list);

  do {
    menu ();
    scanf("%d", &i);

    switch (i)
    {
    case 1:
      push (list);
      break;
    case 2:
      pop (list);
      break;
    case 3:
      print (list);
      break;
    case 4:
      clear (list);
      break;
    
    default:
      break;
    }
  } while (i != 4);
  return 0;
}

List * start (List *list) {
  list = (List *) malloc(sizeof(List));
  list->next = list->prev = NULL;
  return list;
}
void pop (List *list) {
  int number;
  List *kill = list->next;

  printf ("entre a matricula a ser retirada da lista : ");
  scanf ("%d", &number);

  if (empty(list)) {
    printf ("lista vazia");
    return;
  } else {
    for ( ; kill && kill->data.number != number; kill = kill->next);

    if (kill && kill->data.number == number) { 
      kill->prev->next = kill->next;
      if (kill->next)
        kill->next->prev = kill->prev;
      free (kill);
    } else {
      printf ("matricula nao encontrada . . . ");
      return;
    }
  }
}
void push (List *list) {
  List *aux = list;
  List *newCell = start (newCell);

  printf ("entre somente o primeiro nome do aluno : ");
  scanf ("%s", newCell->data.name);
  printf ("entre o numeor de matricula do aluno : ");
  scanf ("%d", &newCell->data.number);

  if (empty(list)) {
    newCell->next = list->next;
    list->next = newCell;
    newCell->prev = list;
    list->next = newCell;
  } else { 
    while (aux->next && aux->next->data.number < newCell->data.number)
      aux = aux->next;

    newCell->next = aux->next;
    newCell->prev = aux;
    if (aux->next)
      newCell->next->prev = newCell;
    aux->next = newCell;
  }
}
void clear (List *list) {
  List *kill;
  
  while (list) {
    kill = list;
    list = list->next;
    free(kill);
  }
}
void print (List *list) {
  for (list = list->next; list; list = list->next)
    printf ("%s, %d \n", list->data.name, list->data.number);
}
bool empty (List *list) {
  if (list->next) 
    return false;
  else return true;
}
void menu () {
  printf (" \n");
  printf (" \n");
  printf ("1-Incluir \n");
  printf ("2-Excluir \n");
  printf ("3-Listar \n");
  printf ("4-Sair \n");
  printf (" \n");
  printf (" \n");
}