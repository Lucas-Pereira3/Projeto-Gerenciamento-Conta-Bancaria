/*Nome: Lucas Da Silva
 Data:24/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */

#include "funcoes.h"

// Funcao para fazer tranferencias entre contas bancarias
void transferirEntreContas(tipolista_conta *L, tipolista_movimentacao *M) {
    int codigoOrigem, codigoDestino, opcao;
    float valor;
    char dataTransferencia[11];
    tipoapontador_conta contaOrigem, contaDestino;
    Reg_movimentacao movOrigem, movDestino;

    do {
        tela();
        Tela_Transacao();

        // Solicitar os codigos das contas
        gotoxy(7, 26);
        printf("Digite 0 para sair.");
        gotoxy(12, 10);
        printf("Conta de origem: ");
        scanf("%d", &codigoOrigem);
        

        if (codigoOrigem == 0) {
            return; // Se digitar 0, sai da funcao
        }

        gotoxy(55, 10);
        printf("Conta de destino: ");
        scanf("%d", &codigoDestino);

        if (codigoDestino == 0) {
            return; // Se digitar 0, sai da funcao
        }

        // Buscar as contas
        contaOrigem = pesquisarConta(L, codigoOrigem);
        contaDestino = pesquisarConta(L, codigoDestino);

        if (contaOrigem == NULL || contaDestino == NULL) {
            gotoxy(7, 26);
            printf("Uma ou ambas as contas nao foram encontradas!");
            getch();
            return;
        }

    // Exibir detalhes das contas 
    gotoxy(29, 11);
    printf("%s", contaOrigem->conteudo.banco);
    gotoxy(73, 11);
    printf("%s", contaDestino->conteudo.banco);

    gotoxy(29, 12);
    printf("%s", contaOrigem->conteudo.agencia);
    gotoxy(73, 12);
    printf("%s", contaDestino->conteudo.agencia);

    gotoxy(29, 13);
    printf("%s", contaOrigem->conteudo.numero_conta);
    gotoxy(73, 13);
    printf("%s", contaDestino->conteudo.numero_conta);

    gotoxy(29, 14);
    printf("%s", contaOrigem->conteudo.tipo_conta);
    if (contaOrigem->conteudo.tipo_conta[0] == '1'){
        gotoxy(29, 14);
        printf("Corrente");
    } else if (contaOrigem->conteudo.tipo_conta[0] == '2'){
        gotoxy(29, 14);
        printf("Poupanca");
    } else if (contaOrigem->conteudo.tipo_conta[0] == '3'){
        gotoxy(29, 14);
        printf("Cartao Credito");
    }
    gotoxy(73, 14);
    printf("%s", contaDestino->conteudo.tipo_conta);
    if (contaDestino->conteudo.tipo_conta[0] == '1'){
            gotoxy(73, 14);
            printf("Corrente");
        } else if (contaDestino->conteudo.tipo_conta[0] == '2'){
            gotoxy(73, 14);
            printf("Poupanca");
        } else if (contaDestino->conteudo.tipo_conta[0] == '3'){
            gotoxy(73, 14);
            printf("Cartao Credito");
        }

    gotoxy(29, 15);
    printf("R$%9.2f", contaOrigem->conteudo.vl_saldo);
    gotoxy(73, 15);
    printf("R$%9.2f", contaDestino->conteudo.vl_saldo);

    gotoxy(29, 16);
    printf("R$%9.2f", contaOrigem->conteudo.vl_limite);
    gotoxy(73, 16);
    printf("R$%9.2f", contaDestino->conteudo.vl_limite);

    gotoxy(29, 17);
    printf("R$%9.2f", contaOrigem->conteudo.vl_saldo + contaOrigem->conteudo.vl_limite);
    gotoxy(73, 17);
    printf("R$%9.2f", contaDestino->conteudo.vl_saldo + contaDestino->conteudo.vl_limite);

        // Solicitar o valor da transferencia
        gotoxy(27, 20);
        printf("Valor a ser transferido: ");
        scanf("%f", &valor);

        // Solicitar a data da transferencia
        gotoxy(27, 21);
        printf("Data Da Transferencia..: ");
        gotoxy(52, 21);
        scanf("%s", dataTransferencia);

        // Validar saldo suficiente
        if (contaOrigem->conteudo.vl_saldo < valor) {
            gotoxy(7, 26);
            printf("Saldo insuficiente na conta de origem!");
            getch();
            return;
        }

        // Realizar transferencia
        contaOrigem->conteudo.vl_saldo -= valor;
        contaDestino->conteudo.vl_saldo += valor;

        // Registrar movimentacao da conta de origem (debito)
        if (M->ultimo == NULL) {
            movOrigem.sequencial = 1;
        } else {
            movOrigem.sequencial = M->ultimo->conteudo.sequencial + 1;
        }
        movOrigem.codigoConta = contaOrigem->conteudo.codigo_conta;
        strcpy(movOrigem.dt_Movimento, dataTransferencia);
        strcpy(movOrigem.tp_movimentacao, "Debito");
        strcpy(movOrigem.ds_favorecido, contaDestino->conteudo.numero_conta);
        movOrigem.vl_movimento = valor;
        movOrigem.vl_saldo = contaOrigem->conteudo.vl_saldo;

        // Adicionar movimentacao a lista
        tipoitem_movimentacao *novoMovOrigem = malloc(sizeof(tipoitem_movimentacao));
        novoMovOrigem->conteudo = movOrigem;
        novoMovOrigem->proximo = NULL;

        if (M->primeiro == NULL) {
            M->primeiro = novoMovOrigem;
            M->ultimo = novoMovOrigem;
        } else {
            M->ultimo->proximo = novoMovOrigem;
            M->ultimo = novoMovOrigem;
        }

        // Registrar movimentacao da conta de destino (credito)
        movDestino.sequencial = movOrigem.sequencial + 1;
        movDestino.codigoConta = contaDestino->conteudo.codigo_conta;
        strcpy(movDestino.dt_Movimento, dataTransferencia);
        strcpy(movDestino.tp_movimentacao, "Credito");
        strcpy(movDestino.ds_favorecido, contaOrigem->conteudo.numero_conta);
        movDestino.vl_movimento = valor;
        movDestino.vl_saldo = contaDestino->conteudo.vl_saldo;

        // Adicionar movimentacao a lista
        tipoitem_movimentacao *novoMovDestino = malloc(sizeof(tipoitem_movimentacao));
        novoMovDestino->conteudo = movDestino;
        novoMovDestino->proximo = NULL;

        if (M->primeiro == NULL) {
            M->primeiro = novoMovDestino;
            M->ultimo = novoMovDestino;
        } else {
            M->ultimo->proximo = novoMovDestino;
            M->ultimo = novoMovDestino;
        }

        // Exibir saldos atualizados
        gotoxy(29, 18);
        printf("R$%9.2f", contaOrigem->conteudo.vl_saldo);
        gotoxy(73, 18);
        printf("R$%9.2f", contaDestino->conteudo.vl_saldo);

        // Mensagem de sucesso
        gotoxy(7, 26);
        printf("                                                            ");
        gotoxy(7, 26);
        printf("Transferencia realizada com sucesso!");
        getch();

        // Perguntar se deseja fazer uma nova transferencia
        gotoxy(7, 26);
        printf("Deseja fazer uma nova transferencia? (1-Sim / 2-Nao): ");
        scanf("%d", &opcao);

        if (opcao == 2) {
            break; // Se for 2, sai do loop e termina a funcao
        }

    } while (1); // Loop continuo ate o usuario escolher nao fazer mais transferencias
}