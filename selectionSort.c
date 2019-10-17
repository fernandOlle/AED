#include  <stdio.h>
#include <string.h> 

typedef struct pessoa{
	int Matricula;
	char Nome[30];
	float Nota;
}pessoa;

void ordena ( pessoa * vet );
void IinsertionSort ( pessoa * vet );
void SinsertionSort ( pessoa * vet );
void imprimir ( pessoa * vet );
void FinsertionSort ( pessoa * vet);

int main ( ) {
	pessoa vet[3];
	int i = 0;

	ordena ( vet );
	
	return 0;
}

void ordena ( pessoa * vet ) {
	int i;

	scanf ("%d", &i); 
	
	switch ( i ) {
		case 1:
			for ( i = 0; i < 3; i ++ ){
				scanf ("%d", &vet[i]. Matricula );
				scanf ("%s", vet[i]. Nome);
				scanf ("%f", &vet[i]. Nota);
			}
			IinsertionSort ( vet );
			imprimir (vet);
			break;
		case 2:
			for ( i = 0; i < 3; i ++ ){
				scanf ("%d", &vet[i]. Matricula );
				scanf ("%s", vet[i]. Nome);
				scanf ("%f", &vet[i]. Nota);
			}
			SinsertionSort ( vet );
			imprimir (vet);
			break;
		case 3:
			for ( i = 0; i < 3; i ++ ){
				scanf ("%d", &vet[i]. Matricula );
				scanf ("%s", vet[i]. Nome);
				scanf ("%f", &vet[i]. Nota);
			}
			FinsertionSort ( vet );
			imprimir (vet);
			break;
		default:
			break;
	}
}

void imprimir ( pessoa * vet ) {
	for ( int i = 0; i < 3; i ++ ){
		printf ("\n");
		printf ("\n");
		printf ("%d \n", vet[i]. Matricula );
		printf ("%s \n", vet[i]. Nome);
		printf ("%f\n", vet[i]. Nota);
	}
}
void IinsertionSort ( pessoa * vet ) {
	int i, j, min;
	pessoa temp;

    for ( i = 0; i < 3; i ++ ) {
        min = i;
        for ( j = i +1; j < 3; j ++ ){
            if ( vet[min]. Matricula > vet[j]. Matricula ) {
                min = j;
            }
        }
        temp = vet[i];
        vet[i] = vet[min];
        vet[min] = temp;
    }
}
void FinsertionSort ( pessoa * vet) {
	int i, j, min;
	pessoa temp;

    for ( i = 0; i < 3; i ++ ) {
        min = i;
        for ( j = i +1; j < 3; j ++ ){
            if ( vet[min]. Nota > vet[j]. Nota ) {
                min = j;
            }
        }
        temp = vet[i];
        vet[i] = vet[min];
        vet[min] = temp;
    }
}
void SinsertionSort ( pessoa * vet) {
	int i, j, min;
	pessoa temp;

    for ( i = 0; i < 3; i ++ ) {
        min = i;
        for ( j = i +1; j < 3; j ++ ){
            if ( strcmp (vet[min]. Nome, vet[j]. Nome) > 0 ) {
                min = j;
            }
        }
        temp = vet[i];
        vet[i] = vet[min];
        vet[min] = temp;
    }
}
		 