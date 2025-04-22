/*Nome: Jhontan de souza.
 Data:24/11/2024.
 ObJ: criar uma função que conta e mostra a quantidade de contas ja cadastradas.
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"


// Funcao para cadastrar movimentacao
void cadastroMovimentacao(tipolista_conta *L, tipolista_movimentacao *M) {
    Reg_conta conta;
    Reg_movimentacao movimento;
    tipoapontador_conta aux2;
    tipoitem_movimentacao *novoItem;
    int resposta, novaMovimentacao;

    do {
        tela();
        TelaCadastroMovimentacao();

        // Configura o proximo numero sequencial
        if (M->primeiro == NULL) {
            movimento.sequencial = 1;  
        } else {
            movimento.sequencial = M->ultimo->conteudo.sequencial + 1;  
        }
        gotoxy(40, 8);
        printf(" %d", movimento.sequencial);
        gotoxy(7, 26);
        printf("Digite 0 para sair.");

        // Solicita o codigo da conta
        gotoxy(41, 9);
        scanf("%d", &conta.codigo_conta);

        // Verifica se o usuario digitou 0 para sair
        if (conta.codigo_conta == 0) {
            return; 
        }

        // Pesquisa a conta pelo codigo
        aux2 = pesquisarConta(L, conta.codigo_conta);
        if (aux2 == NULL) {
            gotoxy(7, 26);
            printf("Conta bancaria nao cadastrada!");
            getch();
            continue; // Volta para o inicio do loop
        }

        // Preenche os dados da conta
        conta = aux2->conteudo;
        gotoxy(41, 10);
        printf("%s", conta.banco);
        gotoxy(41, 11);
        printf("%s", conta.agencia);
        gotoxy(41, 12);
        printf("%s", conta.numero_conta);
        gotoxy(41, 13);
        printf("%s", conta.tipo_conta);
        if (conta.tipo_conta[0] == '1'){
            gotoxy(41, 13);
            printf("Corrente");
        } else if (conta.tipo_conta[0] == '2'){
            gotoxy(41, 13);
            printf("Poupanca");
        } else if (conta.tipo_conta[0] == '3'){
            gotoxy(41, 13);
            printf("Cartao Credito");
        }
        gotoxy(41, 14);
        printf("R$%9.2f", conta.vl_saldo);
        gotoxy(41, 15);
        printf("R$%9.2f", conta.vl_limite);
        gotoxy(41, 16);
        printf("R$%9.2f", conta.vl_saldo + conta.vl_limite);

        // Solicita os dados da movimentacao
        movimento.codigoConta = conta.codigo_conta;
        gotoxy(7, 26);
        printf("                                                           ");
        gotoxy(7, 26);
        printf("Data da Movimentacao (DD/MM/YYYY) ");
        strcpy(movimento.dt_Movimento, le_movimento_data());
        strcpy(movimento.tp_movimentacao, le_movimento_tipo());
        strcpy(movimento.ds_favorecido, le_movimento_favorecido());
        movimento.vl_movimento = le_movimento_valor();

        // Atualiza o saldo dependendo do tipo de movimentacao
        if (strcmp(movimento.tp_movimentacao, "Debito") == 0) {
            movimento.vl_saldo = conta.vl_saldo - movimento.vl_movimento;
            conta.vl_saldo -= movimento.vl_movimento;
        } else if (strcmp(movimento.tp_movimentacao, "Credito") == 0) {
            movimento.vl_saldo = conta.vl_saldo + movimento.vl_movimento;
            conta.vl_saldo += movimento.vl_movimento;
        }

        novoItem = (tipoitem_movimentacao*)malloc(sizeof(tipoitem_movimentacao));
        novoItem->conteudo = movimento;
        novoItem->proximo = NULL;

        // Adicionar a lista
        if (M->primeiro == NULL) {
            M->primeiro = novoItem;
            M->ultimo = novoItem;
        } else {
            M->ultimo->proximo = novoItem;
            M->ultimo = novoItem;
        }
        // Exibe o saldo atualizado
        gotoxy(41, 22);
        printf("R$%9.2f", movimento.vl_saldo);

        // Confirma gravação da movimentacao
        gotoxy(7, 26);
        printf("                                                           ");
        gotoxy(7, 26);
        printf("Confirma gravacao do movimento? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);

        if (resposta == 1) {
            gotoxy(7, 26);
            printf("                                                         ");
            gotoxy(7, 26);
            printf("Movimento gravado com sucesso!");
            getch();
        }

        // Pergunta ao usuario se deseja cadastrar outra movimentacao
        gotoxy(7, 26);
        printf("                                                           ");
        gotoxy(7, 26);
        printf("Cadastrar nova movimentacao? (1-Sim / 2-Nao): ");
        scanf("%d", &novaMovimentacao);

        // Sai do loop se o usuario escolher nao cadastrar outra movimentacao
        if (novaMovimentacao != 1) {
            break;
        }

    } while (1); // Loop continua ate que o usuario escolha nao cadastrar outra movimentacao
}