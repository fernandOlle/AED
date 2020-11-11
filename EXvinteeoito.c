#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct agenda{
    char nome[10];
    int telefone;
}agenda;

typedef struct var{
    int i, Npessoas, op, j, compint;
    char comp[10];
}var;

void *pbuffer;
var *aux;
agenda *aponta;
agenda *apontaaux;

void Insere ();
void Imprimir ();
void Buscar ();
void Deletar ();

int main (){

    pbuffer = malloc(sizeof(var));
    if(pbuffer == NULL){
        printf("\nERRO\n");
        free(pbuffer);
        exit(-1);
    }
    aux = pbuffer;
    aux->op = 0;
    aux->Npessoas = 0;
    aux->i = 0;
    aux->j = 0;


    while(284){
        printf("\nAgenda: \n1: Insere\n2: Lista\n3: Busca\n4: Apaga\n5: SAIR: ");
        scanf("%d", &aux->op);
        getchar();

        switch (aux->op){
            case 1: (aux->Npessoas)++;
            Insere();
            break;

            case 2: if(aux->Npessoas == 0){
                        printf("\nVAZIO\n");
                    }else{
                        Imprimir();
                    }
            break;

            case 3: if(aux->Npessoas == 0){
                        printf("\nVAZIO\n");
                    }else{
                        Buscar();
                    }
            break;

            case 4: if(aux->Npessoas == 0){
                        printf("\nVAZIO\n");
                    }else{
                        Deletar();
                    }
            break;

            case 5:
            free(pbuffer);
            exit(0);
            break;

            default:
            printf("\nOp. Invalida\n");
            break;
        }
    }
    return 0;
}
void Insere (){
    pbuffer = realloc(pbuffer, sizeof(var) + sizeof(agenda)*(aux->Npessoas));
    aux = pbuffer;
    aponta = pbuffer + sizeof(var) + sizeof(agenda)*(aux->Npessoas) - sizeof(agenda);
    printf("\nDigite um nome: ");
    scanf("%s", aponta->nome);
    printf("Digite um telefone: ");
    scanf("%d", &aponta->telefone);
}

void Imprimir (){
    aponta = pbuffer + sizeof(var);
    for (aux->i = 0; (aux->i)<(aux->Npessoas); (aux->i)++){
        printf("\nNome: %s\n", aponta->nome);
        printf("Telefone: %d\n", aponta->telefone);
        aponta++;
    }
}

void Buscar (){
	printf("\nDigite um nome para Buscar: ");
	scanf("%s", aux->comp);
    if(aux->comp == NULL){
        printf("\nERRO\n");
        free(pbuffer);
        exit(-1);
    }
	for(aux->i = 0; (aux->i)<(aux->Npessoas); (aux->i)++ ){
        aponta = pbuffer + sizeof(var);
        aponta += aux->i;
		if(strcmp(aux->comp, aponta->nome) == 0){
        printf("\nNome: %s\n", aponta->nome);
        printf("Telefone: %d\n", aponta->telefone);
        return;
		}else{
            printf("\nNome nao encontrado\n");
        }
	}
}

void Deletar(){
	printf("\nDigite um nome para Deletar: ");
	scanf("%s", aux->comp);
	for(aux->i = 0; (aux->i)<=(aux->Npessoas); (aux->i)++ ){
        aponta = pbuffer + sizeof(var);
        aponta += aux->i;
        apontaaux = pbuffer + sizeof(var);

        if(aux->i == aux->Npessoas){
            printf("\nNome invalido\n");
            break;
        }
        if(strcmp(aux->comp, aponta->nome) == 0){
            while(aux->i < aux->Npessoas){
                aponta = pbuffer + sizeof(var);
                aponta += aux->i;
                apontaaux = pbuffer + sizeof(var);
                apontaaux += aux->i + 1;
                strcpy(aponta->nome, apontaaux->nome);
                aponta->telefone = apontaaux->telefone;
                (aux->i)++;
            }
            (aux->Npessoas)--;
            pbuffer = realloc(pbuffer, sizeof(var) + sizeof(agenda)*(aux->Npessoas));
            return;
        }
	}
}