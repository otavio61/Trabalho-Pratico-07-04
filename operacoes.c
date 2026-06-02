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
                return;
            }

            resultado = n1 / n2;
        break;

        case '^':
            resultado = pow(n1, n2);
        break;
    }

    printf("\n%.2f %c %.2f = %.2f\n", n1, operacao, n2, resultado);
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
}

/** IDEIA SERA IMPLEMENTADA DEPOIS
 *   srand(time(NULL));

  int x = rand() % 3 + 1;  // 0..9
  printf("%d\n", x);
 */
// void listaCompra(){
//     float precos[100];
//     char produtos[10][30];
// }