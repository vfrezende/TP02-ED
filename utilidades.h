#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "Quick_Sort.h"

// função que realiza a troca das chaves
void troca(int *V, int i, int j);

// encontra a mediana entre 3 valores
int mediana(int esq, int meio, int dir);

// usado somente pra ordenar o vetor que guarda o tempo de execução (tamanho 20) para então retirar a mediana
void insertionSort(double array[], int tamanho);

// preenchimento do vetor de inicial de acordo com argv[2], que no caso é o tipo(crescente, decrescente ou aleatótio para certo tamanho k) 
void vec_aleatorio(int *V, int k);

void vec_ord_crescente(int *V, int k);

void vec_ord_decrescente(int *V, int k);


//void print_vector(int *V, int k);

//aloca uma matriz dinâmicamente onde serão guardados os vetores utilizados caso necessário mostralos no output
int** alocarMatriz(int Linhas,int Colunas);

// guardq o vetor de cada execução das 20 propostas para cada caso
void preencher_matriz(int *V, int **M, int l, int c);

// mostra os vetores utilizados
void print_matriz(int **M, int l, int c);

#endif