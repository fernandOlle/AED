#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *ordena_fig(int num_fig, int*fig);

int main () {

    int num_fig;
    int fig[5];
    int i;

    scanf("%d",&num_fig);

    for (i=0; i<num_fig; i++ )
        scanf("%d", &fig[i]);

    *fig=ordena_fig (num_fig, fig);

    for (  i = 0; i < num_fig; i++)
    {
        printf("%d\n", fig[i]);
    }
    

    return 0;
}

int *ordena_fig(int num_fig, int*fig) {
    int aux;
    for (int i=0; i<num_fig-1; i++) 
        for (int j=1; j<num_fig; j++)
           if ( fig[j]<fig[i] ) {
                aux = fig[i];
                fig[i]=fig[j];
                fig[j]=aux;
           }
    return fig;
}