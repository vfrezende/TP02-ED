#include "utilidades.h"

int mediana(int esq, int meio, int dir){
	if (esq >= meio && esq <= dir){
		return esq;
	}
	if (esq >= dir && esq <= meio){
		return esq;
	}
	if (meio >= esq && meio <= dir){
		return meio;
	}
	if (meio >= dir && meio <= esq){
		return meio;
	}
	if (dir >= esq && dir <= meio){
		return dir;
	}
	if (dir >= meio && dir <= esq){
		return dir;
	}

	return meio;
}

void insertionSort(double vec[], int tamanho){
  int i, j, tmp;
  for (i = 1; i < tamanho; i++) {
        j = i;
        while(j > 0 && vec[j - 1] > vec[j]){
            tmp = vec[j];
            vec[j] = vec[j - 1];
            vec[j - 1] = tmp;
            j--;
        }
  }
}

void vec_aleatorio(int *V, int k){
	for (int i = 0; i < k; i++)
    	V[i] = rand() % k + 1;
}

void vec_ord_crescente(int *V, int k){
    for (int i = 0; i < k; i++)
        V[i] = i+1;
}

void vec_ord_decrescente(int *V, int k){
    for (int i = 0; i < k; i++)
        V[i] = k - i;
}

int** alocarMatriz(int Linhas,int Colunas){ 
 
  int i,j; 
  int **m = (int**)malloc(Linhas * sizeof(int*));
 
  for (i = 0; i < Linhas; i++){ 
       m[i] = (int*) malloc(Colunas * sizeof(int));
       for (j = 0; j < Colunas; j++){
            m[i][j] = 0; 
       }
  }
return m;
}

void preencher_matriz(int *V, int **M, int l, int c){
		for (int j = 0; j < c; ++j){
			M[l][j] = V[j];		
		}
}

void print_matriz(int **M, int l, int c){
	for (int i = 0; i < l; ++i){
		for (int j = 0; j < c; ++j){
			printf("%d ",M[i][j]);		
		}
		printf("\n");
	}
}

void troca(int *V, int i, int j){
	int aux = V[i];
	V[i] = V[j];
	V[j] = aux;
	mov++;
}
