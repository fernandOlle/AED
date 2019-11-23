#include <stdio.h>
#include <stdlib.h>

typedef struct starts {
  int intStart;
  int floatStart;
  int doubleStart;
} Starts;
Starts startsIndex;

#define INT startsIndex.intStart*sizeof(int)
#define FLOAT startsIndex.floatStart*sizeof(float)
#define DOUBLE startsIndex.doubleStart*sizeof(double)

void * push (void *buffer);
void * pushInt (void *buffer);
void * pushFloat (void *buffer);
void * pushDouble (void *buffer);
void * bufferRealloc(void *buffer);
void printBuffer (void *buffer);

int main () {
  startsIndex.intStart = startsIndex.floatStart = startsIndex.doubleStart = 0;
  void *buffer = malloc(sizeof(void));
  buffer = push (buffer);
  printBuffer (buffer);
  return 0;
}

void * push (void *buffer) {
  int op;

  do {
    printf ("\n\n1-Int\n2-Float\n3-Double\n4-Para\n\n");
    scanf ("%d", &op);

    switch (op) {
      case 1:
        buffer = pushInt (buffer);
        break;
      case 2:
        buffer = pushFloat (buffer);
        break;
      case 3:
        buffer = pushDouble (buffer);
        break;
      case 4:
        break;

      default:
        break;
    }
  } while (op != 4);
  return buffer;
}

void * bufferRealloc(void *buffer) {
  buffer = realloc (buffer, sizeof(int)*INT +sizeof(float)*FLOAT +sizeof(double)*DOUBLE);
  return buffer;
}
void * pushInt (void *buffer) {
  startsIndex.intStart ++;
  buffer = bufferRealloc (buffer);
  scanf ("%d", (int *)(buffer +INT -1));
  return buffer;
}
void * pushFloat (void *buffer) {
  startsIndex.floatStart ++;
  buffer = bufferRealloc (buffer);
  scanf ("%f", (float *)(buffer +INT +FLOAT -1));
  return buffer;
}
void * pushDouble (void *buffer) {
  startsIndex.doubleStart ++;
  buffer = bufferRealloc (buffer);
  scanf ("%lf", (double *)(buffer +INT +FLOAT +DOUBLE -1));
  return buffer;
}
void printBuffer (void *buffer) {
  if (startsIndex.intStart) {
    printf ("INT :");
    printf ("%d", *(int *)buffer);
    for (int i = 1; i < startsIndex.intStart; i ++)
      printf (", %d", *(int *)(buffer+sizeof(int)*i));
  }

  if (startsIndex.floatStart) {
  printf ("\n");
  printf ("FLOAT :");
  printf ("%f", *(float *)(buffer +INT));
  for (int i = 1; i < startsIndex.floatStart; i ++)
    printf (", %f", *(float *)(buffer+sizeof(float)*i+INT));
  }
  if (startsIndex.doubleStart) {
  printf ("\n");
  printf ("DOUBLE :");
  printf ("%lf", *(int *)(buffer +FLOAT));
  for (int i = 1; i < startsIndex.doubleStart; i ++)
    printf (", %lf", *(double *)(buffer+sizeof(double)*i+FLOAT));
  }
}