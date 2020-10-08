#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) {
  int i = 0;
  char * charVector = (char * ) malloc(sizeof(char)); 
  char * auxVector;
  int lenght = 0;
  int auxLenght = 1;
  int nameLenght;
  int nameCounter = 0;
  char name[50];
  char c;

  int x, y, z;

  while ( 284 ) {
    printf ( "adicionar = 1\nremover = 2\nlistar = 3\nsair = 4\n" );
    scanf ( "%d", &i );
    getchar ( );
    printf ( "\n" );
    x = z = y = 0;

    nameLenght =  0;
    switch ( i ) {
      case 1:
        while ( ( c = getchar ( ) ) != '\n' ) {
          name[nameLenght] = c;
          nameLenght ++;
        }
        name[nameLenght] = '\0';

        auxLenght = nameLenght;
        lenght += nameLenght;
        charVector = (char *) realloc(charVector, sizeof(char) *lenght +2);

        nameLenght =  0;
        charVector[lenght -auxLenght] = '*';
        while (auxLenght > 0) {
          charVector[1 +lenght -auxLenght] = name[nameLenght];
          auxLenght --;
          nameLenght ++;
        }
        charVector[lenght +1] = '\0';
        nameLenght =  0;
        lenght ++;
        nameCounter ++;
      break;
      
      case 2:
        x =1;
        name[0] = '*';
        while ( ( c = getchar () ) != '\n' ) {
          name[x] = c;
          x ++;
        }
        name[x] = '\0';

        y = 0;
        while ( ( (auxVector) = (strstr(charVector, name)) ) ) {
          *(auxVector) = '\0';
          strcat(charVector, auxVector +x);
          if ( charVector[0] == '\0' )
            charVector[0] = '*';
          else if ( lenght >= x )
            lenght = lenght -x;
          else 
            lenght = 2;
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
        free ( auxVector );
        return 0;
      break;

      default:
      break;
    }
  }
}