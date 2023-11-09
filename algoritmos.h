#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <x86intrin.h>


void geraInteracao(int **array, int *extent, int keySearch);
void mostraResultados();
void geraBusca(int **array, int *extent, int keySearch, const char *fileName);
void geraOrdenacao(int **array, int *extent, int keySearch, const char *fileName);
void salvaDados(const int *data, int size, const char *fileName);

/*Protótipos de funções para busca*/
void recebeKeySearch(int *array, int extent, int keySearch);
int buscaLinear(int *array, int extent, int keySearch, int **posicoes, int *contadorPosicoes);
int buscaLinearComSentinela(int *array, int extent, int keySearch);
int buscaBinaria(int *array, int extent, int keySearch);

/*Protótipos de funções para classificação/ordenação*/
void insertionSort(int *array, int extent);
void selectionSort(int *array, int extent);
void bubbleSort(int *array, int extent);
int realizaParticao(int *array, int inicio, int fim);
void quickSort(int *array, int inicio, int fim);
void realizaMescla(int *array, int inicio, int meio, int fim);
void mergeSort(int *array, int inicio, int fim);


#endif