#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct arraystack {
    int* vetor;
    int capacidade;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arraystack* inicializar(int capacidade){
     struct arraystack *pilha =(struct arraystack *)malloc(sizeof(struct arraystack));
	  pilha->vetor = (int *)calloc(capacidade, sizeof(int));
	  pilha->qtdade = 0;
	  pilha->capacidade = capacidade;
	  return pilha;
}

void duplicarCapacidade(struct arraystack* pilha){
    pilha->vetor =(int *)realloc(pilha->vetor, 2 * pilha->capacidade * sizeof(int));
  pilha->capacidade = 2 * pilha->capacidade;
}


//se a pilha estiver nula, instancie a pilha com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arraystack**
//se a pilha encher, duplique a capacidade do array
void empilhar(struct arraystack** pilha, int valor){
	if((*pilha)->qtdade == 0){
		  (*pilha)->vetor[(*pilha)->qtdade] = valor; 
		  (*pilha)->qtdade++;
	}else{
	if ((*pilha)->qtdade == (*pilha)->capacidade) {
		duplicarCapacidade(*pilha);
	  }
	
		(*pilha)->vetor[(*pilha)->qtdade] = valor;
		(*pilha)->qtdade++;
	}
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct arraystack* pilha) {
    if(pilha->qtdade >0){
		return true;
	}else{
		return false;
	}
}

//decrementar qtdade se a pilha n�o estiver nula ou vazia
void desempilhar(struct arraystack* pilha){
    if(vazia(pilha) == true){
		pilha->qtdade--;
	}
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct arraystack* pilha){
	int valor;
   if(vazia(pilha) == false) {
	 printf("Pilha vazia");
   }else{
    
    valor = pilha->vetor[pilha->qtdade-1];
    desempilhar(pilha);
   }
   
   return valor;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct arraystack* pilha){
    if(vazia(pilha)){
        printf("A pilha esta vazia!");
        return -1;
    }else{
        return pilha->vetor[pilha->qtdade-1];
    }
}

void imprimir(struct arraystack* pilha){
    printf("_\n");
    for(int i = pilha->qtdade - 1; i >= 0; i--){
        printf("%d\n",pilha->vetor[i]);
    }
    printf("_\n\n");
}