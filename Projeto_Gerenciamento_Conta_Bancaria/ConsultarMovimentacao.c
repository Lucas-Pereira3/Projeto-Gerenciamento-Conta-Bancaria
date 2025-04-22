/*Nome: Lucas Da Silva
 Data:24/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */

#include "funcoes.h"

// Funcao para consultar transferencias e movimentacao
void consultarMovimentacao(tipolista_conta *L, tipolista_movimentacao *M) {
    int codigoConta;
    tipoapontador_conta contaEncontrada; // Para verificar se a conta existe
    tipoapontador_movimentacao atual = M->primeiro;

    // Exibir titulo da tela
    tela();
    TelaConsultaMovimentacao();

    // Solicitar o codigo da conta para consulta
    gotoxy(7, 26);
    printf("Digite 0 para Sair.");
    gotoxy(10, 6);
    scanf("%d", &codigoConta);

    if (codigoConta == 0) {
        return; // Se digitar 0, sai da funcao
    }

    // Verificar se a conta esta cadastrada
    contaEncontrada = pesquisarConta(L, codigoConta);
    if (contaEncontrada == NULL) {
        gotoxy(7, 26);
        printf("Conta não encontrada. Pressione qualquer tecla para continuar...");
        getch();
        return;
    }

    // Exibir os dados da conta
    gotoxy(10, 6);
    printf("%d", contaEncontrada->conteudo.codigo_conta);
    gotoxy(13, 6);
    printf("%s", contaEncontrada->conteudo.banco);
    gotoxy(32, 6);
    printf("Agencia: %s", contaEncontrada->conteudo.agencia);
    gotoxy(50, 6);
    printf("Cta: %s", contaEncontrada->conteudo.numero_conta);
    gotoxy(65, 6);
    printf("Tp: %s", contaEncontrada->conteudo.tipo_conta);
    if (contaEncontrada->conteudo.tipo_conta[0] == '1') {
    gotoxy(69, 6);
    printf("Corrente");
    } else if (contaEncontrada->conteudo.tipo_conta[0] == '2') {
    gotoxy(69, 6);
    printf("Poupanca");
    } else {
    gotoxy(69, 6);
    printf("Cartao Credito");
    }

    // Verificar se ha movimentacoes para a conta
    int encontrouMovimentacao = 0;
    int linha = 10; // A partir da linha 16 para exibir as movimentacoes

    while (atual != NULL) {
        if (atual->conteudo.codigoConta == codigoConta) {
            // Exibir os detalhes da movimentacao
            gotoxy(2, linha);
            printf("%s", atual->conteudo.dt_Movimento);
            gotoxy(13, linha);
            printf("%s", atual->conteudo.ds_favorecido);
            gotoxy(43, linha);
            printf("%s", atual->conteudo.tp_movimentacao);
            gotoxy(57, linha);
            printf("R$%9.2f", atual->conteudo.vl_movimento);
            gotoxy(69, linha);
            printf("R$%9.2f", atual->conteudo.vl_saldo);
            linha++;
            encontrouMovimentacao = 1;
        }
        atual = atual->proximo;
    }

    // Se nao houver movimentacoes, exibir mensagem informativa
    if (!encontrouMovimentacao) {
        gotoxy(7, 27);
        printf("Nenhuma movimentacao registrada para esta conta.");
    }

    // Mensagem final para o usuario
    gotoxy(7, 26);
    printf("Pressione qualquer tecla para continuar...");
    getch(); // Espera o usuario pressionar uma tecla antes de sair
}