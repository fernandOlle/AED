#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void imparPar(void *pN, int t);

int main () {
	void *pN;	
  int aux = 0;
	pN = malloc(sizeof(int) * MAX);

  for (int i = 0; i < MAX; i ++)
		scanf ("%d", (int *)(pN + (sizeof(int) * i)));
	
  imparPar(pN, MAX);

  for (int i = 0; i < MAX; i ++) {
    if (*(int *)(pN + (sizeof(int) * i)) %2 == 0 && ++ aux == 1) 
      printf ("- ");
    printf ("%d ", *(int *)(pN + (sizeof(int) * i)));
  }

	free(pN);
	return 0;
}

void imparPar(void *pN, int t) {
	int *i, *j, *aux;

	i = (int *) malloc(sizeof(int));
	j = (int *) malloc(sizeof(int));
	aux = (int *) malloc(sizeof(int));
	
	for ((*i) = 0; (*i) < t; (*i) ++)
		if (*(int *)(pN +(sizeof(int) *(*i))) %2 == 0)
			for ((*j) = (*i) +1; (*j) < t; (*j) ++)
				if (*(int *)(pN +(sizeof(int) *(*j))) % 2 != 0) {
					*aux = *(int *)(pN +(sizeof(int) *(*i)));
					*(int *)(pN +(sizeof(int) *(*i))) = *(int *)(pN +(sizeof(int) *(*j)));
					*(int *)(pN +(sizeof(int) *(*j))) = *aux;
					*j = t;
				}
			
	free (i);
	free (j);
	free (aux);
}
