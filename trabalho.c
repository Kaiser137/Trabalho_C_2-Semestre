#include <stdio.h>
//Faço a definição de até 30 cadastros aqui.
#define MAX_CADASTRO 30

//Para cada cadastro individual e as respectivas notas
void CadastroAluno (int alunos, float matriz[MAX_CADASTRO][3], int ID[MAX_CADASTRO]){
    for(int i = 0; i < alunos; i++){
        printf("Digite o ID do aluno: ");
        scanf("%d", &ID[i]);
        for(int j = 0; j < 3; j++){
            printf("Digite a nota %d do aluno: ", j+1);
            scanf("%f", &matriz[i][j]);
        }   
    }
}
//Para cada aluno, calculo a média das notas
void CalcMediaIndividual (int alunos, float matriz[MAX_CADASTRO][3], float media[MAX_CADASTRO]){
   for(int i = 0; i < alunos; i++){
    media[i] = (matriz[i][0] + matriz[i][1] + matriz[i][2]) / 3;
        printf("O aluno %d tem a media de: %.2lf\n", i + 1, media[i]);
   }
}
//Calculo a média geral da turma
void CalcMediaGeral (int alunos, float matriz[MAX_CADASTRO]){
    float soma = 0; 
    for (int i = 0; i < alunos; i++){ 
        soma = soma + matriz[i]; } 
    float mediaGeral = soma / alunos; 
    printf("Média Geral da Turma: %.2f\n", mediaGeral); 
}
//Calculo a maior e a menor nota da turma
void NotasMaiorMenor (int alunos, float matriz[MAX_CADASTRO][3], float *maiorNota, float *menorNota){
    *maiorNota = matriz[0][0];
    *menorNota = matriz[0][0];
    for(int i = 0; i < alunos; i++){
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] > *maiorNota){
                *maiorNota = matriz[i][j];
            }
            if(matriz[i][j] < *menorNota){
                *menorNota = matriz[i][j];
            }  
        }
    }
}

int main(){
        int alunos; 
        int teste_quantidade;
        int condicao = 0;
        
        // Condicao para digitar o numero correto de alunos > 0 ou <= 30
        while(condicao < 1){
        printf("Digite o numero de alunos(maximo ate 30): ");
        scanf("%d", &teste_quantidade);
          if(teste_quantidade > 30 || teste_quantidade <= 0){
            printf("Numero de alunos invalido! Tente novamente.\n");
          } else{
            alunos = teste_quantidade;
            condicao++;
          }
        }
        
        float notas[MAX_CADASTRO][3]; 
        int ids[MAX_CADASTRO]; 
        float medias[MAX_CADASTRO]; 
        float maiorNota, menorNota; 
        
        CadastroAluno(alunos, notas, ids); 
        CalcMediaIndividual(alunos, notas, medias); 
        NotasMaiorMenor(alunos, notas, &maiorNota, &menorNota); 
        CalcMediaGeral(alunos, medias); 
        
        printf("Maior Nota: %.2f\n", maiorNota); 
        printf("Menor Nota: %.2f\n", menorNota);
}
