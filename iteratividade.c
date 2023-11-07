#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calculaNaturais(int numero);
int calculaFatorial(int numero);
int *calculaFibonacci(int numero);
void salvaDados(int numero, int resultadoNaturais, int resultadoFatorial, int resultadoFibonacci);

int main(void){
    int numero;
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("Bem-vindo(a) ao nosso programa para determinação de desempenho computacional para algoritmos iterativos.\n");
    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("Digite um número inteiro:\n");
    scanf("%d", &numero);
    
    int *numerosFibonacci = calculaFibonacci(numero);

    printf("Resultado do cálculo de número naturais:\n %d\n", calculaNaturais(numero));
    printf("Resultado do cálculo de fatorial  a partir de um número:\n %d\n", calculaFatorial(numero));
    printf("Resultado do cálculo da sequência de Fibonacci a partir de um número:\n");
    for (int i = 0; i < numero; i++) {
        printf("%d\n", numerosFibonacci[i]);
    }

    clock_t inicio, fim;

    
    inicio = clock();
    int resultadoNaturais = calculaNaturais(numero);
    fim = clock();
    printf("Tempo de cálculo para números naturais com iteratividade : %d ticks de clock - Tempo tomado: %f\n",  (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoFatorial = calculaFatorial(numero);
    fim = clock();
    printf("Tempo de cálculo para fatorial com iteratividade : %d ticks de clock - Tempo tomado: %f\n", (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));

    inicio = clock();
    int resultadoFibonacci = calculaFibonacci(numero);
    fim = clock();
    printf("Tempo de cálculo para sequência de Fibonacci com iteratividade: %d ticks de clock - Tempo tomado: %f\n", (int)(fim - inicio), (double)((fim - inicio) / CLOCKS_PER_SEC));
    
    salvaDados(numero, resultadoNaturais, resultadoFatorial, resultadoFibonacci);
    
    free(resultadoFibonacci);

    return 0;
}


int calculaNaturais(int numero){
    int soma = 0;
    for(int i = 1; i <= numero; i++){
        soma += i;
    }
    return soma;
}

int calculaFatorial(int numero){
    int fatorial = 1;
    for(int i = 1; i <= numero; i++){
        fatorial *= i;
    }
    return fatorial;
}

int *calculaFibonacci(int numero) {
    int *fibonacci = (int *)malloc(numero * sizeof(int));
    if (fibonacci == NULL) {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
    int auxiliar, fib0 = 0, fib1 = 1;
    fibonacci[0] = fib0;
    fibonacci[1] = fib1;
    for (int i = 2; i < numero; i++) {
        auxiliar = fib0 + fib1;
        fibonacci[i] = auxiliar;
        fib0 = fib1;
        fib1 = auxiliar;
    }
    return fibonacci;
}

void salvaDados(int numero, int resultadoNaturais, int resultadoFatorial, int resultadoFibonacci) {
    FILE *fp;
    fp = fopen("iteratividade.txt", "w");

    if (fp == NULL){
        printf("Erro na abertura de arquivo.\n");
        exit(1);
    }

    fprintf(fp, "Número: %d\n", numero);
    fprintf(fp, "Resultado Naturais: %d\n", resultadoNaturais);
    fprintf(fp, "Resultado Fatorial: %d\n", resultadoFatorial);
    fprintf(fp, "Resultado Fibonacci: %d\n", resultadoFibonacci);

    fclose(fp);
}