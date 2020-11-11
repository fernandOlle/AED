int F1 ( unsigned int n)
{
  if(n==0) return n;
  int i , j;
  for ( i = j = 1; i<=2 *n-1 ; i+=2 ){
    int aux = j +i ;
    for ( j = j +i; j < aux;  j++ );
  }
  j --;
  return j;
}

/*
  a) essa função eleva ao quadrado o numero inserido e o retorna em forma da variavel j 
  a) valor de j para 10 é 100
  c) implementada a cima
*/ 