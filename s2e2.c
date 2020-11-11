#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
    char nome[30];
    int idade;
    int altura;
} Pessoa;

Pessoa *addPessoa(Pessoa *pessoas, int numPess);
void imprime(Pessoa *pessoas, int numPess);

int main()
{
    Pessoa *pessoas;
    pessoas = (Pessoa *)malloc(sizeof(Pessoa));

    int i = 0;
    int numPess = 1;

    while (i != 2)
    {
        i = 0;

        printf("\ninserir pessoa 1, sair 2\n");
        scanf("%d", &i);
        if (i == 1)
        {
            numPess++;
            pessoas = addPessoa(pessoas, numPess);
        }
    }

    if (numPess > 1)
        imprime(pessoas, numPess);

    free(pessoas);
    return 0;
}

Pessoa *addPessoa(Pessoa *pessoas, int numPess)
{
    Pessoa newPess;

    printf("\nentre nome : ");
    scanf("%s", newPess.nome);
    printf("\nentre idade : ");
    scanf("%d", &newPess.idade);
    printf("\nentre altura : ");
    scanf("%d", &newPess.altura);

    pessoas = (Pessoa *)realloc(pessoas, sizeof(Pessoa) * numPess - 1);
    pessoas[numPess - 2] = newPess;

    return pessoas;
}

void imprime(Pessoa *pessoas, int numPess)
{
    for (int i = 0; i < numPess - 1; i++)
    {
        printf("\n Pessoa #%d", i + 1);
        printf("\n Nome: %s", pessoas[i].nome);
        printf("\n Idade: %d", pessoas[i].idade);
        printf("\n Altura: %d", pessoas[i].altura);
        printf("\n\n");
    }
}