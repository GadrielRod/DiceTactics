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
                system("cls");
                mostrarRegras();
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
void mostrarRegras() {
    printf("\033[1;34m"); // Cor azul para as regras
    printf("\n\t\t\t\t\t\tRegras do Jogo - Dice Tactics\v\n");
    printf("1. O jogo é composto por 2 jogadores: Jogador 1 e Jogador 2.\n");
    printf("2. O jogo prossegue até que um dos jogadores alcance um mínimo de 7 pontos.\n");
    printf("3. Cada turno consiste em lançar dois dados D6 e somar os valores obtidos.\n");
    printf("4. Existem nove 'casas' numeradas de 1 a 9.\n");
    printf("5. Após o lançamento dos dados, o jogador pode escolher uma ou duas 'casas' para marcar,\n");
    printf("   selecionando qualquer combinação que resulte na soma dos dados.\n");
    printf("6. Se o jogador conseguir marcar as casas que somam o valor dos dados, o turno passa para o oponente,\n");
    printf("   e as casas escolhidas pelo jogador no turno anterior são marcadas como 'fechadas'.\n");
    printf("7. A pontuação é baseada nas seguintes condições:\n");
    printf("   - Se um jogador não conseguir fechar as casas correspondentes à soma dos dados, o oponente ganha 1 ponto.\n");
    printf("   - Se um jogador fechar as últimas, uma ou duas casas abertas no seu turno, ele ganha 2 pontos.\n");
    printf("   - Se a única casa aberta for a casa número 1, apenas um dado D6 é lançado.\n");

    // Aguardar até pressionar Enter
    printf("\nPressione Enter para voltar ao menu principal...");
    while (getchar() != '\n');
    getchar(); // Limpar o buffer do teclado
}
