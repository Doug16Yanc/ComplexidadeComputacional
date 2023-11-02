#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <x86intrin.h>


/*Protótipos das funções*/

void geraInteracao(int **array, int *extent, int keySearch);
void recebeKeySearch(int *array, int extent, int keySearch);
int buscaLinear(int *array, int extent, int keySearch, int **posicoes, int *contadorPosicoes);
int buscaLinearComSentinela(int *array, int extent, int keySearch);
int buscaBinaria(int *array, int extent, int keySearch);

/*No escopo da função principal estão a chamada para a função que irá receber as entradas do usuário.*/
/*Nesta também, está a execução dos cálculos de tempo para cada algoritmo de busca*/

int main(void) {
    
    int keySearch = -1; 
    int *array;     /*Tanto aqui como em todo o código, o vetor que irá ser preenchido com as entradas do usuário será um ponteiro.*/
    int extent, contadorPosicoes = 0, *posicoes = NULL;
    printf("Bem-vindo ao nosso programa para determinação de complexidade computacional de buscas.\n");
    
    geraInteracao(&array, &extent, keySearch);

    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("       Comparativos entre as complexidades computacionais dos algoritmos de busca em linguagem C\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
   
        
    array = (int *)malloc(extent * sizeof(int));        /*Alocação dinâmica de memória*/

   
    clock_t inicio, fim;

    /*Mensuração de todos os tempos de cada algoritmo de busca*/

    

    inicio = clock();
    int resultadoLinear = buscaLinear(array, extent, keySearch, &posicoes, &contadorPosicoes);
    fim = clock();
 
    printf("Tempo de Busca Linear para n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoSentinela = buscaLinearComSentinela(array, extent, keySearch);
    fim = clock();
    //printf(" %llu \t", fim - inicio);
    printf("Tempo de Busca Linear com Sentinela para n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoBinaria = buscaBinaria(array, extent, keySearch);
    fim = clock();
    printf("Tempo de Busca Binária para n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));
    
    free(array);


    system("PAUSE");

    return 0;
}

/*Função para preenchimento do vetor a ser tratado. O preenchimento ocorre por meio da interação com o usuário*/
void geraInteracao(int **array, int *extent, int keySearch) {
    printf("****************************************\n");
    printf("Digite o tamanho do vetor que gostarias de implementar:");
    scanf("%d", extent);

    *array = (int *)malloc((*extent) * sizeof(int));

    if (*array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    /*Abertura do arquivo que irá receber os números digitados pelo usuário*/
    FILE *fp;
    fp = fopen("numerosLidosBusca", "w");

    if (fp == NULL){
        printf("Erro na abertura de arquivo.\n");
        exit(1);
    }
    
        
    for (int i = 0; i < *extent; i++) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &(*array)[i]);
        fprintf(fp, "%d\n", (*array)[i]); 

    }
    /*Fechamento do arquivo*/
    fclose(fp);
    printf("\nNúmeros do vetor :\n ");

    recebeKeySearch(*array, *extent, keySearch);

}

void recebeKeySearch(int *array, int extent, int keySearch){

    int i, contadorPosicoes = 0, *posicoes = NULL;

    printf("Tudo ok! Agora o digite o elemento que desejas buscar:\n");
    scanf("%d", &keySearch);

    buscaLinear(array, extent, keySearch, &posicoes, &contadorPosicoes);
    buscaLinearComSentinela(array, extent, keySearch);
    buscaBinaria(array, extent, keySearch);
    
    if (contadorPosicoes > 0){
        printf("Elemento encontrado na(s) posição(ões):");
        for (i = 0; i < contadorPosicoes; i++){
            printf("%d\t", posicoes[i]);
        }
        printf("\n");
    }
    else{
        printf("Elemento não encontrado.\n");
    }
    free(posicoes);
    return;
}

/*Função de busca sequencial linear simples*/
int buscaLinear(int *array, int extent, int keySearch, int **posicoes, int *contadorPosicoes) {
    *contadorPosicoes = 0;
    *posicoes = (int *)malloc (extent * sizeof(int));
    
    if (*posicoes == NULL){
        printf("Erro na alocação de memória.\n");
    }
    for (int i = 0; i < extent; i++) {
        if (array[i] == keySearch) {
            (*posicoes)[(*contadorPosicoes)++] = i;
        }
    }
    return -1;  
    
}

/*Função de busca sequencial linear com valor sentinela*/
int buscaLinearComSentinela(int *array, int extent, int keySearch) {
    int lastElement = array[extent] ;
    array[extent] = keySearch; 
    int i = 0;
    while (array[i] != keySearch) {
        i++;
    }
    if ((i < extent - 1) || (array[extent - 1] == keySearch)) {
        return i;  
    }
    return -1;  
}


int buscaBinaria(int *array, int extent, int keySearch) {
    int left = 0;
    int right = extent - 1;
    while (left <= right) {
        int half = left + (right - left) / 2;
        if (array[half] == keySearch) {
            return half;
        }
        if (array[half] < keySearch) {
            left = half + 1;
        } else {
            right = half - 1;
        }
    }
    return -1;  
}
