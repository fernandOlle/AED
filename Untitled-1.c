#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main () {

  char sexo;
  char nome[20];
  char deffis[20];
  int idade;
  float altura;
  float peso;
  int unsigned long long cpf;

  printf("\nentre nome : ");
  scanf("%s", nome);
  printf("\nentre idade : ");
  scanf("%d", &idade);
  getchar();
  printf("\nentre sexo : ");
  scanf("%c", &sexo);
  getchar();
  printf("\nentre cpf : ");
  scanf("%llu", &cpf);
  printf("\nentre altura : ");
  scanf("%f", &altura);
  printf("\nentre peso : ");
  scanf("%f", &peso);
  printf("\nentre Deficiência física : ");
  scanf("%s", &deffis);

  printf("\n\n\n");

  printf("\nnome : %s", nome);
  printf("\nidade : %d", idade);
  printf("\nsexo : %c", sexo);
  printf("\ncpf : %llu", cpf);
  printf("\naltura : %f", altura);
  printf("\npeso : %f", peso);
  printf("\nDeficiência física : %s", deffis);

  return 0;
}