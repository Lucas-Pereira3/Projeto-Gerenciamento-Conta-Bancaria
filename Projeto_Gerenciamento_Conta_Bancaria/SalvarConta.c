/*Nome: Lucas Da Silva
 Data:25/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */


#include "funcoes.h"

// Funcaes de Salvar para contas
void salvarContas(tipolista_conta *L) {
    FILE *file = fopen("contas.dat", "wb");
    if (file == NULL) {
        printf("Erro ao abrir arquivo para salvar contas!\n");
        return;
    }
    tipoitem *item = L->primeiro;
    while (item != NULL) {
        fwrite(&item->conteudo, sizeof(Reg_conta), 1, file);
        item = item->proximo;
    }
    fclose(file);
    gotoxy(7,27);
    printf("Contas salvas com sucesso!\n");
}