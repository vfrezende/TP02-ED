#include "Quick_Sort.h"

void insercao(int *V, int esq, int dir){

	int i, j;
	int atual;
	for(i = esq+1; i <= dir; i++){
		atual = V[i];
		comp++;
        for(j = i-1; (j >= esq) && atual < V[j]; j--){
			V[j+1] = V[j];
			mov++;
			comp++;
		}
		mov++;
		V[j+1] = atual;
	}
}

void ordena_central(int *V, int esq, int dir){
    int i;
    int j;

    particiona_central(V, esq, dir, &i, &j);

    if (esq < j) 
        ordena_central(V, esq, j);
    if (i < dir) 
        ordena_central(V, i, dir);
}

// bloco de funções com funcionamento idêntico (ordenação dos sub-vetores gerados pelos respectivos particionas)
void ordena_mediana(int *V, int esq, int dir){
    int i;
    int j;

    particiona_mediana(V, esq, dir, &i, &j);

    if (esq < j) 
        ordena_mediana(V, esq, j);
    if (i < dir) 
        ordena_mediana(V, i, dir);
}
void ordena_primeiro(int *V, int esq, int dir){
    int i;
    int j;

    particiona_primeiro(V, esq, dir, &i, &j);

    if (esq < j) 
        ordena_primeiro(V, esq, j);
    if (i < dir) 
        ordena_primeiro(V, i, dir);
}

void ordena_1porcento(int *V, int esq, int dir, int k){
    int i;
    int j;

    if (dir-esq <= k/100){
    	insercao(V, esq, dir);
    }
    else{
    	particiona_mediana(V, esq, dir, &i, &j);
        if (esq < j) 
        	ordena_1porcento(V, esq, j, k);
    	if (i < dir) 
        	ordena_1porcento(V, i, dir, k);
    }
}

void ordena_5porcento(int *V, int esq, int dir, int k){
    int i;
    int j;

    if (dir-esq <= (k/100)*5){
    	insercao(V, esq, dir);
    }
    else{
    	particiona_mediana(V, esq, dir, &i, &j);
        if (esq < j) 
        	ordena_5porcento(V, esq, j, k);
    	if (i < dir) 
        	ordena_5porcento(V, i, dir, k);
    }
}

void ordena_10porcento(int *V, int esq, int dir, int k){
    int i;
    int j;

    if (dir-esq <= (k/100)*10){
    	insercao(V, esq, dir);
    }
    else{
    	particiona_mediana(V, esq, dir, &i, &j);
        if (esq < j) 
        	ordena_10porcento(V, esq, j, k);
    	if (i < dir) 
        	ordena_10porcento(V, i, dir, k);
    }
}

//bloco de variações dos quicksort
void quicksort_central(int *V, int k){
	ordena_central(V, 0, k-1);
}

void quicksort_mediana(int *V, int k){
	ordena_mediana(V, 0, k-1);
}

void quicksort_primeiro(int *V, int k){
	ordena_primeiro(V, 0, k-1);
}
void quicksort_1porcento(int *V, int k){
	ordena_1porcento(V, 0, k-1, k);
}
void quicksort_5porcento(int *V, int k){
	ordena_5porcento(V, 0, k-1, k);
}
void quicksort_10porcento(int *V, int k){
	ordena_10porcento(V, 0, k-1, k);
}

//controla toda execução do quicksort não recursivo
void quicksort_iterativo(int *V, int k){
	TipoPilha pilha;
	TipoItem item;
	int esq, dir, i, j;
	FPVazia(&pilha);
	esq = 0;
	dir = k-1;
	item.Dir = dir;
	item.Esq = esq;
	Empilha(item, &pilha);
	do{
		if (dir > esq){
			particiona_central(V,esq,dir,&i, &j);
			if ((j-esq)>(dir-i)){
				item.Dir = j;
				item.Esq = esq;
				Empilha(item, &pilha);
					esq = i;
			}else{
				item.Esq = i;
				item.Dir = dir;
				Empilha(item, &pilha);
				dir = j;
			}
		}else{
		Desempilha(&pilha,&item);
		dir = item.Dir;
		esq = item.Esq;
		}	
	}while(!Vazia(&pilha));
}


void particiona_central(int *V, int esq, int dir, int *i, int *j){
	*i = esq;
	*j = dir;
	int pivo = V[(*i+*j)/2]; // o pivô neste caso é o elementro centra do vetor

	do{
		while(pivo > V[*i]){
			(*i)++;
			comp++;
		}

		while(pivo < V[*j]){
			(*j)--;
			comp++;
		}

		if (*i <= *j){
			troca(V, *i, *j);
			(*i)++;
			(*j)--;
			comp++;
		}
	} while (*i <= *j);
}


void particiona_mediana(int *V, int inicio, int fim, int *i, int *j){

    *i = inicio;
    *j = fim;

    //procura a mediana entre inicio, meio e fim
    int meio = (fim-inicio)/2;
    int pivo = mediana(V[inicio], V[meio], V[fim]); //índice da mediana

	do{
		while(pivo > V[*i]){
			(*i)++;
			comp++;
		}

		while(pivo < V[*j]){
			(*j)--;
			comp++;
		}

		if (*i <= *j){
			troca(V, *i, *j);
			(*i)++;
			(*j)--;
			comp++;
		}
	} while (*i <= *j);
    
}

void particiona_primeiro(int *V, int esq, int dir, int *i, int *j){

	*i = esq;
	*j = dir;
	int pivo = V[*i]; // o pivô neste caso é o primeiro elemento do sub-vetor gerado

	do{
		while(pivo > V[*i]){
			(*i)++;
			comp++;
		}

		while(pivo < V[*j]){
			(*j)--;
			comp++;
		}

		if (*i <= *j){
			troca(V, *i, *j);
			(*i)++;
			(*j)--;
			comp++;
		}
	} while (*i <= *j);
}

//de acordo com o argumento passado na entrada é escolhida a variação do quick sorte que deve ser executada
void quicksort(int *V, const int k, const char *quick_var) {
    if(!strcmp(quick_var, QUICKSORT_CLASSICO)){
        quicksort_central(V, k);
    }
    else if(!strcmp(quick_var, QUICKSORT_INSERCAO1)){
        quicksort_1porcento(V, k);
    }
    else if(!strcmp(quick_var, QUICKSORT_INSERCAO5)){
        quicksort_5porcento(V, k);
    }
    else if(!strcmp(quick_var, QUICKSORT_INSERCAO10)){
        quicksort_10porcento(V, k);
    }
    else if(!strcmp(quick_var, QUICKSORT_MEDIANA)){
        quicksort_mediana(V, k);
    }
    else if(!strcmp(quick_var, QUICKSORT_PRIMEIRO)){
        quicksort_primeiro(V, k);
    }
    else if(!strcmp(quick_var, QUICKSORT_ITERATIVO)){
        quicksort_iterativo(V, k);
    }
}

//retorna o e zera número de comparações e movimentações respectivamente
long get_mov(){return mov;}

long get_comp(){return comp;}

void zera_mov(){mov = 0;}

void zera_comp(){comp = 0;}


