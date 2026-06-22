/**
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "operacoes.h"

/**
 * Realiza uma operação aritimetica, utilizando dois numeros e um operador, fornecidos pelo usuario.
 */
void calculadora(){
    float n1, n2, resultado;
    char operacao;

    printf("\nDigite os numeros e a operacao seguindo a ordem [numero] [operador] [numero]: ");
    scanf("%f %c %f", &n1, &operacao, &n2);

    switch (operacao){
        case '+':
            resultado = n1 + n2;
        break;

        case '-':
            resultado = n1 - n2;
        break;

        case '*':
            resultado = n1 * n2;
        break;

        case '/':
            if(n2 == 0){
                printf("\nNao eh possivel dividir por 0!\n");
                pausa();
                return;
            }

            resultado = n1 / n2;
        break;

        case '^':
            resultado = pow(n1, n2);
        break;
    }

    printf("\n%.2f %c %.2f = %.2f\n", n1, operacao, n2, resultado);

    pausa();
}

/**
 * Realiza uma operacao de media, utilizando duas notas, fornecidas pelo usuario,
 * e informa de aprovado (media >= 6), recuperacao (media < 6 e media >= 4) e reprovado (media < 4).
 */
void mediaSituacao(){
    float n1, n2, media;

    printf("\nDigite suas duas notas para saber a media, seguindo a ordem [numero] [numero]: ");
    scanf("%f %f", &n1, &n2);

    if((n1 < 0 || n1 > 10) || (n2 < 0 || n2 > 10)){
        printf("\n|-----|Insira notas entre 0 e 10|-----|\n");
        pausa();
        return;
    }

    media = (n1 + n2) / 2;

    printf("Sua media: %.2f\n", media);

    if(media >= 6){
        printf("Situacao: Aprovado!\n");
    }else if(media >= 4){
        printf("Situacao: Recuperacao!\n");
    }else{
        printf("Situacao: Reprovado!\n");
    }

    pausa();
}

/**
 * Verifica se o numero, fornecido pelo usuario eh par ou impar.
 * Tambem verifica se o numero eh positivo, negativo ou zero.
 */
void parImpar(){
    int num;

    printf("\nDigite o numero inteiro para verificar: ");
    scanf("%d", &num);

    printf("O numero eh %s\n", num % 2 == 0 ? "PAR" : "IMPAR");

    if(num > 0){
        printf("O numero eh POSITIVO\n");
    }else if(num < 0){
        printf("O numero eh NEGATIVO\n");
    }else{
        printf("O numero eh ZERO\n");
    }

    pausa();
}

/**
 * Gera uma tabuada de 0 ate 10 com o numero fornecido pelo usuario.
 */
void tabuada(){
    int numTabuada;

    printf("\nDigite o numero para ver sua tabuada: ");
    scanf("%d", &numTabuada);

    printf("\n|----|Tabuada do %d|----|\n", numTabuada);

    for(int i = 0; i <= 10; i++){
        printf("%8d * %d = %d\n", numTabuada, i, numTabuada * i);
    }

    pausa();
}

/**
 * Soma valores fornecidos pelo usuario e eh encerrado quando inserido 0.
 * Mostra a soma total e a quantidade de numeros inseridos.
 */
void somaZero(){
    int cont = 0;
    float num, soma = 0;

    printf("\nDigite um numero para somar ou 0 para sair: ");
    scanf("%f", &num);
    
    while(num != 0){
        soma += num;    
        cont++;
        
        printf("Digite um numero para somar ou 0 para sair: ");
        scanf("%f", &num);
    }

    printf("\nSoma total dos numeros: %.2f\n", soma);
    printf("quantidade de numeros inseridos: %d\n", cont);

    pausa();
}

void maiorMenor(){
    int numero, maior = -__INT_MAX__, menor = __INT_MAX__;

    printf("Digite um numero inteiro ou 0 para sair: ");
    scanf("%d", &numero);

    while(numero != 0){
        if(numero > maior) maior = numero;
        if(numero < menor) menor = numero;

        printf("Digite um numero inteiro ou 0 para sair: ");
        scanf("%d", &numero);
    }
    

    printf("\nMaior numero: %d", maior);
    printf("\nMenor numero: %d\n", menor);

    pausa();
}

/**
 * Realiza a operação de fatorial de acordo com o numero escolhido
 */
