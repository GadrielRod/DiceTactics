#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <string.h> // Adicionando para lidar com strings

// Estrutura para armazenar informações de cada jogador
typedef struct {
    char nome[50]; // Nome do jogador
    int pontos;    // Pontuação do jogador
} Jogador;

// Função para exibir o tabuleiro com os números disponíveis
void displayBoard(bool numbers[]) {
    printf("  -------------\n");
    for (int i = 1; i <= 9; i++) {
        if (i == 4 || i == 7) {
            printf(" |-------------|\n");
        }
        if (numbers[i]) {
            printf(" | \033[1;32m%d \033[1;0m", i);
        } else {
            printf(" | \033[1;31mX \033[1;0m");
        }
        if (i == 3 || i == 6 || i == 9) {
            printf("|\n");
        }
    }
    printf("  -------------\n\v");
}

// Função para verificar se o jogo acabou
bool isGameOver(bool numbers[], int targetSum) {
    for (int i = 1; i <= 9; i++) {
        if (numbers[i] && (i == targetSum || i + targetSum == 11)) {
            return false;
        }
        for (int j = i + 1; j <= 9; j++) {
            if (numbers[i] && numbers[j] && i + j == targetSum) {
                return false;
            }
        }
    }
    return true;
}

// Função para um jogador jogar
void jogarJogador(Jogador jogador, bool numbers[]) {
    int roll1 = rand() % 6 + 1;
    int roll2 = rand() % 6 + 1;
    int targetSum = roll1 + roll2;
    printf("%s, Dados rolados: %d + %d = %d\n", jogador.nome, roll1, roll2, targetSum);

    displayBoard(numbers);

    bool validInput = false;
    int input1 = -1, input2 = -1;

    while (!validInput) {
        printf("%s, selecione o primeiro número para fechar: ", jogador.nome);
        if (scanf("%d", &input1) != 1) {
            printf("Entrada inválida. Insira um número inteiro.\n");
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            continue;
        }
        if (input1 == 0) {
            printf("Você não pode pular a seleção do primeiro número.\n");
        } else if (numbers[input1]) {
            if (input1 == targetSum) {
                numbers[input1] = false;
                validInput = true;
                break; // Se a primeira casa fecha a soma, não precisa escolher a segunda casa
            }
            bool otherAvailable = false;
            for (int i = 1; i <= 9; i++) {
                if (numbers[i] && i != input1 && (numbers[targetSum - input1] || numbers[targetSum - i])) {
                    otherAvailable = true;
                    break;
                }
            }
            if (!otherAvailable) {
                printf("Não há outra casa disponível que feche a soma dos dados. %s perde!\n", jogador.nome);
                printf("Game over! O outro jogador ganhou.\n"); // O outro jogador é declarado vencedor
                return;
            }
            printf("%s, escolha o segundo número para fechar: ", jogador.nome);
            if (scanf("%d", &input2) != 1) {
                printf("Entrada inválida. Insira um número inteiro.\n");
                // Limpar o buffer de entrada
                while (getchar() != '\n');
                continue;
            }
            if ((input2 == 0 && numbers[targetSum - input1]) || (input2 != 0 && (numbers[input2] && (input1 + input2 == targetSum)))) {
                numbers[input1] = false;
                if (input2 != 0) numbers[input2] = false;
                validInput = true;
            } else {
                printf("Os números selecionados não correspondem à soma dos dados.\n");
            }
        } else {
            printf("Número inválido. Tente novamente.\n");
        }
    }
}

// Função para um jogador jogar
void jogar(Jogador jogador1, Jogador jogador2) {
    bool numbers[10]; // Array para armazenar os números disponíveis
    srand(time(NULL)); // Seed para geração de números aleatórios

    // Inicializando o array de números disponíveis
    for (int i = 1; i <= 9; i++) {
        numbers[i] = true;
    }

    // Loop principal do jogo
    while (true) {
        // Jogador 1
        jogarJogador(jogador1, numbers);

        // Verifica se o jogo terminou
        if (isGameOver(numbers, 7)) {
            displayBoard(numbers);
            printf("Game over! %s ganhou.\n", jogador1.nome);
            return;
        }

        // Jogador 2
        jogarJogador(jogador2, numbers);

        // Verifica se o jogo terminou
        if (isGameOver(numbers, 7)) {
            displayBoard(numbers);
            printf("Game over! %s ganhou.\n", jogador2.nome);
            return;
        }
    }
}

// Função para mostrar as regras do jogo
void mostrarRegras() {
    printf("\033[1;34m"); // Cor azul para as regras
    printf("\n\t\t\t\t\t\tRegras do Jogo - Dice Tactics\v\n");
    printf("1. O jogo é composto por 2 jogadores.\n");
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

    while (true) {
        // Exibir o menu e solicitar a escolha do jogador
        exibirMenu();
        scanf("%d", &escolha);

        // Tratar a escolha do jogador
        switch (escolha) {
            case 1:
                // Iniciar o jogo
                {
                    Jogador jogador1, jogador2;
                    printf("Digite o nome do Jogador 1: ");
                    scanf("%s", jogador1.nome);
                    printf("Digite o nome do Jogador 2: ");
                    scanf("%s", jogador2.nome);
                    jogador1.pontos = jogador2.pontos = 0;
                    jogar(jogador1, jogador2);
                }
                break;
            case 2:
                printf("\nMostrando escores...\n");
                // Aqui você pode chamar uma função para mostrar os escores
                break;
            case 3:
                // Mostrar regras
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
