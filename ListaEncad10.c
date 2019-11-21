#include <stdio.h>
#include <stdlib.h>

typedef struct produto{
  int codProd; //c ́odigo do produto
  char nomeProd[10]; //nome do produto
  float valor; //valor do produto
  int qtdeEstoque; //quantidade dispon ́ıvel em estoque }
} produto;

typedef struct lista {
  produto Produto;
  struct lista * prox;
} lista;
lista * cabeca;

void retornaMenor (lista *cabeca, produto cell);

int main () {

}

void retornaMenor (lista *cabeca, produto cell) {
  lista * novo;
  float menor = cell.valor;

  for (novo = cabeca->prox; novo != NULL; novo = novo->prox) {
    if (menor > novo->Produto.valor)
      menor = novo->Produto.valor;
  }
  return menor;
}