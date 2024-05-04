#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

// Função para exibir o menu principal
void exibirMenu() {
    printf("\033[1;36m"); // Cor ciano para o título
    printf("\n\t\t=== Dice Tactics ===\n\n");
    printf("\033[0m"); // Resetar a cor

    printf("\033[1;33m"); // Cor amarela para as opções
    printf("\t1. Iniciar Jogo\n");
    printf("\t2. Escores\n");
    printf("\t3. Regras\n");
    printf("\t4. Sair\n");
    printf("\033[0m"); // Resetar a cor

    printf("\033[1;33m"); // Cor amarela para a instrução
    printf("\tEscolha uma opção: ");
    printf("\033[0m"); // Resetar a cor
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL)); // Inicializa a semente de números aleatórios
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
                // Aqui você pode chamar uma função para mostrar os escores
                break;
            case 3:
                //mostrar regras
                printf("\nMostrando as regras");
                break;
            case 4:
                printf("\nSaindo do jogo...\n");
                return 0;
            default:
                printf("\nOpção inválida! Escolha novamente.\n");
        }
    }
}

// Função para mostrar as regras do jogo

