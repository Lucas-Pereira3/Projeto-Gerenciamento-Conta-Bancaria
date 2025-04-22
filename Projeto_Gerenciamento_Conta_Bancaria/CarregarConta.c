/*Nome: Lucas Da Silva
 Data:25/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */


#include "funcoes.h"

// Funcao carregar contas Bancarias
void carregarContas(tipolista_conta *L) {
    tela();
    FILE *file = fopen("contas.dat", "rb");
    if (file == NULL) {
        printf("Nenhum arquivo de contas encontrado.\n");
        return;
    }
    Reg_conta conta;
    while (fread(&conta, sizeof(Reg_conta), 1, file)) {
        tipoitem *novoItem = (tipoitem *)malloc(sizeof(tipoitem));
        novoItem->conteudo = conta;
        novoItem->proximo = NULL;

        if (L->primeiro == NULL) {
            L->primeiro = novoItem;
            L->ultimo = novoItem;
        } else {
            L->ultimo->proximo = novoItem;
            L->ultimo = novoItem;
        }
    }
    fclose(file);
    gotoxy(7,26);
    printf("Contas carregadas com sucesso!\n");
    getch();
}