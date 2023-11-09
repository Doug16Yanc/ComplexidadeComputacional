#include "algoritmos.h"

/*Uma noite, um anjo sussurrou em meu ouvido para deixar o escopo da função principal (main) com a 
menor quantidade de código possível, pois ela não suporta mais carregar o código quase todo com
tanta prática de modularização de código por aí.*/
int main(void) {

    int extent, keySearch = -1, *array;     /*Tanto aqui como em todo o código, o vetor que irá ser preenchido com as entradas do usuário será um ponteiro.*/
    printf("Bem-vindo ao nosso programa para determinação de complexidade computacional de buscas.\n");
    
    geraInteracao(&array, &extent, keySearch);
   
    return 0;
}

/*Função para preenchimento do vetor a ser tratado. O preenchimento ocorre por meio da interação com o usuário*/
void geraInteracao(int **array, int *extent, int keySearch) {

    int opcao;
    
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("       Comparativos entre as complexidades computacionais dos algoritmos em linguagem C\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    do{

        printf("                    --------Selecione uma opção----------           \n");
        printf("                    (1) - ALGORITMOS DE BUSCAS                      \n");
        printf("                    (2) - ALGORITMOS DE CLASSIFICAÇÃO               \n");
        printf("                    (3) - ENCERRAR OPERAÇÃO                         \n");
        scanf("%d", &opcao);
        printf("****************************************\n");

        switch(opcao){
            case 1:
                geraBusca(array, extent, keySearch, "numerosLidosBusca.txt");
                break;
            case 2:
                geraOrdenacao(array, extent, keySearch, "numerosLidosOrdenacao.txt");
                break;
            case 3: 
                printf("Obrigado por ter vindo aqui, sua interação comigo é mais que extraordinária, volte sempre!\n");
                exit(1);
            default:    
                printf("Não é possível escolher esta opção!\n");
                break;
        }

    }
    while (opcao != 3);

}
void geraBusca(int **array, int *extent, int keySearch, const char *fileName){

    printf("Digite o tamanho do vetor que gostarias de implementar:");
    scanf("%d", extent);

    *array = (int *)malloc((*extent) * sizeof(int));          /*Alocação dinâmica de memória e sua execução condicional*/

    if (*array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
 
    /*Preenchimento do vetor*/
    for (int i = 0; i < *extent; i++) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &(*array)[i]);
        printf("%d\n", (*array)[i]); 

    }

    recebeKeySearch(*array, *extent, keySearch);    /*Chamada da função para receber a chave de busca*/
    salvaDados(*array, *extent, fileName);

}

void geraOrdenacao(int **array, int *extent, int keySearch, const char *fileName){
    
    printf("Digite o tamanho do vetor que gostarias de implementar:");
    scanf("%d", extent);

    *array = (int *)malloc((*extent) * sizeof(int));          /*Alocação dinâmica de memória e sua execução condicional*/

    if (*array == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    
    /*Preenchimento do vetor*/
    for (int i = 0; i < *extent; i++) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &(*array)[i]);
        printf("%d\n", (*array)[i]); 

    }

    salvaDados(*array, *extent, fileName);


}

void mostraResultadosBusca(){

    int keySearch = -1; 
    int *array;     /*Tanto aqui como em todo o código, o vetor que irá ser preenchido com as entradas do usuário será um ponteiro.*/
    int extent, contadorPosicoes = 0, *posicoes = NULL;
    
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
    printf("Tempo de Busca Linear com Sentinela para n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoBinaria = buscaBinaria(array, extent, keySearch);
    fim = clock();
    printf("Tempo de Busca Binária para n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));
    
    free(array);        /*Liberação de memóra alocada dinamicamente para o vetor*/

    geraBusca(&array, &extent, keySearch, "numerosLidosBusca.txt");

    system("PAUSE");
}

void mostraResultadosOrdenacao(){
    
    int keySearch = -1; 
    int *array;     /*Tanto aqui como em todo o código, o vetor que irá ser preenchido com as entradas do usuário será um ponteiro.*/
    int extent, contadorPosicoes = 0, *posicoes = NULL;
    
    array = (int *)malloc(extent * sizeof(int));   
    clock_t inicio, fim; /*Variáveis para mensuração de tempo inicial e tempo final*/

    /* Mensuração de todos os tempos de cada algoritmo de ordenação */

    FILE *fp;
    
    /*Realização de medida para cada tipo de algoritmo subsequente*/
    inicio = clock();
    insertionSort(array, extent);
    fim = clock();
    printf("Tempo de classificação para Insertion Sort com n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    selectionSort(array, extent);
    fim = clock();
    printf("Tempo de classificação para Selection Sort com n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    bubbleSort(array, extent);
    fim = clock();
    printf("Tempo de classificação para Bubble Sort com n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    quickSort(array, 0, extent - 1);
    fim = clock();
    printf("Tempo de classificação para Quick Sort com n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    mergeSort(array, 0, extent - 1);
    fim = clock();
    printf("Tempo de classificação para Merge Sort com n=%d: %d ticks de clock - Tempo tomado: %f\n", extent, (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));
            
    free(array);  /*Liberação de memória do vetor que estava alocado dinamicamente no escopo da função geraInteracao*/
    
    geraOrdenacao(&array, &extent, keySearch, "numerosLidosOrdenacao.txt");

    system("PAUSE");
}
void salvaDados(const int *data, int size, const char *fileName) {
    FILE *fp = fopen(fileName, "w");

    if (fp == NULL) {
        printf("Erro na abertura de arquivo.\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d\n", data[i]);
    }

    fclose(fp);
}
