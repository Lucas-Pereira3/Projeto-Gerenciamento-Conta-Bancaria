/*Nome: Lucas Da Silva
 Data:09/11/2024
 ObJ: Funcao para remover uma conta em uma posicao na lista
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */



#include "funcoes.h"

 //Funcao para remover conta em uma posicao
void removerContaPosicao(tipolista_conta *L) {
    int posicao, resposta; 

    do {
        tela();  
        telaContaBancaria();  
        gotoxy(34, 4);  
        printf("REMOVER CONTA EM POSICOES");  

        // Verifica se a lista esta vazia
        if (L->primeiro == NULL) {
            gotoxy(7, 26);  
            printf("Lista vazia! Nenhuma conta para remover.");
            getch();  
            return;  
        }

        // Solicita ao usuario a posicao da conta que ele deseja remover
        gotoxy(7, 26);  
        printf("Digite a posicao para remover: ");
        scanf("%d", &posicao);  

        // Verifica se a posicao e valida (não pode ser menor que 1)
        if (posicao < 1) {
            gotoxy(7, 26);  
            printf("Posição invalida!");
            getch();  
            return;  
        }

        tipoitem *item = L->primeiro;  // Ponteiro para percorrer a lista de contas
        tipoitem *anterior = NULL;  // Ponteiro para o item anterior ao que esta sendo removido

        // Percorre a lista ate encontrar a posicao desejada
        for (int contador = 1; contador < posicao; contador++) {
            anterior = item;  // Atualiza o ponteiro anterior
            item = item->proximo;  // Avanca para o proximo item

            // Verifica se a posicao fornecida e maior que o numero de elementos na lista
            if (item == NULL) {
                gotoxy(7, 26);  
                printf("Posicao Invalida!");
                getch();  
                return;  
            }
        }

        // Exibe as informacoes da conta que sera removida
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
        if (item->conteudo.tipo_conta[0] == '1') {
            gotoxy(24, 15);  
            printf("1-Corrente");
        } else if (item->conteudo.tipo_conta[0] == '2') {
            gotoxy(24, 15);  
            printf("2-Poupanca");
        } else if (item->conteudo.tipo_conta[0] == '3') {
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

        // Pergunta ao usuario se ele deseja remover a conta
        gotoxy(7, 26);  
        printf("Deseja remover esta conta? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta); 

        // Se o usuario desejar remover a conta (resposta = 1)
        if (resposta == 1) {
            // Caso a conta a ser removida seja a primeira da lista
            if (anterior == NULL) {
                L->primeiro = item->proximo;  // O ponteiro primeiro agora aponta para o proximo item

                // Se a lista estiver vazia apos remocao, atualiza o ponteiro ultimo para NULL
                if (L->primeiro == NULL) {
                    L->ultimo = NULL;  
                }
            } else {
                // Se a conta a ser removida nao for a primeira, ajusta o ponteiro proximo do item anterior
                anterior->proximo = item->proximo;

                // Se a conta removida for a ultima da lista, atualiza o ponteiro ultimo
                if (item->proximo == NULL) {
                    L->ultimo = anterior;  // O ultimo item passa a ser o anterior ao item removido
                }
            }

            free(item); 
            gotoxy(7, 26);  
            printf("                                                 ");  
            gotoxy(7, 26);  
            printf("Conta removida com sucesso!"); 
        } else {
            // Se o usuario nao desejar remover a conta
            gotoxy(7, 26);  
            printf("                                                 ");  
            gotoxy(7, 26);  
            printf("Remocao cancelada.");  
        }

        getch();  

        // Pergunta se o usuario deseja remover outra conta
        gotoxy(7, 26);  
        printf("Deseja remover outra conta? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);  

    } while (resposta == 1);  // Repete o processo se a resposta for 1 (Sim)

}