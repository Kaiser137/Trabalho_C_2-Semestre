#include <stdio.h>

int main(){
    int alunos, quantidade_teste, enquanto = 0;

    while(enquanto < 1){
    printf("Digite a quantidade de alunos desejado: ");
    scanf("%d", &quantidade_teste);
    if(quantidade_teste > 30 || quantidade_teste < 0){
        printf("Numero de alunos maior ou insuficiente!");
    }
    else{
        alunos = quantidade_teste;
        enquanto++;
    }
    }

    float matriz[4][alunos];
    int linha = 0;
        for(int j = 0; j < alunos; j++){
            printf("Digite o ID do aluno: ");
            scanf("%f", &matriz[linha][j]);
        }


    for(int i = 0; i < alunos; i++){
        for(int j = 1; j < 4; j++){
            printf("Digite a %d nota do aluno %d: ", j, (int)matriz[0][i]);
            scanf("%f", &matriz[j][i]);
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < alunos; j++){
            printf("A matriz na posicao [%d][%d] eh: %.2lf\n", i, j, matriz[i][j]);
        }
    }
}