void fatorial(){
    int num, acumulador, i = 1;

    do{
        printf("\nDigite o numero escolhido: ");
        scanf("%d", &num);

        if(num < 0) printf("\nDigite um valor inteiro positivo\n");
    }while(num < 0);
    
    if(num == 0){
        printf("\n0! = 1\n");
        return;
    }

    acumulador = num;

    for (int i = num - 1; i > 1; i--){
        acumulador *= i;
    }

    printf("\n%d! = %d\n", num, acumulador);

    pausa();
}

void fibonacci(){
    int n1 = 0, n2 = 1, n3, op;

    do{
        printf("\nEscolha qual posicao: ");
        scanf("%d", &op);

        if(op < 1) printf("\nDigite uma posicao a partir do 1\n");
    } while (op < 1);
    
    if(op == 1){
        n3 = 0;
    }else if(op == 2){
        n3 = 1;
    }else{
        for (int i = 0; i < op - 2; i++){
            n3 = n1 + n2;

            n1 = n2;
            n2 = n3;
        }
    }

    printf("\nNumero da posicao %d: %d\n", op, n3);

    pausa();
}

void listaCompra(){
    int produtoEscolhido, qtdComprada;
    float desconto = 0, totalDaCompra = 0, precos[100] = {
        25.90, //Arroz 
        7.80, //Feijao
        6.40, //Batata
        8.60, //Refirgerante
        2.00, //Bolacha
        4.80, //Leite
        27.40, //Sabao
        2.60, //Detergente
        2.00, //Esponja
        19.30 //Amaciente
    };
    char produtos[10][30] = {
        "Saco de arroz (5kg)",
        "Saco de feijao (1kg)",
        "Batata (1kg)",
        "Refrigerante (2L)",
        "Bolacha (200g)",
        "Leite (1L)",
        "Sabao em po (2,2kg)",
        "Detergente (500ml)",
        "Esponja de cozinha",
        "Amaciante (1L)"
    };

    printf("Bem-Vindo ao Mercado Virtual, escolha quais produtos voce deseja comprar, digitando o numero que vem antes dele\n\n");
    
    do {
        
        for(int i = 0; i < 10; i++){
            printf("%d - %s R$ %.2f\n", i+1, produtos[i], precos[i]);
        }
        printf("0 - Sair\n: ");
        scanf("%d", &produtoEscolhido);

        switch (produtoEscolhido){
            case 1:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[0] * qtdComprada;
                break;
            case 2:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[1] * qtdComprada;
                break;
            case 3:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[2] * qtdComprada;
                break;
            case 4:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[3] * qtdComprada;
                break;
            case 5:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[4] * qtdComprada;
                break;
            case 6:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[5] * qtdComprada;
                break;
            case 7:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[6] * qtdComprada;
                break;
            case 8:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[7] * qtdComprada;
                break;
            case 9:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[8] * qtdComprada;
                break;
            case 10:
                printf("Quantos desse produto voce deseja comprar?\n: ");
                scanf("%d", &qtdComprada);
                totalDaCompra += precos[9] * qtdComprada;
                break;
        }
    } while(produtoEscolhido != 0);

    if(totalDaCompra >= 250 && totalDaCompra <= 500){
        desconto = 0.9;
        totalDaCompra = totalDaCompra * desconto;
        printf("O valor total da sua compra, aplicando um desconto de 10%% foi: R$ %.2f", totalDaCompra);
    } else if(totalDaCompra > 500  && totalDaCompra <= 1000){
        desconto = 0.85;
        totalDaCompra = totalDaCompra * desconto;
        printf("O valor total da sua compra, aplicando um desconto de 15%% foi: R$ %.2f", totalDaCompra);
    } else if(totalDaCompra > 1000){
        desconto = 0.75;
        totalDaCompra = totalDaCompra * desconto;
        printf("O valor total da sua compra, aplicando um desconto de 25%% foi: R$ %.2f", totalDaCompra);
    } else{
        printf("O valor total da sua compra foi: R$ %.2f", totalDaCompra);
    }

    pausa();
}

/**
 * Feito para pausar a execução do código após o uso de alguma funcionalidade
 */
void pausa(){
    getchar();
    printf("\n\nDigite ENTER para continuar...");
    getchar();
}
