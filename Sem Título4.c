#include <stdio.h>
#include <locale.h>

#define TAMANHO_ARRAY 5

struct Aluno {
    char nome[100];
    char dataNascimento[11];
    float notas[2];
    float media;
};

float calcularMedia(struct Aluno aluno) {
    return (aluno.notas[0] + aluno.notas[1]) / 2;
}

void verificarAprovacao(struct Aluno aluno) {
    if (aluno.media >= 7.0) {
        printf("\n Media do Aluno : %2.f ",aluno.media);
		printf("%s está aprovado(a).\n", aluno.nome);
    } else {
        printf("\n Media do Aluno : %2.f ",aluno.media);
		printf("%s está reprovado(a).\n", aluno.nome);
    }
}

int main() {
    setlocale(LC_ALL,"Portuguese");
	
	struct Aluno alunos[TAMANHO_ARRAY];
    int i;
    
    // Preencher informações dos alunos
    for (i = 0; i < TAMANHO_ARRAY; i++) {
        printf("Digite o nome do aluno %d: ", i+1);
        scanf("%s", alunos[i].nome);
        
        printf("Digite a data de nascimento do aluno %d (DD/MM/AAAA): ", i+1);
        scanf("%s", alunos[i].dataNascimento);
        
        printf("Digite a primeira nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i].notas[0]);
        
        printf("Digite a segunda nota do aluno %d: ", i+1);
        scanf("%f", &alunos[i].notas[1]);
        
        // Calcular média
        alunos[i].media = calcularMedia(alunos[i]);
        
        // Verificar aprovação
        verificarAprovacao(alunos[i]);
    }
    
    return 0;
}
