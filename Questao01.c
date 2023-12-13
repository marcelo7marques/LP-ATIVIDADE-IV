#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 3

struct dados_contatos {
   char nome[200];
   char telefone[200];
   char email[200];
};

void buscarcontato(struct dados_contatos contatos[], char contato[]) {
   int i;
   for (i = 0; i < TAM; i++) {
      if (strcmp(contatos[i].nome, contato) == 0) {
         printf("Nome: %s \n", contatos[i].nome);
         printf("Telefone: %s \n", contatos[i].telefone);
         printf("Email: %s \n", contatos[i].email);
         return;
      }
   }
   printf("Contato não encontrado.\n");
}

int main() {
   setlocale(LC_ALL, "Portuguese");

   struct dados_contatos contatos[TAM];
   char contato[200];
   int i;

   for (i = 0; i < TAM; i++) {
      printf("\nDigite os dados do %dº contato:\n", i + 1);
      printf("Nome: ");
      fgets(contatos[i].nome, sizeof(contatos[i].nome), stdin);

      printf("Telefone: ");
      fgets(contatos[i].telefone, sizeof(contatos[i].telefone), stdin);

      printf("Email: ");
      fgets(contatos[i].email, sizeof(contatos[i].email), stdin);

      contatos[i].nome[strcspn(contatos[i].nome, "\n")] = 0;
      contatos[i].telefone[strcspn(contatos[i].telefone, "\n")] = 0;
      contatos[i].email[strcspn(contatos[i].email, "\n")] = 0;
   }

   printf("\n Digite o nome do contato que deseja pesquisar: ");
   fgets(contato, sizeof(contato), stdin);
   contato[strcspn(contato, "\n")] = 0;

   buscarcontato(contatos, contato);
   
   return 0;
}
