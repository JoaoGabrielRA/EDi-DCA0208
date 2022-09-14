#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>

int main() {

  struct linkedlist *listaligada = inicializar();
  inserirElementoNoFim(listaligada, 10);
  inserirElementoNoFim(listaligada, 127);
  inserirElementoNoFim(listaligada, 115);
  imprimirlistaligada(listaligada);
  printf("\n");
  imprimirlistaligada(listaligada);
  printf("\n");
  inserirElementoNoInicio(listaligada, 5);
  printf("\n");
  imprimirlistaligada(listaligada);
  printf("\n");
  inserirElementoEmPosicao(listaligada, 25, 2); 
  imprimirlistaligada(listaligada);
  printf("\n");
  //obterElementoEmPosicao(listaligada, 1);
  removerElementoEmPosicao(listaligada,2);
  imprimirlistaligada(listaligada);
  free(listaligada);
  return 0;
}