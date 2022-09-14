#include "Arraylist.h"

#include <stdio.h>
#include <stdlib.h>

int tamanho = 10;
int main(void) {
  /* ---- ARRAY LIST ----*/
  struct arraylist *lista = inicializar(tamanho);
  for (int i = 0; i < 10; i++) {
    inserirElementoNoFim(lista, i);
  }
  exibirLista(lista);
  printf("\n");
  printf("%d", obterElementoEmPosicao(lista, 3));
  printf("\n");
  inserirElementoNoFim(lista, 69);
  printf("\n");
  exibirLista(lista);
  printf("\n");
  inserirElementoEmPosicao(lista, 34, 4);
  exibirLista(lista);
  printf("\n");
  atualizarElemento(lista, 89, 1);
  exibirLista(lista);
  printf("\n");
  removerElementoEmPosicao(lista, 8);
  exibirLista(lista);
  printf("\n");
  removerElementoNoFim(lista);
  exibirLista(lista);
  printf("\n");
  exibirTamanho(lista);
  free(lista->vetor);
  free(lista);

  /* ---- FIM ARRAY LIST --*/
  
  return 0;
}