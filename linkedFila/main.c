#include <stdio.h>
#include <stdlib.h>

#include "linkedfila.h"

int main(){

    struct linkedqueue *fila = inicializar();
    enfileirar(&fila,1);
    enfileirar(&fila,2);
    enfileirar(&fila,3);
    enfileirar(&fila,4);
    enfileirar(&fila,5);

    desenfileirar(fila);


    free(fila);
}