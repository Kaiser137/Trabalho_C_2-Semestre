#include <stdio.h>

int posicionarBarcos1(char jogador1, int tabuleiro1[10][10]){
    int barcos = 1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro1[i][j] = 0;
        }
    }

    printf("Jogador %s, digite a posicao dos seus barcos\n", jogador1);

    while(barcos < 5){
        int x, y;
        printf("Digite a posicao do barco %d: ", barcos);
        scanf("%d %d", &x, &y);
        if(tabuleiro1[x][y] == 0){
            tabuleiro1[x][y] = 1;
            barcos++;
        }else{
            printf("Posicao ja ocupada\n");
        }
    }

    return tabuleiro1;
}

int posicionarBarcos2(char jogador2, int tabuleiro2[10][10]){
    int barcos = 1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro2[i][j] = 0;
        }
    }

    printf("Jogador %s, digite a posicao dos seus barcos\n", jogador2);

    while(barcos < 5){
        int x, y;
        printf("Digite a posicao do barco %d: ", barcos);
        scanf("%d %d", &x, &y);
        if(tabuleiro2[x][y] == 0){
            tabuleiro2[x][y] = 1;
            barcos++;
        }else{
            printf("Posicao ja ocupada\n");
        }
    }

    return tabuleiro2;
}

int main(){
    char jogador1[1000], jogador2[1000], tabuleiro1[10][10], tabuleiro2[10][10];

    printf("Digite o apelido do jogador 1: ");
    scanf("%s", jogador1);
    printf("Digite o apelido do jogador 2: ");
    scanf("%s", jogador2);

    posicionarBarcos1(jogador1, tabuleiro1);
    posicionarBarcos2(jogador2, tabuleiro2);
}