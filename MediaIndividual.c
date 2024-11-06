#include <stdio.h>


void CalcMediaIndividual (float matriz[4][30], int alunos){
    float media;
    int ID;
    float soma = 0;
    printf("Digite o ID para a media individual: ");
    scanf("%d", &ID);
    if (ID >= 0) { 
        for(int i = 1; i < 4; i++){ 
            soma = soma + matriz[i][ID]; 
            printf("%.2lf\n", soma);
        } 
          media = soma / 3.0; 
    printf("O aluno do ID %d tem a media de %.2f\n", ID, media); 
    } else { 
  printf("ID invalido!\n"); 
    } 
}





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

    float matriz[4][30];
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
    CalcMediaIndividual(matriz,alunos);
}
