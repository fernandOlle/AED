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
  struct Cell *next;
} Cell;

typedef struct line {
  Cell *head;
} Line;


Line *start (Line *line);
void push (Line *line);
Cell * pop (Line *line);
void printLine (Line *line);
void reverse (Line **line);
void clear (Line *line);
Line * reset (Line *line);
bool empty (Line *line);
void menu ();

int main () {
  int op;
  Line *line = start (line);
  do {
    menu ();
    scanf ("%d", &op);
    switch (op) {
      case 1:
        push (line);
        break;
      case 2:
        Cell *temp = pop (line);
        printf ("%s, %d", temp->data.name, temp->data.iData);
        free (temp);
        break;
      case 3:
        printLine (line); 
        break;
      case 4:
        reverse (&line);
        break;
      case 5:
        line = reset (line);
        break;
      case 6:
        clear (line);
        break;
      
      default:
        break;
    }
  } while (op != 6);
  return 0;
}

Line *start (Line *line) {
  line = (Line *) malloc(sizeof(Line));
  line->head = (Cell *) malloc(sizeof(Cell));
  line->head->next = NULL;
  return line;
}
void push (Line *line) {
  Cell *newCell;

  printf ("entre o nome o aluno : ");
  scanf ("%s", newCell->data.name);
  printf ("entre o nuemro do aluno : ");
  scanf ("%d", newCell->data.name);

  if (empty(line)) {
    newCell->next = line->head->next;
    line->head->next = newCell;
  } else {
    while (line->head->next)
      line->head = line->head->next;

    newCell->next = line->head->next;
    line->head->next = newCell;
  }
}
Cell * pop (Line *line) {
  Cell *kill = (Cell *) malloc(sizeof(Cell));
  kill->next = NULL;

  kill = line->head->next;

  if (empty(line)) {
    return NULL;
  } else {
    kill = line->head->next;
    line->head->next = kill->next;
    return kill;
  }
}
void printLine (Line *line) {
  if (empty(line)) {
    printf ("lista vazia");
    return;
  } else {
    while (line->head) {
      line->head = line->head->next;
      printf ("%s, %d\n", line->head->data.name, line->head->data.iData);
    }
  }
}
void reverse (Line **line) {
  Cell *current = (*line)->head, *next = NULL, *prev = NULL;
  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  (*line)->head = prev;
}
void clear (Line *line) {
  Cell *kill;
  while (line->head) {
    kill = line->head;
    line->head = line->head->next;
    free (kill);
  }
  free (line);
}
Line * reset (Line *line) {
  clear (line);
  line = start (line);
  return line;
}
bool empty (Line *line) {
  if (line->head->next)
    return false;
  else return true;
}
void menu () {
  printf ("\n");
  printf ("\n");
  printf ("1-Posh\n");
  printf ("2-Pop\n");
  printf ("3-PrintLine\n");
  printf ("4-Reverse\n");
  printf ("5-Reset\n");
  printf ("6-Sair\n");
  printf ("\n");
}