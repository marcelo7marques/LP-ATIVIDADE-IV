#include<stdio.h>


typedef struct{
    char nome[100];
    float preco;
    int quantidade_estoque;
} Produto;


float calcularValorTotalEstoque(Produto p){
    return p.quantidade_estoque;
}


void atualizarEstoque(Produto *p, int quantidade_compra){
    p->quantidade_estoque - quantidade_compra;
}

int main(){
    Produto produto;
    float estoqueatual;
    
    printf("Digite o nome do produto: \n");
    fgets(produto.nome, 100, stdin);
    
    printf("Digite o preco do produto: \n");
    scanf("%f", &produto.preco);
    
    printf("Digite a quantidade em estoque: \n");
    scanf("%d", &produto.quantidade_estoque);
    
    int opcao;
    do{
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Escolha uma opcao: \n");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Digite a quantidade a ser comprada: \n");
                int quantidade_compra;
                scanf("%d", &quantidade_compra);
                
                if(produto.quantidade_estoque >= quantidade_compra){
                    atualizarEstoque(&produto, quantidade_compra);
                    estoqueatual = calcularValorTotalEstoque(produto) - quantidade_compra;
                    printf("Estoque Atual : %.2f \n",estoqueatual);
					printf("Compra realizada com sucesso!\n");
                }else{
                    printf("Quantidade em estoque insuficiente.\n");
                }
                break;
            case 2:
                printf("Nome do produto: %s\n", produto.nome);
                printf("Preco do produto: %.2f\n", produto.preco);
                printf("Quantidade em estoque: %d\n", produto.quantidade_estoque);
                printf("Valor total em estoque: %.2f\n", calcularValorTotalEstoque(produto));
                break;
            
			case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
        
    }while(opcao != 3);
    
    return 0;
}
