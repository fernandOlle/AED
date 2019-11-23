//
//  lista.c
//  
//
//  Created by Fernando R. Ollé on 14/11/19.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
  int ra;
  char nome[50];
} Aluno;

typedef struct Pilha {
  Aluno *alunos;
  int topo;
  int base;
  int limite;
} Pilha;

void pop();
void push();
void reset();
void empyt();
void print();
void clear();

int main () {
  int i;
  
  do {
    switch (i) {
      case 1:
        pop (fila);
      break;
      case 2:
        push (fila);
      break:
      case 3:
        print (fila);
      break;
      case 4:
        return 0;
      break;
    }
  } while (i != 4);
  return 0;
}

void pop() {

}
void push() {

}
void reset() {
  pilha.topo = NULL;
  push.base = NULL;
  pilha->alunos = NULL;
  pilha.limite = 0;
}
void print() {

}
void clear() {

}
void empyt() {
x
}


C/C++ Clang Command Adapter