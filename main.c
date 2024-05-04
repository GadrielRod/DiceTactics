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
                system("cls");
                mostrarRegras();
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
void mostrarRegras() {
    printf("\033[1;34m"); // Cor azul para as regras
    printf("\n\t\t\t\t\t\tRegras do Jogo - Dice Tactics\v\n");
    printf("1. O jogo � composto por 2 jogadores: Jogador 1 e Jogador 2.\n");
    printf("2. O jogo prossegue at� que um dos jogadores alcance um m�nimo de 7 pontos.\n");
    printf("3. Cada turno consiste em lan�ar dois dados D6 e somar os valores obtidos.\n");
    printf("4. Existem nove 'casas' numeradas de 1 a 9.\n");
    printf("5. Ap�s o lan�amento dos dados, o jogador pode escolher uma ou duas 'casas' para marcar,\n");
    printf("   selecionando qualquer combina��o que resulte na soma dos dados.\n");
    printf("6. Se o jogador conseguir marcar as casas que somam o valor dos dados, o turno passa para o oponente,\n");
    printf("   e as casas escolhidas pelo jogador no turno anterior s�o marcadas como 'fechadas'.\n");
    printf("7. A pontua��o � baseada nas seguintes condi��es:\n");
    printf("   - Se um jogador n�o conseguir fechar as casas correspondentes � soma dos dados, o oponente ganha 1 ponto.\n");
    printf("   - Se um jogador fechar as �ltimas, uma ou duas casas abertas no seu turno, ele ganha 2 pontos.\n");
    printf("   - Se a �nica casa aberta for a casa n�mero 1, apenas um dado D6 � lan�ado.\n");

    // Aguardar at� pressionar Enter
    printf("\nPressione Enter para voltar ao menu principal...");
    while (getchar() != '\n');
    getchar(); // Limpar o buffer do teclado
}
