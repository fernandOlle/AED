#include  <stdio.h>
#include <string.h> 

typedef struct pessoa{
	int Matricula;
	char Nome[30];
	float Nota;
}pessoa;

void ordena ( pessoa * vet );
void IFinsertionSort ( pessoa * vet );
void SinsertionSort ( pessoa * vet );
void imprimir ( pessoa * vet );

int main ( ) {
	pessoa vet[2];
	int i = 0;

	ordena ( vet );
	
	return 0;
}

void ordena ( pessoa * vet ) {
	int i;

	scanf ("%d", &i); 
	
	switch ( i ) {
		case 1:
			for ( i = 0; i < 2; i ++ ){
				scanf ("%d", &vet[i]. Matricula );
				scanf ("%s", vet[i]. Nome);
				scanf ("%f", &vet[i]. Nota);
			}
			IFinsertionSort ( vet );
			imprimir (vet);
			break;
		case 2:
			for ( i = 0; i < 2; i ++ ){
				scanf ("%d", &vet[i]. Matricula );
				scanf ("%s", vet[i]. Nome);
				scanf ("%f", &vet[i]. Nota);
			}
			SinsertionSort ( vet );
			imprimir (vet);
			break;
		case 3:
			for ( i = 0; i < 2; i ++ ){
				scanf ("%d", &vet[i]. Matricula );
				scanf ("%s", vet[i]. Nome);
				scanf ("%f", &vet[i]. Nota);
			}
			IFinsertionSort ( vet );
			imprimir (vet);
			break;
		default:
			break;
	}
}

void imprimir ( pessoa * vet ) {
	for ( int i = 0; i < 2; i ++ ){
		printf ("\n");
		printf ("\n");
		printf ("%d \n", vet[i]. Matricula );
		printf ("%s \n", vet[i]. Nome);
		printf ("%f\n", vet[i]. Nota);
	}
}
void IFinsertionSort ( pessoa * vet) {
	int i, j;
	pessoa temp;

	for ( i = 1; i < 2; i ++ ) {
		j = i -1;
		temp = vet[i];
		while ( j >= 0 && vet[j]. Matricula > temp. Matricula ) {
			vet[j+1] = vet[j];
			j --;
		} 
		vet[j+1] = temp; 
	}
}
void SinsertionSort ( pessoa * vet) {
	int i, j;
	pessoa temp;

	for ( i = 1; i < 2; i ++ ) {
		j = i -1;
		temp = vet[i];
		while ( j >= 0 && ( strcmp (vet[j]. Nome, temp. Nome) > 0 ) ) {
			vet[j+1] = vet[j];
			j --;
		} 
		vet[j+1] = temp; 
	}
}