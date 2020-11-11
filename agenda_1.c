#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *inserir(void *pBuffer);
void buscar(void *pBuffer);
void listar(void *pBuffer);
void *apagar(void *pBuffer);
void insertion(void *pBuffer);
void selection(void *pBuffer);
void bubble(void *pBuffer);
void quick(void *pBuffer,int left,int right);
int main()
{
  void *pBuffer;
  pBuffer = malloc((sizeof(int) * 5) + (sizeof(char) * 10));
  //1º numero de elementos, 2º controle repetição 1, 3º controle repetição 2,
  //4º controle escolha, 5º espaço para nome temporario, 6º espaço para numero temporario
  *(int *)pBuffer = 0;
  for (;;)
  {
    printf("AGENDA ALEJANDRO\n");
    printf("1)Inserir\n");
    printf("2)Buscar\n");
    printf("3)Apagar\n");
    printf("4)Listar\n");
    printf("5)Insertion Sort\n");
    printf("6)Selection Sort\n");
    printf("7)Bubble Sort\n");
    printf("8)Quick Sort\n");
    printf("9)Sair\n");
    scanf("%d", (int *)(pBuffer + (3 * sizeof(int))));
    switch (*(int *)(pBuffer + (3 * sizeof(int))))
    {
    case 1:
      pBuffer = inserir(pBuffer);
      break;
    case 2:
      buscar(pBuffer);
      break;
    case 3:
      pBuffer = apagar(pBuffer);
      break;
    case 4:
      listar(pBuffer);
      break;
    case 5:
      insertion(pBuffer);
      break;
    case 6:
      selection(pBuffer);
      break;
    case 7:
      bubble(pBuffer);
      break;
    case 8:
      quick(pBuffer,0,*(int*)pBuffer);
      break;
    case 9:
      free(pBuffer);
      exit(0);
      break;

    default:
      printf("Opcao invalida");
      break;
    }
  }
  return 0;
}
void *inserir(void *pBuffer)
{

  pBuffer = realloc(pBuffer, (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + sizeof(int)) * ((*(int *)pBuffer) + 1)));
  printf("Informe o nome: ");
  scanf("%s", (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + ((*(int *)pBuffer) * (10 * sizeof(char) + sizeof(int))))));
  printf("Informe o numero: ");
  scanf("%d", (int *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + ((*(int *)pBuffer) * (10 * sizeof(char) + sizeof(int))) + (10 * sizeof(char)))));
  *(int *)pBuffer = *(int *)pBuffer + 1;

  return pBuffer;
}
void buscar(void *pBuffer)
{
  printf("Informe o nome que deseja buscar: ");
  scanf("%s", (char *)(pBuffer + (4 * sizeof(int))));
  for (*(int *)(pBuffer + (sizeof(int))) = 0; *(int *)(pBuffer + (sizeof(int))) < *(int *)pBuffer; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {
    if (strcmp((pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))), (char *)(pBuffer + (4 * sizeof(int)))) == 0)
    {
      printf("Nome: %s\n", (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))));
      printf("Telefone: %d\n", *(int *)(pBuffer + ((10 * sizeof(char)) + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))));
    }
  }
}
void listar(void *pBuffer)
{

  for (*(int *)(pBuffer + (sizeof(int))) = 0; *(int *)(pBuffer + (sizeof(int))) < *(int *)pBuffer; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {
    printf("Nome: %s\n", (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))));
    printf("Telefone: %d\n", *(int *)(pBuffer + ((10 * sizeof(char)) + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))));
  }
}
void *apagar(void *pBuffer)
{
  printf("Informe o nome que deseja apagar: ");
  scanf("%s", (char *)(pBuffer + (4 * sizeof(int))));
  for (*(int *)(pBuffer + (sizeof(int))) = 0; strcmp((pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))), (char *)(pBuffer + (4 * sizeof(int)))) != 0; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {
  }
  for (*(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))); *(int *)(pBuffer + (sizeof(int))) < *(int *)pBuffer; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {
    strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))), (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * (1 + *(int *)(pBuffer + (sizeof(int))))))));
    *(int *)(pBuffer + ((10 * sizeof(char)) + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))) = *(int *)(pBuffer + ((10 * sizeof(char)) + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * (1 + *(int *)(pBuffer + (sizeof(int)))))));
  }
  *(int *)pBuffer = *(int *)pBuffer - 1;
  pBuffer = realloc(pBuffer, (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * ((*(int *)pBuffer))));

  return pBuffer;
}
void insertion(void *pBuffer)
{

  for (*(int *)(pBuffer + (sizeof(int))) = 1; *(int *)(pBuffer + (sizeof(int))) < *(int *)pBuffer; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {
    strcpy((char *)(pBuffer + (4 * sizeof(int))), (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int)))))));
    *(int *)(pBuffer + (10 + (4 * sizeof(int)))) = *(int *)(pBuffer + ((10 * sizeof(char)) + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (sizeof(int))))));
    *(int *)(pBuffer + (2 * sizeof(int))) = (*(int *)(pBuffer + (sizeof(int)))) - 1;
    while (((*(int *)(pBuffer + (2 * sizeof(int)))) >= 0) &&
           strcmp((char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (2 * sizeof(int)))))), (char *)(pBuffer + (4 * sizeof(int)))) > 0)
    {
      strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * (1 + *(int *)(pBuffer + (2 * sizeof(int))))))), (char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (2 * sizeof(int)))))));
      *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * (1 + *(int *)(pBuffer + (2 * sizeof(int))))))) =
          *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * *(int *)(pBuffer + (2 * sizeof(int))))));
      *(int *)(pBuffer + (2 * sizeof(int))) = *(int *)(pBuffer + (2 * sizeof(int))) - 1;
    }
    strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * ((*(int *)(pBuffer + (2 * sizeof(int)))) + 1)))), (char *)(pBuffer + (4 * sizeof(int))));
    *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * (sizeof(char))) + (((10 * sizeof(char)) + (sizeof(int))) * ((*(int *)(pBuffer + (2 * sizeof(int)))) + 1)))) = *(int *)(pBuffer + (10 + (4 * sizeof(int))));
  }
}
void selection(void *pBuffer)
{
  //vou usar a variavel de controle switch para armazenar o min id
  for (*(int *)(pBuffer + (sizeof(int))) = 0; *(int *)(pBuffer + (sizeof(int))) < (*(int *)pBuffer) - 1; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {

    *(int *)(pBuffer + (3 * sizeof(int))) = *(int *)(pBuffer + (sizeof(int)));
    for (*(int *)(pBuffer + (2 * sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1; *(int *)(pBuffer + (2 * sizeof(int))) < *(int *)pBuffer; *(int *)(pBuffer + (2 * sizeof(int))) = *(int *)(pBuffer + (2 * sizeof(int))) + 1)
    {
      if (strcmp((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                     (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2 * sizeof(int)))))),
                 (char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                     (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (3 * sizeof(int))))))) < 0)
      {

        *(int *)(pBuffer + (3 * sizeof(int))) = *(int *)(pBuffer + (2 * sizeof(int)));
      }
    }

    strcpy((char *)(pBuffer + (4 * sizeof(int))), (char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                                                      (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (3 * sizeof(int)))))));

    *(int *)(pBuffer + (10 * sizeof(char) + 4 * sizeof(int))) = *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * sizeof(char)) +
                                                                                    (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (3 * sizeof(int))))));
    strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                               (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (3 * sizeof(int)))))),
           (char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                               (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int)))))));
    *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * sizeof(char)) +
                        (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (3 * sizeof(int)))))) = *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * sizeof(char)) +
                                                                                                                            (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int))))));

    strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                               (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int)))))),
           (char *)(pBuffer + (4 * sizeof(int))));
    *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * sizeof(char)) +
                        (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int)))))) = *(int *)(pBuffer + (10 * sizeof(char) + 4 * sizeof(int)));
  }
}
void bubble(void *pBuffer)
{

  for (*(int *)(pBuffer + (sizeof(int))) = 0; *(int *)(pBuffer + (sizeof(int))) < (*(int *)pBuffer) - 1; *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1)
  {
    for (*(int *)(pBuffer + (2 * sizeof(int))) = 0; *(int *)(pBuffer + (2 * sizeof(int))) < (*(int *)pBuffer) - (*(int *)(pBuffer + (sizeof(int)))) - 1; *(int *)(pBuffer + (2 * sizeof(int))) = *(int *)(pBuffer + (2 * sizeof(int))) + 1)
    {
      if (strcmp((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                     (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2 * sizeof(int)))))),
                 (char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                     (10 * sizeof(char) + sizeof(int)) * (1 + *(int *)(pBuffer + (2 * sizeof(int))))))) > 0)
      {
        strcpy((char *)(pBuffer + (4 * sizeof(int))), (char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                                                          (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2 * sizeof(int)))))));
        *(int *)(pBuffer + (4 * (sizeof(int)) + (10 * sizeof(char)))) = *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * sizeof(char)) +
                                                                                            (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2 * sizeof(int))))));
        strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                   (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2 * sizeof(int)))))),
               (char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                   (10 * sizeof(char) + sizeof(int)) * (1 + *(int *)(pBuffer + (2 * sizeof(int)))))));
        *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * sizeof(char)) +
                            (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2 * sizeof(int)))))) = *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * sizeof(char)) +
                                                                                                                                (10 * sizeof(char) + sizeof(int)) * (1 + *(int *)(pBuffer + (2 * sizeof(int))))));
        strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +
                                   (10 * sizeof(char) + sizeof(int)) * (1 + *(int *)(pBuffer + (2 * sizeof(int)))))),
               (char *)(pBuffer + (4 * sizeof(int))));
        *(int *)(pBuffer + (10 + (5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (1 + *(int *)(pBuffer + (2 * sizeof(int)))))) = *(int *)(pBuffer + (4 * (sizeof(int)) + (10 * sizeof(char))));
      }
    }
  }
}
void quick(void *pBuffer,int left,int right){
   srand(time(NULL));
*(int *)(pBuffer + (sizeof(int))) = left;
*(int *)(pBuffer + (2 * sizeof(int))) = right;
*(int *)(pBuffer + (4 * sizeof(int))) = rand() % (left-right); //Usando aleatorio como pivo e armazenando na parte da opcao switch
do{
  while(strcmp((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int)))))),(char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +(10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (4 * sizeof(int)))))))<0)
  *(int *)(pBuffer + (sizeof(int))) = *(int *)(pBuffer + (sizeof(int))) + 1;
  
  while(strcmp((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (4*sizeof(int)))))),(char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) +(10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2 * sizeof(int)))))))<0)
