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
#include <math.h>

void calculadora();
void mediaSituacao();
void parImpar();
void tabuada();
void somaZero();
void potencia();
void fatorial();
void fibonacci();

int main(){
    int opcao;

    do{
        printf("\n|----------------|Menu de Utilidades|----------------|\n");
        printf("| 1 - Calculadora basica                             |\n");
        printf("| 2 - Media e situacao                               |\n");
        printf("| 3 - Par, impar e sinal                             |\n");
        printf("| 4 - Tabuada                                        |\n");
        printf("| 5 - Soma ate 0                                     |\n");
        printf("| 6 - Potencia                                       |\n");
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
                potencia();
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

/**
 * Realiza uma operação de potência, utilizando a biblioteca Math nativa
 */
void potencia(){
    float base, expoente;
    
    printf("\nDigite o numero da base: ");
    scanf("%f", &base);

    printf("Digite o numero do expoente: ");
    scanf("%f", &expoente);

    printf("\n%.2f^%.2f = %.2f\n", base, expoente, pow(base, expoente));
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
    
}