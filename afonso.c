

void barra1 (int hp, int dano) {
  int aux = calculaDanoPoHp(hp, dano);
  if(aux == 500)
  printf("HP[||||||||||] - %d",aux);
  else if(aux == 450)
  printf("HP[|||||||||#] - %d",aux);
  else if(aux == 400)
  printf("HP[||||||||##] - %d",aux);
  else if(aux == 350)
  printf("HP[|||||||###] - %d",aux);
  else if(aux == 300)
  printf("HP[||||||####] - %d",aux);
  else if(aux == 250)
  printf("HP[|||||#####] - %d",aux);
  else if(aux == 200)
  printf("HP[||||######] - %d",aux);
  else if(aux == 150)
  printf("HP[|||#######] - %d",aux);
  else if(aux == 100)
  printf("HP[||########] - %d",aux);
  else if(aux == 50)
  printf("HP[|#########] - %d",aux);
  else if(aux == 0)
  printf("HP[##########] - %d",hp);
}

float calculaDanoPorHp (int hp, int dano) {
  if (hp < 500) {
    float porcentagem = (100*dano)/hp;
    float danoReal = (500*porcentagem)/100

    return danoReal;

  } else if ( hp > 500 ) {

  } else return dano;
}