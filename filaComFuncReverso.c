#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct data {
  char name[30];
  int iData;
} Data;

typedef struct cell {
  Data data;
  struct cell *next;
} Cell;

typedef struct queue {
  Cell *head;
} Queue;

Queue *start (Queue *queue);
void push (Queue *queue);
Cell * pop (Queue *queue);
void printQueue (Queue *queue);
void reverse (Queue **queue);
void clear (Queue *queue);
Queue * reset (Queue *queue);
bool empty (Queue *queue);
void menu ();

int main () {
  int op;
  Queue *queue = start (queue);
  do {
    menu ();
    scanf ("%d", &op);
    Cell *temp;
    switch (op) {
      case 1:
        push (queue);
        break;
      case 2:
        temp = pop (queue);
        printf ("%s, %d", temp->data.name, temp->data.iData);
        break;
      case 3:
        printQueue (queue); 
        break;
      case 4:
        reverse (&queue);
        break;
      case 5:
        queue = reset (queue);
        break;
      case 6:
        clear (queue);
        break;
      
      default:
        break;
    }
    free (temp);
  } while (op != 6);
  return 0;
}

Queue *start (Queue *queue) {
  queue = (Queue *) malloc(sizeof(Queue));
  queue->head = (Cell *) malloc(sizeof(Cell));
  queue->head->next = NULL;
  return queue;
}
void push (Queue *queue) {
  Cell *newCell = (Cell *) malloc(sizeof(Cell));
  Cell *aux = queue->head;
  printf ("entre o nome o aluno : ");
  scanf ("%s", newCell->data.name);
  printf ("entre o nuemro do aluno : ");
  scanf ("%d", &newCell->data.iData);

  if (empty(queue)) {
    newCell->next = queue->head->next;
    queue->head->next = newCell;
  } else {
    while (aux->next)
      aux = aux->next;

    newCell->next = aux->next;
    aux->next = newCell;
  }
}
Cell * pop (Queue *queue) {
  Cell *kill = (Cell *) malloc(sizeof(Cell));
  kill->next = NULL;

  kill = queue->head->next;

  if (empty(queue)) {
    return NULL;
  } else {
    kill = queue->head->next;
    queue->head->next = kill->next;
    return kill;
  }
}
void printQueue (Queue *queue) {
  Cell *aux = queue->head;
  if (empty(queue)) {
    printf ("lista vazia");
    return;
  } else {
    while (aux->next) {
      aux = aux->next;
      printf ("%s, %d\n", aux->data.name, aux->data.iData);
    }
  }
}
void reverse (Queue **queue) {
  Cell *current = (*queue)->head->next, *next = NULL, *prev = NULL;
  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  (*queue)->head->next = prev;
}
void clear (Queue *queue) {
  Cell *kill;
  while (queue->head) {
    kill = queue->head;
    queue->head = queue->head->next;
    free (kill);
  }
  free (queue);
}
Queue * reset (Queue *queue) {
  clear (queue);
  queue = start (queue);
  return queue;
}
bool empty (Queue *queue) {
  if (queue->head->next)
    return false;
  else return true;
}
void menu () {
  printf ("\n");
  printf ("\n");
  printf ("1-Posh\n");
  printf ("2-Pop\n");
  printf ("3-Printqueue\n");
  printf ("4-Reverse\n");
  printf ("5-Reset\n");
  printf ("6-Sair\n");
  printf ("\n");
}