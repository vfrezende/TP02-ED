#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pilha.h"
#include "utilidades.h"

#define QUICKSORT_INSERCAO1 "QI1"
#define QUICKSORT_INSERCAO5 "QI5"
#define QUICKSORT_INSERCAO10 "QI10"
#define QUICKSORT_MEDIANA "QM3"
#define QUICKSORT_CLASSICO "QC"
#define QUICKSORT_PRIMEIRO "QPE"
#define QUICKSORT_ITERATIVO "QNR"

#define ALEATORIO "Ale"
#define CRESCENTE "OrdC"
#define DECRESCENTE "OrdD"

#define FLAG "-p"

// variáveis globais criadas para retornar valores de comparações entre chaves
// e de movimentações de chaves respectivamente.
static long comp, mov = 0;


//seleciona a variação do quicksort desejada.
void quicksort(int *V, const int k, const char *quick_var);

//algoritmo de ordenação usado nos casos 4, 5 e 6 do problema
void insercao(int *V, int esq, int dir);

//função que ordena os sub-vetores criados a partir do particiona
//(mesmo funcionamento para tods quicksorts implementados de forma recursiva)
void ordena_central(int *V, int esq, int dir);
void ordena_mediana(int *V, int esq, int dir);
void ordena_primeiro(int *V, int esq, int dir);
void ordena_1porcento(int *V, int esq, int dir, int tam);
void ordena_5porcento(int *V, int esq, int dir, int tam);
void ordena_10porcento(int *V, int esq, int dir, int tam);

// chama os procedimentos ordena e partição para e coordena a execução geral da função
//(mesmo funcionamento para tods quicksorts implementados de forma recursiva)
void quicksort_central(int *V, int k);
void quicksort_mediana(int *V, int k);
void quicksort_primeiro(int *V, int k);
void quicksort_1porcento(int *V, int k);
void quicksort_5porcento(int *V, int k);
void quicksort_10porcento(int *V, int k);
void quicksort_iterativo(int *V, int k);

//Particiona implementado para caso 1 pivor central
void particiona_central(int *V, int esq, int dir, int *i, int *j);

//Particiona implementado para o caso 2 pivor mediana de três(esquerda, centro e direita)
void particiona_mediana(int *V, int inicio, int fim, int *i, int *j);

//Particiona implementado para caso 3 pivor sendo elemento mais a esquerda do vetor
void particiona_primeiro(int *V, int esq, int dir, int *i, int *j);

//pega os valores de comparacoes e movimentacoes
long get_mov();
long get_comp();

// zera os valores de comparacoes e movimentacoes
void zera_mov();
void zera_comp();

#endif