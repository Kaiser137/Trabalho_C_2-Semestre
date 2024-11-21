#include <stdio.h>

#define TAMANHO 10
#define NUM_BARCOS 4
#define JOGADAS 4
//aqiu é onde eu estabeleço o tamanho do tabuleiro, o numero de barcos e o numero de jogadas
void posicionarBarcos(char jogador[], int tabuleiro[TAMANHO][TAMANHO]) {
    int barcos = 0;
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    printf("Jogador %s, digite a posicao dos seus barcos\n", jogador);
    while(barcos < NUM_BARCOS) {
        int x, y, pontuacao;
        printf("Digite a posicao (x y) e pontuacao do barco %d (1-4): ", barcos + 1);
        scanf("%d %d %d", &x, &y, &pontuacao);
        if(x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO && tabuleiro[x][y] == 0 && pontuacao >= 1 && pontuacao <= 4) {
            tabuleiro[x][y] = pontuacao;
            barcos++;
        } else {
            printf("Posicao invalida ou ja ocupada, ou pontuacao invalida\n");
        }
    }
}
//loop para a impressão do tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for(int i = 0; i < TAMANHO; i++) {
        for(int j = 0; j < TAMANHO; j++) {
            if(tabuleiro[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}
//função para fazer a jogada por turnos
int fazerJogada(char jogador[], int tabuleiro[TAMANHO][TAMANHO]) {
    int x, y;
    printf("Jogador %s, digite a posicao para atacar (x y): ", jogador);
    scanf("%d %d", &x, &y);
    if(x >= 0 && x < TAMANHO && y >= 0 && y < TAMANHO) {
        int pontuacao = tabuleiro[x][y];
        tabuleiro[x][y] = 0;
        return pontuacao;
    }
    printf("Coordenadas invalidas. Tente novamente.\n");
    return -1;
}

int main() {
    char jogador1[1000], jogador2[1000];
    int tabuleiro1[TAMANHO][TAMANHO], tabuleiro2[TAMANHO][TAMANHO];
    int pontuacao1 = 0, pontuacao2 = 0;

    printf("Digite o apelido do jogador 1: ");
    scanf("%s", jogador1);
    printf("Digite o apelido do jogador 2: ");
    scanf("%s", jogador2);

    posicionarBarcos(jogador1, tabuleiro1);
    posicionarBarcos(jogador2, tabuleiro2);
//tabuleiro com as posições e conclusões das jogadas
    for(int i = 0; i < JOGADAS; i++) {
        int pontuacao;
        do {
            printf("\nTabuleiro do Jogador 2:\n");
            imprimirTabuleiro(tabuleiro2);
            pontuacao = fazerJogada(jogador1, tabuleiro2);
            if(pontuacao > 0) {
                pontuacao1 += pontuacao;
                printf("Acertou! Pontuacao do Jogador 1: %d\n", pontuacao1);
            } else if(pontuacao == 0) {
                printf("Espaco vazio. Sem pontuacao.\n");
            }
        } while(pontuacao == -1);

        do {
            printf("\nTabuleiro do Jogador 1:\n");
            imprimirTabuleiro(tabuleiro1);
            pontuacao = fazerJogada(jogador2, tabuleiro1);
            if(pontuacao > 0) {
                pontuacao2 += pontuacao;
                printf("Acertou! Pontuacao do Jogador 2: %d\n", pontuacao2);
            } else if(pontuacao == 0) {
                printf("Espaco vazio. Sem pontuacao.\n");
            }
        } while(pontuacao == -1);
    }
}
