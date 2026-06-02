/**
 * Trabalho 1 de Linguagem de Programacao 1 (LPR1), desenvolvido
 * com o objetivo de ser um programa que apresenta operacoes
 * relacionadas a manipulacao numerica, utilizando conceitos
 * desenvolvidos ate o momento 
 * 
 * Desenvolvido por: Otavio de Moraes e Arthur Mauro Araujo Silva
 * 
 * 
 * 
 * 
 */
#include <stdio.h>
#include "operacoes.h"

int main(){
    int opcao;

    do{
        printf("\n|----------------|Menu de Utilidades|----------------|\n");
        printf("| 1 - Calculadora basica                             |\n");
        printf("| 2 - Media e situacao                               |\n");
        printf("| 3 - Par, impar e sinal                             |\n");
        printf("| 4 - Tabuada                                        |\n");
        printf("| 5 - Soma ate 0                                     |\n");
        printf("| 6 - Maior e menor                                  |\n");
        printf("| 7 - Fatorial                                       |\n");
        printf("| 8 - Fibonacci                                      |\n");
        printf("| 0 - Sair                                           |\n");
        printf("|----------------------------------------------------|\n");
        printf("\nDigite sua opcao: ");

        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                calculadora();
            break;

            case 2:
                mediaSituacao();
            break;

            case 3:
                parImpar();
            break;

            case 4:
                tabuada();
            break;

            case 5:
                somaZero();
            break;

            case 6:
                maiorMenor();
            break;

            case 7:
                fatorial();
            break;

            case 8:
                fibonacci();
            break;

            case 0:
                printf("\n\n|----------------------------------------------------|\n");
                printf("|                     Ate mais!!!                    |\n");
                printf("|----------------------------------------------------|\n\n");
            break;

            default:
                printf("Opcao invalida! Selecione uma das opcoes apresentadas\n");
            break;
        }

    }while (opcao != 0);

    return 0;
}