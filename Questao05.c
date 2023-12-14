#include <stdio.h>

#define MAX_FUNCIONARIOS 1000

struct Funcionario {
    char nome[200];
    char cargo[50];
    float salario;
};

float calcularMediaSalario(struct Funcionario funcionarios[], int numerofuncionarios, char cargo[]) {
    float somaSalarios = 0;
    int i ;

    for (i = 0; i < numerofuncionarios; i++) {
        if (strcmp(funcionarios[i].cargo, cargo) == 0) {
            somaSalarios += funcionarios[i].salario;
            i++;
        }
    }

    if (i == 0) {
        return 0;
    }

    return somaSalarios / i;
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numerofuncionarios;
    char cargoProcurado[50];
    int i;

    printf("Informe a quantidade de funcionarios: ");
    scanf("%d", &numerofuncionarios);

    for (i = 0; i < numerofuncionarios; i++) {
        printf("\n Informe o nome do funcionario %d: ", i + 1);
        scanf("%s", funcionarios[i].nome);
        printf("\n Informe o cargo do funcionario %d: ", i + 1);
        scanf("%s", funcionarios[i].cargo);
        printf("\n Informe o salario do funcionario %d: ", i + 1);
        scanf("%f", &funcionarios[i].salario);
    }

    printf("\n Informe o cargo que deseja calcular a media salarial: ");
    scanf("%s", cargoProcurado);

    float mediaSalarial = calcularMediaSalario(funcionarios, numerofuncionarios, cargoProcurado);

    printf("\n A media salarial dos programadores é : %.2f", mediaSalarial);

    return 0;
}
