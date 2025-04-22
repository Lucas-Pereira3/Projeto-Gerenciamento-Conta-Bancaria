/*Nome: Jhontan de souza.
 Data:25/11/2024.
 ObJ: criar uma função que cadastra contas no Inicio da lista
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/
 
#include "funcoes.h"

// Funcaes de salvar movimentacoes
void salvarMovimentacoes(tipolista_movimentacao *M) {
    FILE *file = fopen("movimentacoes.dat", "wb");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para salvar movimentacaes!\n");
        return;
    }
    tipoitem_movimentacao *item = M->primeiro;
    while (item != NULL) {
        fwrite(&item->conteudo, sizeof(Reg_movimentacao), 1, file);
        item = item->proximo;
    }
    fclose(file);
    gotoxy(34 ,27);
    printf("Movimentacaes salvas com sucesso!\n");
}