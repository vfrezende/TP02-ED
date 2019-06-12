#ifndef PILHA_H
#define PILHA_H

#include <stdlib.h>
#include <stdio.h>

typedef int TipoChave;

typedef struct {
	TipoChave Esq;
	TipoChave Dir;
}TipoItem;

typedef struct Celula_str *Apontador; 

typedef struct Celula_str{
	TipoItem Item;
	Apontador Prox;
}Celula;

typedef struct {
	Apontador Fundo, Topo;
	int Tamanho;
}TipoPilha;


void FPVazia(TipoPilha *Pilha);
void Empilha(TipoItem x, TipoPilha *Pilha);

int Desempilha(TipoPilha *Pilha, TipoItem *item);
int Vazia(const TipoPilha *Pilha);

#endif
