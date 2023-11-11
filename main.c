
#include "algoritmos.h"

/*Uma noite, um anjo sussurrou em meu ouvido para deixar o escopo da função principal (main) com a 
menor quantidade de código possível, mas sou péssimo em seguir o conselho.*/
int main(void) {

    int opcao, extent, keySearch = -1, *array;    /*Tanto aqui como em todo o código, o vetor que irá ser preenchido com as entradas do usuário será um ponteiro.*/
    printf("Bem-vindo ao nosso programa para determinação de complexidade computacional de buscas.\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("       Comparativos entre as complexidades computacionais dos algoritmos em linguagem C\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("                    --------Selecione uma opção----------           \n");
    printf("                    (1) - ALGORITMOS DE BUSCAS                      \n");
    printf("                    (2) - ALGORITMOS DE CLASSIFICAÇÃO               \n");
    scanf("%d", &opcao);
    printf("****************************************\n");

    switch(opcao){
        case 1:
            printf("Digite o tamanho do vetor:\n");
            scanf("%d", &extent);
            array = geraVetorAleatorio1(extent);
            free(array);
            break;
        case 2:
            printf("Digite o tamanho do vetor:\n");
            scanf("%d", &extent);
            array = geraVetorAleatorio2(extent);
            free(array);
            break;
        default:    
            printf("Não é possível escolher esta opção!\n");
            break;
    }
    return 0;
}

/*Nas demais linhas de código, senti-me um relojoeiro suiço após tantos ponteiros*/