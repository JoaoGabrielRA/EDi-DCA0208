#include <stdio.h>
#include <stdlib.h>

struct no {
  int val;
  struct no *prox;
};

struct linkedlist {
  struct no *cabeca;
  int qtdade;
};

struct linkedlist *inicializar() {

  struct linkedlist *listaligada =
      (struct linkedlist *)malloc(sizeof(struct linkedlist));
  listaligada->qtdade = 0;
  listaligada->cabeca = 0;
  return listaligada;
}

struct no *alocarNovoNo(int valor) {
  struct no *novoNo = (struct no *)malloc(sizeof(struct no));
  novoNo->val = valor;
  novoNo->prox = 0;
  return novoNo;
}

void inserirElementoNoFim(struct linkedlist *listaligada, int valor) {
  if (listaligada->qtdade == 0) {
    listaligada->cabeca = alocarNovoNo(valor); // aloca primeiro nó;
  } else {
    struct no *aux = listaligada->cabeca; // guarda o valor da cabeca;
    for (int i = 0; i < listaligada->qtdade - 1; i++) {
      aux = aux->prox;
      // caminha até a penultima posicao;
    }
    aux->prox = alocarNovoNo(valor);
  }
  listaligada->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist *listaligada, int valor) {

  struct no *novoNo = alocarNovoNo(valor);
  novoNo->prox = listaligada->cabeca;
  listaligada->cabeca = novoNo;

  listaligada->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist *listaligada, int valor,
                              int posicao) {
  if (posicao >= listaligada->qtdade || posicao < 0) {
    printf("posicao inválida");
    exit(0);
  }
  if (posicao == 0) {
    inserirElementoNoInicio(listaligada, valor);
  } else {
    struct no *aux = listaligada->cabeca;
    for (int i = 0; i < posicao-1; i++) {
      aux = aux->prox;
    }
    struct no *NovoNo = alocarNovoNo(valor);
    NovoNo->prox = aux->prox;
    aux->prox = NovoNo;
    listaligada->qtdade++;
  }
}

int obterElementoEmPosicao(struct linkedlist *listaligada, int posicao) {
  if (posicao > listaligada->qtdade || posicao < 0) {
    printf("posicao inválida");
    exit(0);
  } else {
    if (posicao == 0) {
      printf("O valor na posicao %d é %d", posicao, listaligada->cabeca->val);
    }
    struct no *aux = listaligada->cabeca;
    for (int i = 0; i < posicao; i++) {
      aux = aux->prox;
    }
    printf("O valor na posição %d corresponde a %d: ", posicao, aux->val);
  }
}

void removerElementoEmPosicao(struct linkedlist *listaligada, int posicao) {
  if (posicao > listaligada->qtdade || posicao < 0) {
    printf("Posição Inválida");
    exit(0);
  } else {
    struct no *aux = listaligada->cabeca;
    if (posicao == 0) {
      listaligada->cabeca = listaligada->cabeca->prox;
      free(aux);
      listaligada->qtdade--;
    }
    for (int i = 0; i < posicao - 1; i++) {
      aux = aux->prox;
    }
    struct no *aux2 = aux->prox;
    aux->prox = aux->prox->prox; // recebe 0;

    printf("Elementos com valor %d removido \n" , aux2->val);

    free(aux2);
    listaligada->qtdade--;
  }
}

void imprimirlistaligada(struct linkedlist *listaligada) {
  // usamos o aux para percorrer a lista
  if (listaligada->cabeca != NULL) {
    struct no *aux = listaligada->cabeca;
    // navega partindo da cabeça até chegar NULL
    printf("[");
    do {
      printf("%d", aux->val);
      aux = aux->prox;
      if (aux != NULL) {
        printf(", ");
      }
    } while (aux != NULL);
    printf("]");
  } else {
    printf("A listaligada está vazia!");
  }
}
