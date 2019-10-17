#include  <stdio.h>
#include <stdlib.h>

int main ( ) {
    void * ptr;
                 /*
                    se eu fosse dar um malloc nesse 
                        ponteiro eu ja alocaria um double
                     |  pq cabe qualquer tipo (no caso de
                     |  eu querer usar ele pra varios tipos)
                    \./ e tbm não precisa/*não pode de cast.    
                    ptr = malloc ( sizeof ( double ) );
                */
    int i = 0;
    float f = 3.14;
    double d = 3.1400000;
    char c = 'A';
    char s [ 7 ] = "string";
    printf("♛ ");

    ptr = &i;
    printf ( "%i\n", * ( int * )ptr );
    
    ptr = &f;
    printf ( "%f\n", * ( float * ) ptr );

    ptr = &d;
    printf ( "%lf\n", * ( double * ) ptr );
    
    ptr = &c;
    printf ( "%c\n", * ( char * ) ptr );

    ptr = ( char * ) &s;
    printf ( "%s\n", ( char * ) ptr );

    return 0;
}