#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	int topo;
	int vetor [MAX];
} pilha;

void libera ( pilha*p ) {
	free(p);
}

pilha*cria () {
	pilha*p;
	p = ( pilha* ) malloc ( sizeof ( pilha ) );
	p->topo = -1;
	return p;
}

int vazia ( pilha *p ) {
	if(p->topo == -1){
		return 1;
	}
	else {
		return 0;
	}
}

int cheia ( pilha*p ) {
	if(p->topo == MAX -1){
		return 1;
	}
	else {
		return 0;
	}
}

void empilha ( pilha*p, int v) {
	p->topo++;
	p->vetor[p->topo] = v;
}

int desempilha ( pilha*p ) {
	int aux;
	aux = p->vetor[p->topo];
	p->topo--;
	return aux;
}

int main () {
	
	pilha*p;
	p = cria();
	
	int x;
	
	empilha( p, 10 );
	empilha( p, 20 );
	empilha( p, 30);
	empilha( p, 60 );
	
	x = desempilha ( p );
	printf("Elemento %d retirado", x);
	
	libera ( p );
	return 0;
}
