#include <stdio.h>
#include <stdlib.h>

int main ( ) {
  char string[80];
  char subString[80][80];
  int count = 0, vaifio = 0;

  for (int i = 0; i < 80; i ++)
    scanf("%c", &string[i]);

  for (int i = 0; i < 80; i ++, vaifio ++) {
    if ( string[i] == ' ' || string[i] == '\n' ) {
      subString[count][vaifio] = '\0';
      vaifio = -1;
      count ++;
    } else 
      subString[count][vaifio] = string[i];
  }

  for ( int i  = 0; i < count; i ++)
    printf ("%s\n", subString[i]);

  return 0;
}