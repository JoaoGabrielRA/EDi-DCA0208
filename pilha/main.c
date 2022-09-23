#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
int main(){

struct arraystack *pilha = inicializar(10);
empilhar(&pilha,1);
empilhar(&pilha,2);
empilhar(&pilha,3);
imprimir(pilha);
desempilhar(pilha);
imprimir(pilha);
printf("\n\n");

printf("valor desempilhado = %d",desempilharRetornando(pilha));
imprimir(pilha);
printf("\n\n");
empilhar(&pilha,5);
imprimir(pilha);
printf("\n\n");
printf("valor desempilhado = %d",desempilharRetornando(pilha));
imprimir(pilha);
free(pilha); 
}