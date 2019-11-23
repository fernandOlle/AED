#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    char nome[10];
    int matricula;  
} Aluno;

typedef struct Pilha {
    Aluno *alunos;
    Aluno *base;
    Aluno *topo;
    int capacidade;
} Pilha;

void reset (Pilha *pilha);
void push (Pilha *pilha);
void pop (Pilha *pilha);
int empty (Pilha *pilha);
void imprimir (Pilha *pilha);
void clear (Pilha *pilha);
Aluno * copiaPilha (Pilha *pilha);

int main ( ) {
    Pilha pilha;
    int i = 0;

    do {
        printf("entre op");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            push (&pilha);
            break;
        case 2:
            pop(&pilha);
            break;
        case 3:
            clear(&pilha);
            break;
        case 4:
            imprimir(&pilha);
            break;

        default:
            break;
        }
    } while (i != 4);

    return 0;
}

void reset (Pilha *pilha) {
    pilha->alunos = NULL;
    pilha->base = NULL;
    pilha->topo = NULL;
    pilha->capacidade = 0;

    pilha->alunos = (Aluno *) malloc(sizeof(Aluno));
    pilha->base = NULL;
}
void push (Pilha *pilha) {
    Aluno novo;
    
    printf("entre nome");
    scanf("%s",novo.nome);
    printf("entre matricula");
    scanf("%d", novo.matricula);
    

    pilha->capacidade ++;
    pilha->alunos = (Aluno *) realloc(pilha->alunos, sizeof(Aluno)* pilha->capacidade);

    pilha->alunos[pilha->capacidade] = novo;
    pilha->base = &pilha->alunos[pilha->capacidade -1];
    pilha->topo = pilha->alunos;
}
void pop (Pilha *pilha) {
    if (empty(pilha)) {
        pilha->capacidade --;
        pilha = (Pilha *) malloc(sizeof(Pilha) * pilha->capacidade);
        pilha-> alunos = copiaPilha(pilha);

        pilha->topo = &pilha->alunos[pilha->capacidade];
    } else return; 
}
int empty (Pilha *pilha) {
    if (pilha->capacidade == 0) {
        return 1;
    } else return 0;
}
Aluno * copiaPilha (Pilha *pilha) {
    Aluno * novo;
    novo = (Aluno *) malloc (sizeof(Aluno) * pilha->capacidade);

    for (int i = 0; i < pilha->capacidade; i ++)
        novo[i] = pilha->alunos[i];

    return novo;
}
void imprimir (Pilha *pilha) {

}
void clear (Pilha *pilha) {
    pilha->alunos = NULL;
    pilha->base = NULL;
    pilha->topo = NULL;
    pilha->capacidade = 0;
    free(pilha->alunos);
}