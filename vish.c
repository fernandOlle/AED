#include  <stdio.h>
#include  <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/**	Índices do buffer virtual:
 * pBuffer+0 = variável de auxílio
 * pBuffer+sizeof(int) = tamanho do buffer
 * pBuffer+2*sizeof(int) = quantidade de nomes cadastrados na agenda
 * pBuffer+3*sizeof(int) = variável de índice para laços de repetição
 * pBuffer+4*sizeof(int) = segunda variável de índice para laços de repetição
 * pBuffer+5*sizeof(int) = começo dos dados da agenda
 * */

//------------------------------Variáveis e Tipos

typedef struct P
{
	char nome[30];
	int identidade;
}Pessoa;

void *pBuffer;

//------------------------------Funções
void Organizar(int **p, int **q, int **r, int **s, int **t)
{
	*p=pBuffer+0;
	*q=pBuffer+sizeof(int);
	*r=pBuffer+2*sizeof(int);
	*s=pBuffer+3*sizeof(int);
	*t=pBuffer+4*sizeof(int);
}

void InsertionSort()
{
    int *tmp=pBuffer+0*sizeof(int),*i=pBuffer+3*sizeof(int),*j=pBuffer+4*sizeof(int), *n=pBuffer+2*sizeof(int);
Pessoa *pessoa=pBuffer+5*sizeof(int);
	Pessoa *aux=pessoa+*n;

    for (*j=1; *j<*n; *j=*j+1)
    {
        *i=*j-1;
        strcpy(aux->nome,(pessoa+*j)->nome);
        *tmp=(pessoa+*j)->identidade;
        while ((*i>=0) && (*tmp < (pessoa+*i)->identidade))
        {
            strcpy((pessoa+*i+1)->nome,(pessoa+*i)->nome);
            (pessoa+*i+1)->identidade = (pessoa+*i)->identidade;
            *i=*i-1;
        }
        strcpy((pessoa+*i+1)->nome,aux->nome);
    (pessoa+*i+1)->identidade = *tmp;
    }
}


//------------------------------Métodos
void incluirPessoa()
{
    int *q=pBuffer+sizeof(int), *r=pBuffer+2*sizeof(int);
    Pessoa *pessoa=pBuffer+sizeof(int)*5;
    pessoa=pessoa+*r;

	printf("Digite o nome: ");
	getchar();
    fgets(pessoa->nome, 30, stdin);
	pessoa->identidade=(int)*pessoa->nome;

    *r=*r+1;
    *q=(*r+1)*sizeof(Pessoa)+5*sizeof(int);
    pBuffer=realloc(pBuffer,*q);
}

void apagarPessoa()
{
	int *i=pBuffer+3*sizeof(int), *r=pBuffer+2*sizeof(int);
	Pessoa *pessoa=pBuffer+5;
	Pessoa *alguem=pessoa+*r;
	printf("Digite o nome: ");
	getchar();
	fgets(alguem->nome, 30, stdin);
	for (*i=0; *i<=*r; (*i)++)
	{
		pessoa=pBuffer+5*sizeof(int);
	if (*i == *r)
			printf("Não há ninguém com este nome.\n");
		else
        {
			pessoa=pessoa+*i;
			if (strcmp(alguem->nome,pessoa->nome) == 0)
			{
				pessoa->identidade=999;
				InsertionSort();
				printf("Excluído com sucesso!\n");
				*r=*r-1;
				return;
			}
        }
	}
}

void buscarPessoa()
{
	int *i=pBuffer+3*sizeof(int), *r=pBuffer+2*sizeof(int);
	Pessoa *pessoa=pBuffer+5;
	Pessoa *alguem=pessoa+*r;
	printf("Digite o nome: ");
	getchar();
	fgets(alguem->nome, 30, stdin);
	for (*i=0; *i<=*r; (*i)++)
	{
		pessoa=pBuffer+5*sizeof(int);
		if (*i == *r)
			printf("Não há ninguém com este nome.\n");
		else
        {
            pessoa=pessoa+*i;
			if (strcmp(alguem->nome,pessoa->nome) == 0)
			{
                printf("%s", pessoa->nome);
                printf("Código de identificação: %d\n", pessoa->identidade);
				return;
			}
        }
	}
}

void listarPessoa()
{
	int *i=pBuffer+3*sizeof(int), *r=pBuffer+2*sizeof(int);
	Pessoa *pessoa;
	for (*i=0; *i<=*r; (*i)++)
	{
		pessoa=pBuffer+5*sizeof(int);
		if (*i == *r)
			break;
		else
		{
			pessoa=pessoa+*i;
			printf("%s", pessoa->nome);
			printf("Código de identificação: %d\n", pessoa->identidade);
		}
	}
}

void Sair()
{
	free(pBuffer);
	printf("\nObrigado! Um dia esta agenda irá salvar todos os nomes em um arquivo, portanto fique atento. Volte sempre!");
}

//------------------------------Main
void main()
{
	printf("Bem-vindo a Agenda de KDOXG. \nCarregando...");
	int *p, *q, *r, *s, *t;
    pBuffer=malloc(sizeof(int)*5+sizeof(Pessoa));
	Organizar(&p,&q,&r,&s,&t);
	*p=0;
	*q=0;
	*r=0;

	printf("\n------------------------------");
	printf("\n\nDigite sua escolha...\n1 para incluir...\n2 para excluir...\n3 para buscar...\n4 para listar...\n5 para sair...\nCaso escolha outro valor, nada acontecerá");
	Inicio: Organizar(&p,&q,&r,&s,&t);
	printf("\n\nDigite: ");
	scanf("%d", s);

	switch (*s)
	{
		case 1:
			incluirPessoa();
			Organizar(&p,&q,&r,&s,&t);
			if (*r > 1)
				InsertionSort();
			printf("Pessoa incluída! Use o 'Buscar' para ver seu código de identificação.\n");
			goto Inicio;
			pBuffer=pBuffer;
		break;
		case 2:
			apagarPessoa();
    		*q=(*r+1)*sizeof(Pessoa)+5*sizeof(int);
    		pBuffer=realloc(pBuffer,*q);
			goto Inicio;
			pBuffer=pBuffer;
		break;
		case 3:
			buscarPessoa();
			goto Inicio;
			pBuffer=pBuffer;
		break;
		case 4:
			listarPessoa();
			printf("Total de pessoas: %d", *r);
			goto Inicio;
			pBuffer=pBuffer;
		break;
		case 5:
			Sair();
		break;
		default:
			goto Inicio;
			pBuffer=pBuffer;
        break;
	}
}