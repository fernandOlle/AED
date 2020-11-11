#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char linha[80];
    printf("Digite uma frase de ate 80caracteres: ");
    gets(linha);
    char * substr = strtok(linha, " ");
    printf("\n");
    while(substr != NULL){
        printf(" %s\n", substr);
        substr = strtok(NULL, " ");
    }
    return 0;
}