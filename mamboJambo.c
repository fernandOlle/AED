#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
  char c;
  char name[50];
  char * auxVector;
  char * charVector = (char * ) malloc(sizeof(char)); 
  int x;
  int i;
  int auxLenght;
  int nameLenght;
  int lenght = 0;
  int nameCounter = 0;


  while ( 284 ) {
    printf ( "adicionar = 1\nremover = 2\nlistar = 3\nsair = 4\n" );
    scanf ( "%d", &i );
    getchar ( );
    printf ( "\n" );
    x =  nameLenght = auxLenght = 0;

    nameLenght =  0;
    switch ( i ) {
      case 1:
        while ( ( c = getchar ( ) ) != '\n' ) 
          name[nameLenght ++] = c;
        
        name[nameLenght ++] = '*';
        name[nameLenght] = '\0';

        lenght += auxLenght = nameLenght;
        charVector = (char *) realloc(charVector, sizeof(char) *lenght +2);

        nameLenght =  0;
        while (auxLenght >= 0) 
          charVector[lenght -( auxLenght --)] = name[nameLenght ++];

        nameCounter ++;
      break;
      
      case 2:
        x = 0;
        while ( ( c = getchar () ) != '\n' )
          name[x ++] = c;
        
        if ( name[0] == '\0' )
          break; 

        name[x ++] = '*';
        name[x] = '\0';

        if ( ( (auxVector) = (strstr(charVector, name)) ) ) {
          *(auxVector) = '\0';
          strcat(charVector, auxVector +x);
          if ( lenght >= x )
            lenght = lenght -x;
          charVector = (char *) realloc( charVector, sizeof(char) * lenght );
        }
      break;

      case 3:
        while ( nameLenght < lenght ) {
          if ( charVector[nameLenght] == '*' ) 
            printf ( "\n" );
          else 
            printf  ( "%c", charVector[nameLenght] );
          nameLenght ++;
        }
        printf ("\n"); 
      break;
      
      case 4:
        free ( charVector );
        return 0;
      break;

      default:
      break;
    }
  }
  return 0;
}