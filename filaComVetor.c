#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 5

typedef struct Aluno {
    char nome[10];
    int cod;
} Aluno;

typedef struct Fila {
    Aluno alunos[MAX];
    int topo;
    int base;
    int limite;
    int qtdDeAlunos;
} Fila;
Fila fila;

int push (Fila *fila);
int pop (Fila *fila, Aluno *aux);
int clear (Fila * fila);
void reset (Fila *fila);
bool empty (Fila fila);
void menu ();
bool full (Fila fila);

int main () {

    return 0;
}

int push (Fila *fila) {
    if (!full(*fila)) {
        scanf ("%s", fila->alunos[fila->topo].nome);
        fila->alunos[fila->topo].cod = (int) fila->alunos[fila->topo].nome;
        fila->topo ++;   
        if (fila->topo != 10 && !full(*fila))
            fila->topo = 0;
    } else printf ("fila cheia");
}
int pop (Fila *fila, Aluno *aux) {
    if (!empty(*fila)) {
        
    } else return printf ("fila vazia");
}
int clear (Fila * fila) {
    Fila *nova;
    reset (nova);
    fila = nova;
}
void reset (Fila *fila) {
    fila->topo = 0;
    fila->base = 0;
    fila->limite = MAX;
    fila->qtdDeAlunos = 0;
}
bool empty (Fila fila) {
    if (fila.qtdDeAlunos == 0)
        return true;
    else return false
}
void menu () {

}
bool full (Fila fila) {
    if (fila.qtdDeAlunos == fila.limite)
        return true;
    else return false
}