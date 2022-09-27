#include "doubly.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  struct doublylista *lista = inicializar();

  inserirElementoNoInicio(lista, 1);
  inserirElementoNoInicio(lista, 3);
  inserirElementoNoInicio(lista, 4);
  imprimirLista(lista);
  printf("\n\n");

  inserirElementoNoFim(lista, 5);
  inserirElementoNoFim(lista, 8);
  imprimirLista(lista);
  printf("\n\n");

  inserirElementoEmPosicao(lista, 69, 1);
  imprimirLista(lista);
  printf("\n\n");

  obterElementoEmPosicao(lista,4);
  printf("\n\n");

  removerElementoEmPosicao(lista,4);
  printf("\n\n");
  imprimirLista(lista);

  inverterLista(lista);
  printf("\n Lista inversa: ");
  imprimirLista(lista);

  free(lista);
}