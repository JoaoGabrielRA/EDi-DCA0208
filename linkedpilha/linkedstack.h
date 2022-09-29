#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct no{
    int val;
    struct no *prox;
};

struct linkedstack {
    struct no* topo;
    int qtdade;
};

struct linkedstack* inicializar() {
    struct linkedstack *pilha = (struct linkedstack*)malloc(sizeof(struct linkedstack));
    pilha->qtdade = 0;
    pilha->topo = 0;
    return pilha;
}

struct no* alocarNovoNo(int valor){
    struct no *novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->val =0;
    novoNo->prox = 0;
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct linkedstack* pilha) {
    if(pilha->qtdade > 0){
        return false;
    }else{
        return true;
    }
}

//se a pilha estiver nula, instancie a pilha
//por causa da possibilidade de instanciacao usamos struct linkedstack**
void empilhar(struct linkedstack** pilha, int valor){
     
    if((*pilha)->qtdade == 0){
        struct no * novoNo = alocarNovoNo(valor);
        novoNo->prox = (*pilha)->topo;
        (*pilha)->topo = novoNo;
       printf("valor %d empilhado", novoNo->val);
       (*pilha)->qtdade++;
    }else{
        struct no *aux = (*pilha)->topo;
        aux->prox = alocarNovoNo(valor); 
        printf("valor %d empilhado", valor);
        (*pilha)->qtdade++;
    }
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct linkedstack* pilha) {
    //TODO
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct linkedstack* pilha) {
    //TODO
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct linkedstack* pilha){
    //TODO
}

void exibirPilha(struct linkedstack* pilha) {
    //usamos o aux para percorrer a lista
    if (!vazia(pilha)) {
        struct no* aux = pilha->topo;
        //navega partindo do topo até chegar NULL
        printf("_\n");
        do {
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while (aux != NULL);
        printf("_");
    }
    else {
        printf("A pilha está vazia!");
    }
}