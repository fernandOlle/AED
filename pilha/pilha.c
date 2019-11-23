#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
  char nome[30];
  int iCod;
} Aluno;

typedef struct Pilha {
  Aluno alunos[10];
  int topo;
  int base;
  int limite;
} Pilha;
Pilha pilha;

Pilha push ();
Pilha pop ();
Pilha clear (Pilha pilha);
Pilha reset ();
Pilha listar ();
Pilha empty ();
void menu ();

int main () {
  pilha.topo = 0;
  pilha.base = 0;
  pilha.limite = 10;
  int i = 0;

  do {
    menu ();
    scanf ("%d", &i);
    switch (i) {
      case 1:
        pilha = push ();
        break;

      case 2:
        pilha = pop ();
        break;

      case 3:
        pilha = clear (pilha);
        break;

      case 4:
        pilha = reset ();
        break;
      
      case 5:
        pilha = empty ();
        break;

      case 6:
        pilha = listar ();

      default:
        break;
    }
  } while (i != 7);

  return 0;
}

void menu () {
  printf ("\n");
  printf ("1 push\n");
  printf ("2 pop\n");
  printf ("3 clear\n");
  printf ("4 reset\n");
  printf ("5 empty\n");
  printf ("6 listar\n");
  printf ("7 sair\n");
  printf ("\n");
}
Pilha push () {
  if (pilha.topo < pilha.limite) {
    scanf ("%s", pilha.alunos[pilha.topo].nome);
    pilha.alunos[pilha.topo].iCod = (int)pilha.alunos[pilha.topo].nome;
    pilha.topo ++;
    if (pilha.topo == pilha.limite)
      printf("igualou");
  } else if (pilha.topo == pilha.limite) {
    printf("entrouu");
    Aluno aux[10];
    for (int i = 0; i < 10; i ++)
      aux[i] = pilha.alunos[-- pilha.topo];
    for (int i = 8; i >= 0; i ++) {
      if (pilha.topo == 0)
        printf("ooooo");
      pilha.alunos[++ pilha.topo] = aux[i];
    }
    scanf ("%s", pilha.alunos[pilha.topo].nome);
  }
  return pilha;
}
Pilha pop () {
  if (pilha.topo > pilha.base) {
    printf ("%s, %d", pilha.alunos[pilha.topo].nome, pilha.alunos[pilha.topo].iCod);

    pilha.topo --;
  } else printf ("pilha esta vazia");
  return pilha;
}
Pilha clear (Pilha pilha) {
  pilha.topo = 0;
  pilha.base = 0;
  pilha.limite = 10;

  return pilha;
}
Pilha reset () {
  Pilha novaPilha;
  novaPilha = clear (pilha);

  return novaPilha;
}
Pilha listar () {
  while (pilha.topo -1 >= pilha.base) {
    printf ("%s, %d \n", pilha.alunos[pilha.topo -1]. nome, pilha.alunos[-- pilha.topo].iCod);
  }

  Pilha novaPilha;
  novaPilha = reset ();

  return novaPilha;
}
Pilha empty () {
  pilha = clear (pilha);

  return pilha;
}
