#include "linkedstack.h"

#include <stdio.h>
#include <stdlib.h>

int main() {

  struct linkedstack *pilha = inicializar();

  empilhar(pilha,1);
  empilhar(pilha,2);
  empilhar(pilha,3);
  
  exibirPilha(pilha);
  free(pilha);
  return 0;
}