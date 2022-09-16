#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

int main() {

  struct linkedlist *listaligada = inicializar();

  inserirElementoNoFim(listaligada, 1);
  printf("foi - ");
  imprimirlistaligada(listaligada);

  printf("\n");

  inserirElementoNoFim(listaligada, 2);
  printf("foi - ");
  imprimirlistaligada(listaligada);

  printf("\n");

  inserirElementoNoFim(listaligada, 3);
  printf("foi - ");
  imprimirlistaligada(listaligada);
  printf("\n");

  inserirElementoNoInicio(listaligada, 5);

  printf("foi - ");
  imprimirlistaligada(listaligada);
  printf("\n");
  printf("quantidade de elementos em cima: %d", listaligada->qtdade);
  printf("\n");

  inserirElementoEmPosicao(listaligada, 25, 0);
  printf("foi - ");
  imprimirlistaligada(listaligada);
  printf("\n");
  printf("quantidade de elementos em cima: %d", listaligada->qtdade);
  printf("\n");

  inserirElementoEmPosicao(listaligada, 22, 4);
  printf("foi - ");
  imprimirlistaligada(listaligada);
  printf("foi - ");
  printf("\n");
  printf("quantidade de elementos: %d", listaligada->qtdade);
  printf("\n");

  obterElementoEmPosicao(listaligada, 2);
  printf("\n");
  
  removerElementoEmPosicao(listaligada, 2);
  imprimirlistaligada(listaligada);
  printf("\n");
  printf("quantidade de elementos em cima: %d", listaligada->qtdade);
  printf("\n");

  inserirElementoNoInicio(listaligada,7);
  imprimirlistaligada(listaligada);
  printf("\n");
  printf("quantidade de elementos em cima: %d", listaligada->qtdade);
  
  free(listaligada);
  return 0;
}
