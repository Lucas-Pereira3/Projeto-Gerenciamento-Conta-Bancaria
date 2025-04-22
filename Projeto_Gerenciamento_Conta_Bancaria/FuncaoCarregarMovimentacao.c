/*Nome: Jhontan de souza.
 Data:25/11/2024.
 ObJ: criar uma função que cadastra contas no Inicio da lista
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/
 
#include "funcoes.h"
void carregarMovimentacoes(tipolista_movimentacao *M) {
    tela();
    FILE *file = fopen("movimentacoes.dat", "rb");
    if (file == NULL) {
        gotoxy(7,26);
        printf("Nenhum arquivo de movimentacaes encontrado.\n");
        return;
    }
    Reg_movimentacao movimentacao;
    while (fread(&movimentacao, sizeof(Reg_movimentacao), 1, file)) {
        tipoitem_movimentacao *novoItem = (tipoitem_movimentacao *)malloc(sizeof(tipoitem_movimentacao));
        novoItem->conteudo = movimentacao;
        novoItem->proximo = NULL;

        if (M->primeiro == NULL) {
            M->primeiro = novoItem;
            M->ultimo = novoItem;
        } else {
            M->ultimo->proximo = novoItem;
            M->ultimo = novoItem;
        }
    }
    fclose(file);
    gotoxy(7,26);
    printf("Movimentacoes carregadas com sucesso!\n");
    getch();
}


tipoapontador_conta pesquisarConta(tipolista_conta *L, int codigo) {
    tipoitem* item = L->primeiro;

    while (item != NULL) {
        if (item->conteudo.codigo_conta == codigo) {
            return item; // Retorna o ponteiro para o item encontrado
        }
        item = item->proximo;
    }
    return NULL; // Retorna NULL se nao encontrar
}