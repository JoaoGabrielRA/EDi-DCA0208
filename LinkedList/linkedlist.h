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
  // TODO
}

void inserirElementoNoFim(struct linkedlist *listaligada, int valor) {
  if (listaligada->qtdade == 0) {
    listaligada->cabeca = (struct no *)malloc(sizeof(struct no)); //aloca primeiro nó;
    
    listaligada->cabeca->prox = 0; //atribui valor para o 0 para a "ultima" cabeca do nó;
    listaligada->cabeca->val = valor; //atribui o valor para o nó;
  } else {
    struct no *aux = listaligada->cabeca; //guarda o valor do proximo no;
    for (int i = 1; i < listaligada->qtdade; i++) {
      aux = aux->prox;
    } //caminha até a ultima posicao;
    aux->prox = (struct no *)malloc(sizeof(struct no));
    aux->prox->prox = 0;
    aux->prox->val = valor;
  }
  listaligada->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist *listaligada, int valor) {
  if(listaligada->qtdade <=0){
  printf("array vazio!");
    exit(0);
  }
  else{
    for(int i=0; i<1 ;i++){
      listaligada->cabeca->val = valor;
    }
  }
}

void inserirElementoEmPosicao(struct linkedlist *listaligada, int valor,int posicao) {
  if(posicao >= listaligada->qtdade || posicao < 0){
    printf("posicao inválida");
    exit(0);
  }
  else{
      struct no *aux = listaligada->cabeca;
      for(int i=0; i<posicao;i++){
        aux = aux->prox;
      }
    aux->val = valor;
  }
}

int obterElementoEmPosicao(struct linkedlist *listaligada, int posicao) {
  if(posicao >= listaligada->qtdade || posicao < 0){
    printf("posicao inválida");
    exit(0);
  }
  else{
      struct no *aux = listaligada->cabeca;
      for(int i=0; i < posicao; i++){
      aux = aux->prox;
      }
    printf("%d: ", aux->val);
  }
}

void removerElementoEmPosicao(struct linkedlist *listaligada, int posicao) {
  if(posicao > listaligada->qtdade || posicao <0){
    printf("Posição Inválida");
    exit(0);
  }
  else{
       struct no* aux = listaligada->cabeca;
    if (posicao == 0) {
        listaligada->cabeca = listaligada->cabeca->prox;
        free(aux);
        listaligada->qtdade--;
        return;
    }
    for (int i = 1; i < posicao; i++) {
        aux = aux->prox;
    }
    struct no* aux2 = aux->prox;
    aux->prox = aux->prox->prox;
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
