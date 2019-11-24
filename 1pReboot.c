#include <stdio.h>
#include <stdlib.h>

typedef struct starts {
  int intStart;
  int floatStart;
  int doubleStart;
} Starts;
Starts startsIndex;

#define INT startsIndex.intStart
#define FLOAT startsIndex.floatStart
#define DOUBLE startsIndex.doubleStart

void ** allocBuffer (void **buffer);
void * pushInt (void *buffer);
void * pushFloat (void *buffer);
void * pushDouble (void *buffer);
void pushBuffer (void **buffer);
void printBuffer (void **buffer);
void printInt (void *buffer);
void printFloat (void *buffer);
void printDouble (void *buffer);
void menu ();

int main () {
  void **buffer;
  buffer = allocBuffer (buffer);
  pushBuffer (buffer);

  free (buffer);
  return 0;
}
/************ MAIN ACIMA ************/
void ** allocBuffer (void **buffer) {
  buffer = (void **) malloc(sizeof(void *) *3);
  buffer[0] = (int *) malloc(sizeof(int));
  buffer[1] = (float *) malloc(sizeof(float));
  buffer[2] = (double *) malloc(sizeof(double));

  startsIndex.intStart = startsIndex.floatStart 
  = startsIndex.doubleStart = 0;

  return buffer;
}
/******** FUNÇÃO PRINCIPAL ********/
void pushBuffer (void **buffer) {
  int op;
  do {
    menu ();
    scanf ("%d", &op);

    switch (op)
    {
    case 1:
      buffer[0] = pushInt (buffer[0]);
      break;
    case 2:
      buffer[1] = pushFloat (buffer[1]);
      break;
    case 3:
      buffer[2] = pushDouble (buffer[2]);
      break;
    case 4:
      printBuffer (buffer);
      break;

    default:
      break;
    }
  } while (op != 4);
}
/**********************************/
void * pushInt (void *buffer) {
  int newInt;
  scanf ("%d", &newInt);
  INT ++;
  buffer = (int *) realloc(buffer, sizeof(int) *INT);
  *(int *) (buffer +(sizeof(int) *(INT -1))) = newInt;

  return buffer;
}
void * pushFloat (void *buffer) {
  float newFloat;
  scanf ("%f", &newFloat);
  FLOAT ++;
  buffer = (float *) realloc(buffer, sizeof(float) *FLOAT);
  *(float *) (buffer +(sizeof(float) *(FLOAT -1))) = newFloat;

  return buffer;
}  
void * pushDouble (void *buffer) {
  double newDouble;
  scanf ("%lf", &newDouble);
  DOUBLE ++;
  buffer = (double *) realloc(buffer, sizeof(double) *DOUBLE);
  *(double *) (buffer +(sizeof(double) *(DOUBLE -1))) = newDouble;
  
  return buffer;
}
void printBuffer (void **buffer) {
  printInt (buffer[0]);
  printFloat (buffer[1]);
  printDouble (buffer[2]);  
}
void printInt (void *buffer) {
  if (INT) {
    printf ("INT :");
    printf ("%d", *(int *)buffer);
    for (int i = 1; i < INT; i ++)
      printf (", %d", *(int *)(buffer+sizeof(int)*i));
  }
}
void printFloat (void *buffer) {
  if (FLOAT) {
    printf ("\n");
    printf ("FLOAT :");
    printf ("%f", *(float *)(buffer));
    for (int i = 1; i < FLOAT; i ++)
      printf (", %f", *(float *)(buffer+sizeof(float)*i));
  }
}
void printDouble (void *buffer) {
  if (DOUBLE) {
    printf ("\n");
    printf ("DOUBLE :");
    printf ("%lf", *(double *)(buffer));
    for (int i = 1; i < DOUBLE; i ++)
      printf (", %lf", *(double *)(buffer+sizeof(double)*i));
  }
}
void menu () {
  printf ("\n");
  printf ("\n");
  printf ("1-Int\n");
  printf ("2-Float\n");
  printf ("3-Double\n");
  printf ("4-Sair\n");
  printf ("\n");
  printf ("\n");
}