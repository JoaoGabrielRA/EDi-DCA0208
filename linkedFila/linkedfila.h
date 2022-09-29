#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedqueue {
    struct no* frente;
    struct no* tras;
    int qtdade;
};

struct linkedqueue* inicializar() {
    struct linkedqueue *fila = (struct linkedqueue*)malloc(sizeof(struct linkedqueue));
    fila->frente = NULL;
    fila->tras = NULL;
    fila->qtdade = 0;
    return fila;
}

struct no* alocarNovoNo(int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->prox = 0;
    novoNo->val = valor;
    return novoNo;
}

bool vazia(struct linkedqueue* fila) {
    if(fila->qtdade == 0){
        return true;
    }else{
        return false;
    }
}

//se a fila estiver nula, instancie a fila
//por causa da possibilidade de instanciacao usamos struct linkedqueue**
void enfileirar(struct linkedqueue** fila, int val) {
    struct no* novoNo = alocarNovoNo(val);
    if(vazia(*fila) == true){
        (*fila)->tras = novoNo;
        (*fila)->frente = novoNo;
        (*fila)->qtdade = 1;
         printf("primeiro valor enfileirado:%d \n", (*fila)->tras->val);
    }else{
        (*fila)->tras->prox = novoNo;
        (*fila)->tras = novoNo;
        (*fila)->qtdade++;
        printf("%d valor enfileirado:%d \n", (*fila)->qtdade, (*fila)->tras->val);
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
//lembrem de desalocar o n� removido (free)
int desenfileirar(struct linkedqueue* fila) {
    struct no *aux = fila->frente;
    printf("Valor desenfileriado: %d", fila->frente->val);
    fila->frente = fila->frente->prox;
    free(aux);
    fila->qtdade--;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct linkedqueue* fila) {
    if(fila == NULL || fila->qtdade ==0){
        printf("FILA VAZIA");
    }
}