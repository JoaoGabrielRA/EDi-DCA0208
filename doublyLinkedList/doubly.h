#include <stdio.h>
#include <stdlib.h>

struct no {
  struct no *ant;
  int val;
  struct no *prox;
};

struct doublylista {
  struct no *cabeca;
  struct no *cauda;
  int qtdade;
};

struct doublylista *inicializar() {
  struct doublylista *lista =
      (struct doublylista *)malloc(sizeof(struct doublylista));
  lista->cabeca = 0;
  lista->cauda = 0;
  lista->qtdade = 0;
  return lista;
}

struct no *alocarNovoNo(int valor) {
  struct no *novoNo = (struct no *)malloc(sizeof(struct no));
  novoNo->val = valor;
  novoNo->ant = 0;
  novoNo->prox = 0;
}

void inserirElementoNoInicio(struct doublylista *lista, int valor) {
  struct no *novoNo = alocarNovoNo(valor);
  if (lista->qtdade == 0) {
    lista->cabeca = novoNo;
    lista->cauda = novoNo;
  } else {
    struct no *aux = lista->cabeca;
    lista->cabeca = novoNo;
    novoNo->prox = aux;
  }
  lista->qtdade++;
  printf("Valor %d inserido no inicio\n", valor);
}

void inserirElementoNoFim(struct doublylista *lista, int valor) {
  struct no *novoNo = alocarNovoNo(valor);
  if (lista->qtdade == 0) {
    inserirElementoNoInicio(lista, valor);
  } else {
    struct no *aux = lista->cauda;
    lista->cauda = novoNo;
    novoNo->ant = aux;
    aux->prox = novoNo;
  }
  lista->qtdade++;
  printf("Valor %d inserido no fim\n", valor);
}

void inserirElementoEmPosicao(struct doublylista *lista, int valor,int posicao) {
  if (posicao > lista->qtdade || posicao < 0) {
    printf("POSICAO INVALIDA!");
  }
  if (lista->qtdade == 0) {
    inserirElementoNoInicio(lista, valor);
  } else {
    struct no *novoNo = alocarNovoNo(valor);
    struct no *aux = lista->cabeca;
    for (int i = 0; i < posicao - 1; i++) {
      aux = aux->prox;
    }
    novoNo->ant = aux;
    novoNo->prox = aux->prox;
    aux->prox = novoNo;
  }
  printf("Valor %d inserido na posicao %d\n", valor,posicao);
  lista->qtdade++;

}

int obterElementoEmPosicao(struct doublylista *lista, int posicao) {
  if(posicao > (lista->qtdade) || posicao <0){
    printf("Posição inválida");
  }
    struct no *aux = lista->cabeca;
    for(int i=0 ; i<posicao ;i++){
      aux = aux->prox;
    }
    printf("O valor da posicao %d corresponde a %d", posicao, aux->val);
}

void removerElementoEmPosicao(struct doublylista *lista, int posicao) {
  struct no *aux = lista->cabeca;
  for(int i = 0; i <posicao ;i++){
      aux = aux->prox;
  }
  aux->ant->prox = aux->prox;
  aux->prox->ant = aux->ant;
  printf("Elemento removido da posicao %d\n",posicao);
  free(aux);
}

void inverterLista(struct doublylista *lista){
    struct no* atual = lista->cabeca;
    struct no* aux = atual->prox;
    atual->prox = NULL;
    atual->ant = aux;

    while(aux != NULL){
        aux->ant = aux->prox;
        aux->prox = atual;
        atual = aux;
        aux = aux->ant;
    }

    lista->cabeca = atual;
}

void imprimirLista(struct no **cabeca) {
  // usamos o aux para percorrer a lista
  if ((*cabeca) != NULL) {
    struct no *aux = (*cabeca);
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
    printf("A lista está vazia!");
  }
}