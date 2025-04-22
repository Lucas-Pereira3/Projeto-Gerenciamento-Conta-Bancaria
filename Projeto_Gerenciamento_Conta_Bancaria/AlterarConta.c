/*Nome: Lucas Da Silva
 Data:09/11/2024
 ObJ: Funçao para alterar as informacao da conta
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */

#include "funcoes.h"

 // Funcao para alterar conta bancaria
void alterarConta(tipolista_conta *L) {
    int codigo;     
    int campo;      
    int resposta;   

    tipoitem* item = L->primeiro;  // Ponteiro para percorrer a lista de contas

    // Verifica se a lista esta vazia
    if (L->primeiro == NULL) {
        gotoxy(7, 26);  
        printf("Lista vazia! Nenhuma conta para alterar.");
        getch();  
        return;   
    }

    tela();  
    telaContaBancaria();  
    gotoxy(39, 4);  
    printf("ALTERACAO DE CONTA");
    gotoxy(7, 26);  
    printf("Digite 0 para sair\n");
    gotoxy(24, 7);  
    scanf("%d", &codigo); 

    // Se o usuario digitar 0, a funcao e encerrada
    if (codigo == 0) {
        return;  
    }

    // Chama a funcao pesquisarConta para procurar a conta pelo codigo
    item = pesquisarConta(L, codigo);

    // Se a conta nao for encontrada, exibe uma mensagem e retorna
    if (item == NULL) {
        gotoxy(7, 26);  
        printf("Conta nao encontrada!");
        getch();  
        return;  
    }

    // Exibe as informacoes da conta encontrada
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
    gotoxy(24, 21);  
    printf("%d", item->conteudo.status);  

    do {
        do {
            // Pergunta qual campo deseja alterar
            gotoxy(7, 26);  
            printf("                                                    ");
            gotoxy(7, 26);  
            printf("Deseja alterar qual campo? (0-sair): ");
            scanf("%d", &campo);  

            // Se o campo informado for invalido, repete a solicitacao
            if (campo < 0 || campo > 7) {
                gotoxy(7, 26);  
                printf("Campo invalido. Digite um valor entre 0 e 7.");
                getch();  
            }
        } while (campo < 0 || campo > 7);  // Enquanto o campo for invalido, solicita novamente

        // Se o campo escolhido for 0, sai do loop
        if (campo == 0) {
            break;  
        }

        // Solicita a alteracao do campo escolhido
        switch (campo) {
            case 1:
                gotoxy(24, 9);  
                printf("               ");  
                gotoxy(24, 9);  
                scanf("%s", item->conteudo.banco); 
                break;
            case 2:
                gotoxy(24, 11);  
                printf("                ");  
                gotoxy(24, 11);  
                scanf("%s", item->conteudo.agencia);  
                break;
            case 3:
                gotoxy(24, 13);  
                printf("                 ");  
                gotoxy(24, 13);  
                scanf("%s", item->conteudo.numero_conta);  
                break;
            case 4:
                gotoxy(24, 15);  
                printf("                 ");  
                gotoxy(24, 15);  
                scanf("%s", item->conteudo.tipo_conta);  
                break;
            case 5:
                gotoxy(24, 17);  
                printf("                  ");  
                gotoxy(24, 17);  
                scanf("%lf", &item->conteudo.vl_saldo); 
                break;
            case 6:
                gotoxy(24, 19);  
                printf("                  ");  
                gotoxy(24, 19);  
                scanf("%lf", &item->conteudo.vl_limite);  
                break;
            case 7:
                gotoxy(24, 21);  
                printf("                  ");  
                gotoxy(24, 21);  
                scanf("%d", &item->conteudo.status);  
                break;
        }

        // Pergunta ao usuario se deseja confirmar a alteracao
        do {
            gotoxy(7, 26);  
            printf("                                                            ");
            gotoxy(7, 26);  
            printf("Deseja confirmar a alteracao? (1-Sim / 2-Nao): ");
            scanf("%d", &resposta);  

            // Se a resposta nao for 1 ou 2, repete a solicitacao
            if (resposta != 1 && resposta != 2) {
                gotoxy(7, 26); 
                printf("Opcao invalida! Digite 1 para Sim ou 2 para Nao.");
                getch();  
            }
        } while (resposta != 1 && resposta != 2);  // Enquanto a resposta nao for valida, solicita novamente

        // Se a resposta for 1, confirma a alteração
        if (resposta == 1) {
            gotoxy(7, 27);  
            printf("                                                            ");
            gotoxy(7, 27);  
            printf("Alteracao realizada com sucesso!");  
        } else {
            gotoxy(7, 27);  
            printf("                                                            ");
            gotoxy(7, 27);  
            printf("Alteracao cancelada!");  // Exibe a mensagem de cancelamento
        }

        getch();  
        // Pergunta se o usuario deseja alterar outro campo
        gotoxy(7, 26);  
        printf("                                                            ");
        gotoxy(7, 26);  
        printf("Deseja alterar outro campo? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);  
    } while (resposta == 1);  // Repete o processo se a resposta for 1 (Sim)
}