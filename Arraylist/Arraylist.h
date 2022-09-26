#include <stdio.h>
#include <stdlib.h>

struct arraylist {
  int *vetor;
  int qtdade;
  int capacidade;
};

struct arraylist *inicializar(int capacidade) {
  struct arraylist *lista =
      (struct arraylist *)malloc(sizeof(struct arraylist));
  lista->vetor = (int *)calloc(capacidade, sizeof(int));
  lista->qtdade = 0;
  lista->capacidade = capacidade;
  return lista;
}

int obterElementoEmPosicao(struct arraylist *lista, int posicao) {
  if (posicao >= 0 && posicao < lista->qtdade) {
    return lista->vetor[posicao];
  }
}
void duplicarCapacidade(struct arraylist *lista) {
  lista->vetor =
      (int *)realloc(lista->vetor, 2 * lista->capacidade * sizeof(int));
  lista->capacidade = 2 * lista->capacidade;
}
/*void duplicarCapacidade(struct arraylist *lista) {
  int novaLista[2 * lista->capacidade];
  // printf("%d=", 2 * lista->capacidade);
  for (int i = 0; i < lista->capacidade; i++) {
    novaLista[i] = lista->vetor[i];
  }
  free(lista);
  lista = novaLista;
}*/

void inserirElementoNoFim(struct arraylist *lista, int valor) {
  if (lista->qtdade == lista->capacidade) {
    duplicarCapacidade(lista);
  }
  lista->vetor[lista->qtdade] = valor;
  lista->qtdade++;
}

void inserirElementoEmPosicao(struct arraylist *lista, int valor, int posicao) {
  if (posicao >= 0 && posicao <= lista->qtdade) {
    if (lista->qtdade == lista->capacidade) {
      duplicarCapacidade(lista);
    }
    for (int i = lista->qtdade; i > posicao; i--) {
      lista->vetor[i] = lista->vetor[i - 1];
    }
    lista->vetor[posicao] = valor;
    lista->qtdade++;
  }
}

void atualizarElemento(struct arraylist *lista, int valor, int posicao) {

  if (posicao > 0 && posicao < lista->qtdade) {
    lista->vetor[posicao] = valor;
  }
}

void removerElementoNoFim(struct arraylist *lista) { lista->qtdade--; }

void removerElementoEmPosicao(struct arraylist *lista, int posicao) {
  if (posicao >= 0 && posicao < lista->qtdade) {
    while (posicao < lista->qtdade - 1) {
      lista->vetor[posicao] = lista->vetor[posicao + 1];
      posicao++;
    }
    lista->qtdade--;
  }
}

int exibirTamanho(struct arraylist *lista) {
  int tamanho = lista->qtdade;

  printf("Tamanho da lista: %d", tamanho);
}

void inverterLista(struct arraylist *lista){

   int novaLista[lista->qtdade];
    int j = lista->qtdade;
  for (int i = 0 ; i < lista->qtdade; i++) {
    novaLista[i] = lista->vetor[j-1];
    j--;
    //printf("%d",novaLista[i]);
  }
  for(int i = 0; i< lista->qtdade ; i++){
    lista->vetor[i] = novaLista[i];
  }
}
void exibirLista(struct arraylist *lista) {
  printf("[");
  for (int i = 0; i < lista->qtdade; i++) {
    printf("%d", lista->vetor[i]);
    if (i < lista->qtdade - 1) {
      printf(", ");
    }
  }
  printf("]");
}