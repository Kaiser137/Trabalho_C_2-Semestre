#include <stdio.h>

int main(){
    int alunos;

    printf("Digite a quantidade de alunos desejado: ");
    scanf("%d", &alunos);

    int matriz[4][alunos];
    for(int i = 0; i < 1; i++){
        for(int j = 0; j < alunos){
            printf("Digite o ID do aluno: ");
            scanf("%d", &matriz[i][j]);
        }
    }
}
