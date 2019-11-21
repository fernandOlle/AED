/*
  38. Implementar uma lista encadeada para manipulac ̧a ̃o de polinoˆmios do tipo
   a'n xˆn +a`n−1 xˆn−1 +···+a'1 xˆ1 +a0
  onde cada elemento i da lista deve armazenar o n-e ́simo termo do polinoˆmio (diferente de 0). Cada item da lista 
  deve conter o valor da poteˆncia de (inteiro) e o coeficiente correspondente (inteiro). Fac ̧a func ̧o ̃es para :
  (a) Inicializar um polinoˆmio.
  (b) Inserir um novo termo no polinoˆmio existente (c) Imprimir
  (c) Imprimir
  (d) Eliminar o termo associado a` n-e ́sima poteˆncia (e) Reinicializar um polinoˆmio
  (e) Reinicializar um polinoˆmio
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Polinomio {
  int a;
  int potencia;
} Polinomio;

typedef struct Lista {
  Polinomio poli;
  struct Lista * prox;
} Lista;

Lista * start (Lista *cabeca);
void menu();
Lista * push (Lista *cabeca);
void imprimir (Lista *cabeca);
void pop (Lista *cabeca);
void reset (Lista *cabeca);

int main () {
  Lista *cabeca;
  int i;

  cabeca = start (cabeca);
  do {
    menu ();
    scanf ("%d", &i);
    switch (i)
    {
    case 1:
      cabeca = push (cabeca);
      break;
    case 2:
      imprimir (cabeca);
      break;
    case 3:
      pop (cabeca);
      break;
    case 4:
      reset (cabeca);
      cabeca = start (cabeca);
      break;
    case 5: 
      reset (cabeca);
      break;

    default:
      break;
    }
  } while (i != 5);
  return 0;
}

Lista * start (Lista *cabeca) {
  cabeca = (Lista *) malloc(sizeof(Lista));
  cabeca->prox = NULL;
  Lista *novaCabeca = cabeca;
  int a;
  int potencia;

  printf ("Entre a potencia maior do polinomio : ");
  scanf ("%d", &potencia);

  for (int i = potencia ; i >= 0; i --) {
    Lista *cell;
    cell = (Lista *) malloc(sizeof(Lista));
    novaCabeca->prox = cell;
    novaCabeca = novaCabeca->prox; 
    printf ("entre o valor de A para o termo numero %d do polinomio : ", (potencia +1) -i);
    scanf ("%d", &a);
    novaCabeca->poli.a = a;
    novaCabeca->poli.potencia = i;
  }
  novaCabeca->prox = NULL;
  
  return cabeca;
}
void menu () {
  printf ("\n");
  printf ("\n");
  printf ("1 = push\n");
  printf ("2 = lista\n");
  printf("3 = pop\n");
  printf ("4 = reset\n");
  printf ("5 = sair");
  printf ("\n");
  printf ("\n");
}
Lista * push (Lista *cabeca) {
  Lista *novoTermo;
  novoTermo = (Lista *) malloc(sizeof(Lista));
   
  for (novoTermo = cabeca->prox; novoTermo->prox != NULL; novoTermo = novoTermo->prox);

  novoTermo->prox = (Lista *) malloc(sizeof(Lista));
  novoTermo = novoTermo->prox;
  novoTermo->prox = NULL;

  printf ("entre nova constante para o novo termo do polinomio : ");
  scanf ("%d", &novoTermo->poli.a);
  printf ("entre nova potencia para o novo termo do polinomio : ");
  scanf ("%d", &novoTermo->poli.potencia);

  return cabeca;
}
void imprimir (Lista *cabeca) { 
  for (cabeca = cabeca->prox; cabeca != NULL; cabeca = cabeca->prox) {
    if (cabeca->poli.potencia && cabeca->prox) {
      printf ("%d . x^%d ", cabeca->poli.a, cabeca->poli.potencia);
      printf ("+");
    } else if (!cabeca->poli.potencia) { 
      printf ("%d ", cabeca->poli.a);
      if (cabeca->prox)
         printf ("+");
    } else if (cabeca->poli.potencia) {
      printf ("%d . x^%d ", cabeca->poli.a, cabeca->poli.potencia);
      if (cabeca->prox)
        printf ("+");
    }
  }
}   
void pop (Lista *cabeca) {
  int index, i;
  Lista *remover;
  printf ("entre indice do polinomio que se deseja tirar : ");
  scanf ("%d", &index);

  for (remover = cabeca->prox, i = 0; i < index && cabeca != NULL; 
    i ++, remover = remover->prox, cabeca = cabeca->prox) {
      if (!cabeca && i < index) {
        printf ("index invalido");
        return;
      }
  }
  cabeca->prox = remover->prox;
  free (remover);
}
void reset (Lista *cabeca) {
  cabeca = cabeca->prox;
  
  if (cabeca->prox)
    reset(cabeca);

  free (cabeca);
}