*(int *)(pBuffer + (2 * sizeof(int))) = *(int *)(pBuffer + (2 * sizeof(int))) - 1;

if(*(int *)(pBuffer + (sizeof(int)))<=*(int *)(pBuffer + (2 * sizeof(int)))){
strcpy((char *)(pBuffer + (4 * sizeof(int))),(char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int)))))));
*(int *)(pBuffer + (4 * sizeof(int) + 10))=*(int *)(pBuffer + (10+(5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int))))));
strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int)))))),(char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2*sizeof(int)))))));
*(int *)(pBuffer + (10+(5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (sizeof(int))))))=*(int *)(pBuffer + (10+(5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2*sizeof(int))))));
strcpy((char *)(pBuffer + ((5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2*sizeof(int)))))),(char *)(pBuffer + (4 * sizeof(int))));
*(int *)(pBuffer + (10+(5 * sizeof(int)) + (10 * sizeof(char)) + (10 * sizeof(char) + sizeof(int)) * (*(int *)(pBuffer + (2*sizeof(int))))))=*(int *)(pBuffer + (4 * sizeof(int) + 10));
*(int *)(pBuffer + (sizeof(int)))= *(int *)(pBuffer + (sizeof(int))) + 1;
*(int *)(pBuffer + (2 * sizeof(int))) = *(int *)(pBuffer + (2 * sizeof(int))) - 1;
}
}while(*(int *)(pBuffer + (sizeof(int)))<=*(int *)(pBuffer + (2 * sizeof(int))));
if(left<*(int *)(pBuffer + (2 * sizeof(int)))){
  quick(pBuffer,left,*(int *)(pBuffer + (2 * sizeof(int))));
}
if(*(int *)(pBuffer + (sizeof(int)))<right){
  quick(pBuffer,*(int *)(pBuffer + (sizeof(int))),right);
}

}