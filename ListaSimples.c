#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char name[100];
    unsigned int id;
    struct list * next;
} list;

void setName ( char * name );
void setList ( list * head );
list *  __init__ ( );
void showList ( list * head );
void deleteList ( list * head );

int main ( ) {
    list * head;

    head = __init__ ( );

    int i = 1;

    while ( i ) {
        setList ( head );
        printf ( "\t\tflag" );
        scanf ( "%d", & i );
        getchar ( );
        showList ( head );
    }

    printf("%s", head-> name );

    deleteList ( head );
    return 0;
}
void setName ( char * name ) {
    char c;
    int i = 0; 

    printf ( "inset name : ");

    while ( ( c = getchar( ) ) != '\n' )
        name[ i ++ ] = c;

    name[ i ++ ] = '\0';
}
void setList ( list * head ) {
    list * new, * current;

    new = ( list * ) malloc ( sizeof ( list ) );
    new-> next = NULL;
    current = head;

    setName ( new-> name );
    printf ( "insert id : " );
    scanf ( "%d", & new-> id );    

    if ( current-> next ) 
        for ( ; current-> next && strcmp ( current-> next-> name, new-> name ) < 0 ; current = current-> next );
    
    new->next = current-> next;
    current-> next = new;
}
list *  __init__ ( ) {
    list * start;
    start = ( list * ) malloc ( sizeof ( list ) );
    start-> next = NULL;

    return start; 
}
void showList ( list * head ) {
    for ( head = head-> next ; head ; head = head-> next )
        printf ( "\n%s\t%d", head-> name, head-> id );

    printf ( "\n\n" );
}
void deleteList ( list * head ) {
    list * tmp;

    while ( head ) {
        tmp = head;
        head = head-> next;
        free ( tmp );
    }
}