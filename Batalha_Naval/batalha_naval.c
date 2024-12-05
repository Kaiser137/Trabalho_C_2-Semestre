#include <stdio.h>
#include <string.h>

#define TAMANHO 10
#define NUM_BARCOS 4
#define JOGADAS 4

// Função para posicionar os barcos de um jogador no tabuleiro
void posicionarBarcos(char jogador[], int tabuleiro[TAMANHO][TAMANHO]) {
    int barcos = 0;

    // Inicializa o tabuleiro com zeros
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    printf("Jogador %s, digite a posição dos seus barcos\n", jogador);
    printf("Digite assim, por exemplo:\nx = 1, y = 1 e pontuacao = 2, preencha assim x y pontucao (1 1 2)\n");
    while (barcos < NUM_BARCOS) {
        int x, y, pontuacao;
        printf("Digite a posição (x, y) e a pontuação do barco %d: ", barcos + 1);
        scanf("%d %d %d", &x, &y, &pontuacao);

        // Verificação de posição válida e pontuação
        if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && tabuleiro[x][y] == 0 && pontuacao >= 1 && pontuacao <= 4) {
            tabuleiro[x][y] = pontuacao;
            barcos++;
        } else {
            if (x < 0 || x >= TAMANHO || y < 0 || y >= TAMANHO) {
                printf("Coordenadas fora do tabuleiro. Tente novamente.\n");
            } else if (tabuleiro[x][y] != 0) {
                printf("Posição já ocupada. Tente novamente.\n");
            } else {
                printf("Pontuação inválida. Digite um valor entre 1 e 4.\n");
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO], int mascarar) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == 0) {
                printf(". ");
            } else if (tabuleiro[i][j] == -1) {
                printf("X ");
            } else if (mascarar && tabuleiro[i][j] > 0) {
                printf(". ");
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

// Função para verificar acerto e retornar a pontuação
int fazerJogada(char jogador[], int tabuleiro[TAMANHO][TAMANHO]) {
    int x, y;
    printf("Jogador %s, digite a posição para atacar (x y): ", jogador);
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
        int pontuacao = tabuleiro[x][y];
        if (pontuacao > 0) {
            tabuleiro[x][y] = -1;  // Marca o acerto com "X"
            printf("Acertou!\n");
        } else if (pontuacao == 0) {
            tabuleiro[x][y] = -1;  // Marca o espaço vazio que foi atacado com "X"
        }
        return pontuacao;
    }
    printf("Coordenadas inválidas. Tente novamente.\n");
    return -1;  // Retorna -1 caso a coordenada seja inválida
}

// Função para exibir o placar final
void exibirPlacar(int pontuacao1, int pontuacao2) {
    printf("\nPlacar Final:\n");
    printf("Jogador 1: %d pontos\n", pontuacao1);
    printf("Jogador 2: %d pontos\n", pontuacao2);

    if (pontuacao1 > pontuacao2) {
        printf("Jogador 1 venceu!\n");
    } else if (pontuacao2 > pontuacao1) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }
}

int main() {
    char jogador1[100], jogador2[100];
    int tabuleiro1[TAMANHO][TAMANHO], tabuleiro2[TAMANHO][TAMANHO];
    int pontuacao1 = 0, pontuacao2 = 0;

    // Leitura dos nomes dos jogadores
    printf("Digite o apelido do jogador 1: ");
    fgets(jogador1, sizeof(jogador1), stdin);
    jogador1[strcspn(jogador1, "\n")] = '\0';

    printf("Digite o apelido do jogador 2: ");
    fgets(jogador2, sizeof(jogador2), stdin);
    jogador2[strcspn(jogador2, "\n")] = '\0';

    // Posicionamento dos barcos
    posicionarBarcos(jogador1, tabuleiro1);
    posicionarBarcos(jogador2, tabuleiro2);

    // Loop de jogadas
    for (int i = 0; i < JOGADAS; i++) {
        int pontuacao;

        // Jogador 1
        do {
            printf("\nTabuleiro do Jogador 2:\n");
            imprimirTabuleiro(tabuleiro2, 1);  // Mostra o tabuleiro do jogador 2 sem revelar os barcos
            pontuacao = fazerJogada(jogador1, tabuleiro2);
            if (pontuacao > 0) {
                pontuacao1 += pontuacao;
                printf("Pontuação do Jogador 1: %d\n", pontuacao1);
            } else if (pontuacao == 0) {
                printf("Espaço vazio. Sem pontuação.\n");
            }
        } while (pontuacao == -1);

        // Jogador 2
        do {
            printf("\nTabuleiro do Jogador 1:\n");
            imprimirTabuleiro(tabuleiro1, 1);  // Mostra o tabuleiro do jogador 1 sem revelar os barcos
            pontuacao = fazerJogada(jogador2, tabuleiro1);
            if (pontuacao > 0) {
                pontuacao2 += pontuacao;
                printf("Pontuação do Jogador 2: %d\n", pontuacao2);
            } else if (pontuacao == 0) {
                printf("Espaço vazio. Sem pontuação.\n");
            }
        } while (pontuacao == -1);
    }

    // Exibir placar final
    exibirPlacar(pontuacao1, pontuacao2);

    return 0;
}
