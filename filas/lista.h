#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct arrayqueue {
    int frente;
    int tras;
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array    
};

struct arrayqueue* inicializar(int tamArray) {
    struct arrayqueue *fila = (struct arrayqueue*)malloc(sizeof(struct arrayqueue));
    fila->frente=-1;
    fila->tras=-1;
    fila->tamanho=tamArray;
    fila->qtdade=0;
    fila->elementos = (int *)calloc(tamArray,sizeof(int));
    return fila;
}
//se a fila estiver nula, instancie a fila com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arrayqueue**
//se a fila encher, simplesmente não enfileire
void enfileirar(struct arrayqueue** fila, int val) {
    if((*fila) == NULL){
        (*fila) = inicializar(10);
    }
      //  (*fila)->elementos[(*fila)->qtdade] = val;
       // (*fila)->tras++;
        // (*fila)->qtdade++;
    //if(((*fila)->qtdade) == (*fila)->tamanho){
     //   duplicarCapacidade((*fila));
   // }
     if(frente((*fila)) == false){
        (*fila)->frente=0;
        (*fila)->tras=0;
        (*fila)->elementos[(*fila)->frente] = val;
        (*fila)->qtdade = 1;
    }else if((((*fila)->tras)+1)%((*fila)->tamanho) == (*fila)->frente){
        printf("Array cheio!");
        exit(0);
    }
    else{
        (*fila)->tras = ((*fila)->tras+1)%((*fila)->tamanho);
        (*fila)->elementos[(*fila)->tras] = val;
        (*fila)->qtdade++; 
        }
         printf("Valor enfileirado: %d\n" ,  (*fila)->elementos[(*fila)->tras]);
    }


//retorne a constante INT_MIN se a fila for nula ou vazia
int desenfileirar(struct arrayqueue* fila) {
    if(frente((fila)) == false){ printf("Fila vazia!"); exit(0); }
    if((fila)->frente == (fila)->tras){
          printf("fila vazia!");
          exit(0);
   }else{
      printf("valor desemfileirado %d",(fila->elementos[fila->frente]));
        fila->frente =((fila->frente) + 1 )% (fila->tamanho) ;
        fila->qtdade--;
    }
    
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct arrayqueue* fila) {
    if((fila->frente == -1 && fila->tras == -1 )){
        return false;
    }else{
        return true;
    }

}