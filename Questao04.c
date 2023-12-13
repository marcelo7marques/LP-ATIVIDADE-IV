#include <stdio.h>
#include <locale.h>

typedef struct {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20];
} ContaBancaria;

void depositar(ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito de R$ %.2f realizado com sucesso!\n", valor);
}

void sacar(ContaBancaria *conta, float valor) {
    if (valor > conta->saldo) {
        printf("Saldo insuficiente!\n");
    } else {
        conta->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso!\n", valor);
    }
}

void imprimirSaldo(ContaBancaria conta) {
    printf("Saldo atual: R$ %.2f \n", conta.saldo);
}

int main() {
	
	setlocale(LC_ALL,"Portuguese");
	
    ContaBancaria conta;
    int opcao;
    float valor;

    printf("Número da conta: \n");
    scanf("%d", &conta.numeroConta);

    printf("Nome do titular: \n");
    scanf(" %[^\n]s", conta.nomeTitular);

    printf("Tipo de conta (poupança ou corrente): \n");
    scanf(" %[^\n]s", conta.tipoConta);

    printf("Saldo inicial: R$ \n");
    scanf("%f", &conta.saldo);

    do {
	

    printf("1 - Depositar \n");
    printf("2 - Sacar \n");
    printf("Escolha uma opção (0 para sair): \n");
    scanf("%d", &opcao);

    
    switch (opcao) {
            case 1:
                printf("Valor a ser depositado: R$ \n");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Valor a ser sacado: R$ \n");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;   
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        imprimirSaldo(conta);
        

    } while (opcao != 0);

    return 0;
}
