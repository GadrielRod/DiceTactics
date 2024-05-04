#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

// Fun��o para exibir o menu principal
void exibirMenu() {
    printf("\033[1;36m"); // Cor ciano para o t�tulo
    printf("\n\t\t=== Dice Tactics ===\n\n");
    printf("\033[0m"); // Resetar a cor

    printf("\033[1;33m"); // Cor amarela para as op��es
    printf("\t1. Iniciar Jogo\n");
    printf("\t2. Escores\n");
    printf("\t3. Regras\n");
    printf("\t4. Sair\n");
    printf("\033[0m"); // Resetar a cor

    printf("\033[1;33m"); // Cor amarela para a instru��o
    printf("\tEscolha uma op��o: ");
    printf("\033[0m"); // Resetar a cor
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // Inicializa a semente de n�meros aleat�rios
    int escolha;


    while(true) {
        // Exibir o menu e solicitar a escolha do jogador
        exibirMenu();
        scanf("%d", &escolha);

        // Tratar a escolha do jogador
        switch (escolha) {
            case 1:

                break;
            case 2:
                printf("\nMostrando escores...\n");
                // Aqui voc� pode chamar uma fun��o para mostrar os escores
                break;
            case 3:
                //mostrar regras
                printf("\nMostrando as regras");
                break;
            case 4:
                printf("\nSaindo do jogo...\n");
                return 0;
            default:
                printf("\nOp��o inv�lida! Escolha novamente.\n");
        }
    }
}

// Fun��o para mostrar as regras do jogo

