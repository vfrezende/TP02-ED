#include "Quick_Sort.h"

int main(int argc, char *argv[]){

    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;

//tamanho do vetor
    int k = atoi(argv[3]);

    int *V = (int*) malloc(k*sizeof(int)); //vetor de tamanho k a ser ordenado

// entrada de acordo com tipo de vetor(Crecente, Decrescente, Aleatorio)
    char *tipo = argv[2];

//entrada que escolhe varaicao do quicksort
    const char *variacao = argv[1];

//flag da entrada que sinaliza se vetores utilizados serão impressos ou não
    const char *flag = argv[4];
// entrada de acordo com variacao do quicksort
    
    double vec_tempo[20];

// alocando uma matriz para retornar os vetores utilizados
    int **vec_saidas = alocarMatriz(20, k);

    for (int i = 0; i < 20; ++i){
        if(!strcmp(tipo, ALEATORIO)){
            vec_aleatorio(V, k);
        }
        else if(!strcmp(tipo, CRESCENTE)){
            vec_ord_crescente(V, k);
        }
        else if(!strcmp(tipo, DECRESCENTE)){
            vec_ord_decrescente(V, k);
        }
        else{
            printf("Erro: Nao foi possivel identificar tipo do vetor\n"); 
             exit(1);
            }
        preencher_matriz(V, vec_saidas, i, k); //salva o vetor utilizado em cada iteração em uma matriz
        start = clock();
        quicksort(V, k, variacao); //variação do quicksort utilizado
        end = clock();
        cpu_time_used = (((double) (end - start)) / CLOCKS_PER_SEC) * 1.e+3; //calculo do tempo de execução
        vec_tempo[i] = cpu_time_used;
    }
    
    insertionSort(vec_tempo, 20); //ordenando o vetor contendo os tempos de execução para retirar a mediana

    double mediana = (vec_tempo[10] + vec_tempo[9])/2;
    double media_comp = get_comp()/20;
    double media_mov = get_mov()/20;

    printf("%s %s %d %.2lf %.2lf %.2lf\n", argv[1], argv[2], k, media_comp, media_mov, mediana);

    if (!strcmp(flag, FLAG))
        print_matriz(vec_saidas,20,k);

    zera_comp();
    zera_mov();

    free(V);
    free(vec_saidas);	
    return 0;
}