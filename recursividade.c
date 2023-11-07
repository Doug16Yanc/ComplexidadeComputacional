#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculaNaturais(int numero);
int calculaFatorial(int numero);
int *calculaFibonacci(int numero);
void salvaDados(int numero, int numeroNatural, int numeroFatorial, int *numerosFibonacci, int resultadoNaturais, int resultadoFatorial, int resultadoFibonacci);

int main(void){
    int numero;
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("Bem-vindo(a) ao nosso programa para determinação de desempenho computacional para algoritmos recursivos.\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("Digite um número inteiro:\n");
    scanf("%d", &numero);
    
    int numeroNatural = calculaNaturais(numero);
    int numeroFatorial = calculaFatorial(numero);
    int *numerosFibonacci = calculaFibonacci(numero);

    printf("Resultado do cálculo de número naturais:\n %d\n", numeroNatural);
    printf("Resultado do cálculo de fatorial  a partir de um número:\n %d\n", numeroFatorial);
    printf("Resultado do cálculo da sequência de Fibonacci a partir de um número:\n");
    for (int i = 0; i < numero; i++) {
        printf("%d\n", numerosFibonacci[i]);
    }

    clock_t inicio, fim;

    
    inicio = clock();
    int resultadoNaturais = calculaNaturais(numero);
    fim = clock();
    printf("Tempo de cálculo para números naturais com recursividade : %d ticks de clock - Tempo tomado: %f\n",  (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoFatorial = calculaFatorial(numero);
    fim = clock();
    printf("Tempo de cálculo para fatorial com recursividade : %d ticks de clock - Tempo tomado: %f\n", (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoFibonacci = calculaFibonacci(numero);
    fim = clock();
    printf("Tempo de cálculo para sequência de Fibonacci com recursividade : %d ticks de clock - Tempo tomado: %f\n", (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));
    
    salvaDados(numero, numeroNatural, numeroFatorial, &numerosFibonacci, resultadoNaturais, resultadoFatorial, resultadoFibonacci);

    return 0;
}


int calculaNaturais(int numero){
    int soma = 0;
    if(numero == 1){
        soma = 1;
    }
    else{
        soma = numero + calculaNaturais(numero - 1);
    }
    return soma;
}

int calculaFatorial(int numero){
    int fatorial = 1;
    if (numero == 0 || numero == 1){
        fatorial = 1;
    }
    else{
        fatorial = numero*calculaFatorial(numero - 1);
    }
    return fatorial;
}

int *calculaFibonacci(int numero) {
    int *fibonacci = (int *)malloc(numero * sizeof(int));
    if (fibonacci == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    
    if (numero <= 0) {
        return NULL;
    }
    
    for (int i = 0; i < numero; i++) {
        if (i <= 1) {
            fibonacci[i] = i;
        } else {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
    }
    
    return fibonacci;
}


void salvaDados(int numero, int numeroNatural, int numeroFatorial, int *numerosFibonacci, int resultadoNaturais, int resultadoFatorial, int resultadoFibonacci) {
    FILE *fp;
    fp = fopen("recursividade.txt", "w");

    if (fp == NULL){
        printf("Erro na abertura de arquivo.\n");
        exit(1);
    }

    fprintf(fp, "Número: %d\n", numero);
    fprintf(fp, "Resultado Naturais: %d\n", numeroNatural);
    fprintf(fp, "Resultado Fatorial: %d\n", numeroFatorial);
    fprintf(fp, "Resultado Fibonacci:\n");
    for (int i = 0; i < numero; i++) {
        printf("%d\n", numerosFibonacci[i]);
    }

    
    clock_t inicio, fim;
    
    inicio = clock();
    fim = clock();
    printf("Tempo de cálculo para números naturais com recursividade : %d ticks de clock - Tempo tomado: %f\n",  (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    fim = clock();
    printf("Tempo de cálculo para fatorial com recursividade : %d ticks de clock - Tempo tomado: %f\n", (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    fim = clock();
    printf("Tempo de cálculo para sequência de Fibonacci com recursividade : %d ticks de clock - Tempo tomado: %f\n", (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));
    
    fclose(fp);
}