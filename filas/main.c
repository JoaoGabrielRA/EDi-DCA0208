#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
int main(){

struct arrayqueue *fila = inicializar(10);
for(int i=0;i<10;i++){
enfileirar(&fila,i);
}
desenfileirar(fila);
printf("\n");
enfileirar(&fila,69);
printf("\n");
for(int i=0;i<10;i++){
printf("%d\n",fila->elementos[i]);
}
}

