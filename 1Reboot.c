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

int * pushInt (int *i);
void * push (void *buffer);
float * pushFloat (float *f);
double * pushDouble (double *d);
void printBuffer (void *buffer);
void * pushBuffer (int *i, float *f, double *d, void *bufer);

int main () {
  startsIndex.intStart = startsIndex.floatStart = startsIndex.doubleStart = 0;
  void *buffer = malloc(sizeof(void));
  buffer = push (buffer);
  printBuffer (buffer);
  return 0;
}

void * push (void *buffer) {
  int op;
  int *i, *f, *d;

  do {
    printf ("\n\n1-Int\n2-Float\n3-Double\n4-Para\n\n");
    scanf ("%d", &op);

    switch (op) {
      case 1:
        i = pushInt (i);
        break;
      case 2:
        f = pushFloat (f);
        break;
      case 3:
        d = pushDouble (d);
        break;
      case 4:
        buffer = pushBuffer (i, f, d, buffer);
        break;

      default:
        break;
    }
  } while (op != 4);
  return buffer;
}
void * pushBuffer (int *i, float *f, double *d, void *bufer) {
  
}
int * pushInt (int *i) {
  int newI;
  scanf ("%d", &newI);
  startsIndex.intStart ++;

  i = (int *) realloc(i, sizeof(int)*INT);
  i[INT -1] = newI;

  return i;
}
float * pushFloat (float *f) {
  float newF;
  scanf ("%d", &newF);
  startsIndex.floatStart ++;

  f = (int *) realloc(f, sizeof(int)*FLOAT);
  f[FLOAT -1] = newF;

  return f;
}
double * pushDouble (double *d) {
  double newI;
  scanf ("%d", &newI);
  startsIndex.doubleStart ++;

  d = (int *) realloc(i, sizeof(int)*DOUBLE);
  i[DOUBLE -1] = newI;

  return d;
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