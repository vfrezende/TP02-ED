#include "pilha.h"

void FPVazia(TipoPilha *Pilha){
	Pilha->Topo = (Apontador) malloc(sizeof(Celula));
	Pilha->Fundo = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;
}


void Empilha(TipoItem x, TipoPilha *Pilha){
	Apontador Aux;
	Aux = (Apontador) malloc(sizeof(Celula));
	Pilha->Topo->Item = x;
	Aux->Prox = Pilha->Topo;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}

int Desempilha(TipoPilha *Pilha, TipoItem *item){
	Apontador q;
	if (Vazia(Pilha)){
		printf("Erro:pilha vazia\n"); 
		return 0;
	}
	q = Pilha->Topo;
	Pilha->Topo = q->Prox;
	free(q);
	Pilha->Tamanho--;
	*item = Pilha->Topo->Item; 
	return 1;
}

int Vazia(const TipoPilha *Pilha){
return (Pilha->Topo == Pilha->Fundo);
} 