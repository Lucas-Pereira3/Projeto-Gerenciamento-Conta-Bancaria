/*Nome: Lucas Da Silva
 Data:09/11/2024
 ObJ: Funçao para remover conta no final da lista
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */

#include "funcoes.h"

// Funcao para remover conta no final
void removerContaFinal(tipolista_conta *L) {
    int resposta = 0;
    do {
        tela();
        telaContaBancaria();
            gotoxy(34, 4);
            printf("REMOVER CONTA NO FINAL");
        // Verifica se a lista esta vazia
        if (L->primeiro == NULL) {
            gotoxy(7, 26);
            printf("Lista vazia! Nenhuma conta para remover.");
            getch();
            return;
        }

        // Percorrer a lista para encontrar o ultimo item (conta a ser removida)
        tipoitem *item = L->primeiro;
        tipoitem *anterior = NULL;
        // Encontra o ultimo item da lista
        while (item->proximo != NULL) {
            anterior = item;
            item = item->proximo;
        }

        // Exibir os dados da conta a ser removida
        gotoxy(24, 7);
        printf("%d", item->conteudo.codigo_conta);
        gotoxy(24, 9);
        printf("%s", item->conteudo.banco);
        gotoxy(24, 11);
        printf("%s", item->conteudo.agencia);
        gotoxy(24, 13);
        printf("%s", item->conteudo.numero_conta);
        gotoxy(24, 15);
        printf("%s", item->conteudo.tipo_conta);
        // Se o tipo da conta for 1, 2 ou 3, exibe o tipo de conta de forma mais detalhada
        if (item->conteudo.tipo_conta[0] == '1'){
        gotoxy(24, 15);
        printf("1-Corrente");
        } else if (item->conteudo.tipo_conta[0] == '2'){
        gotoxy(24, 15);
        printf("2-Poupanca");
        } else if (item->conteudo.tipo_conta[0] == '3'){
        gotoxy(24, 15);
        printf("3-Cartao Credito");
        } 
        gotoxy(24, 17);
        printf("%.2lf", item->conteudo.vl_saldo);
        gotoxy(24, 19);
        printf("%.2lf", item->conteudo.vl_limite);
         item->conteudo.status = 1;

        gotoxy(24, 21);  
        printf("%d", item->conteudo.status);

        // Perguntar ao usuario se deseja remover esta conta
        gotoxy(7, 26);
        printf("Deseja remover esta conta? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);

        // Se o usuario escolher 1 (Sim), remove a conta
        if (resposta == 1) {
            // Se a conta for a unica na lista
            if (anterior == NULL) {
                L->primeiro = NULL;
                L->ultimo = NULL;
            } else {
                // Remover o ultimo item
                anterior->proximo = NULL;
                L->ultimo = anterior;
            }

            free(item); // Libera a memoria da conta removida
            gotoxy(7, 26);
            printf("Conta removida com sucesso!");

        }

        // Perguntar se deseja remover outra conta
        gotoxy(7, 26);
        printf("Deseja remover outra conta? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);

    } while (resposta == 1); // Repete o processo se a resposta for 1 (Sim)
}