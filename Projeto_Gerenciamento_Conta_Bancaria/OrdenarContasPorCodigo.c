/*Nome: Jhontan de souza.
 Data:09/11/2024.
 ObJ: criar uma função que cadastra contas no Inicio da lista
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"

void OrdenarContasPorCodigo(tipolista_conta *L) {
    if (L->primeiro == NULL) {
        gotoxy(7, 26);
        printf("Lista esta vazia. Nenhuma conta para consultar.");
        getch();
        return;
    }

    // Ordenar as contas pelo código da conta (ordem crescente)
    int trocado;
    tipoitem *item, *item2;
    Reg_conta temp;


    // Ordenação das contas por código (ordem crescente)
    do {
        trocado = 0;
        item = L->primeiro;

        while (item->proximo != NULL) {
            item2 = item->proximo;
            if (item->conteudo.codigo_conta > item2->conteudo.codigo_conta) {
                // Trocar os conteúdos das contas
                temp = item->conteudo;
                item->conteudo = item2->conteudo;
                item2->conteudo = temp;
                trocado = 1;
            }
            item = item->proximo;
        }
    } while (trocado);  // Continuar até que não haja mais trocas

    // Exibir cabeçalho da tela de consulta
    tela();
    telaConsultaContas();
    gotoxy(34, 4);
    printf("CONTAS ORDENADAS PRO CODIGO");

    // Variáveis para somar o saldo e limite
    double totalSaldo = 0.0;
    double totalLimite = 0.0;

    // Exibir as contas ordenadas
    item = L->primeiro;  // Resetar item para o início da lista

    int linha = 9;  // Iniciar na linha 9 para começar a exibir as contas abaixo do cabeçalho
    while (item != NULL) {
        gotoxy(2, linha);  // Ajuste a posição para cada item
        printf("%d", item->conteudo.codigo_conta);
        gotoxy(5, linha);
        printf("%s", item->conteudo.banco);
        gotoxy(25, linha);
        printf("%s", item->conteudo.agencia);
        gotoxy(31, linha);
        printf("%s", item->conteudo.numero_conta);
        gotoxy(40, linha);
        printf("%s", item->conteudo.tipo_conta);
        if (item->conteudo.tipo_conta[0] == '1'){
            gotoxy(40, linha);
            printf("Corrente");
        } else if (item->conteudo.tipo_conta[0] == '2'){
            gotoxy(40, linha);
            printf("Poupanca");
        } else if (item->conteudo.tipo_conta[0] == '3'){
            gotoxy(40, linha);
            printf("Cartao Credito");
        }      
        gotoxy(55, linha);
        printf("R$ %.2lf", item->conteudo.vl_saldo);
        gotoxy(67, linha);
        printf("R$ %.2lf", item->conteudo.vl_limite);
        gotoxy(78, linha);
        printf("%d", item->conteudo.status);

        // Atualizar a soma total dos saldos e limites
        totalSaldo += item->conteudo.vl_saldo;
        totalLimite += item->conteudo.vl_limite;

        // Atualiza o status da conta
        item->conteudo.status = 1;

        item = item->proximo;  // Avançar para o próximo item
        linha++;  // Incrementar a linha para a próxima conta
    }

    // Exibir a soma total dos saldos e limites após a exibição das contas
    linha++;  // Pular uma linha para exibir os totais
    gotoxy(43, linha + 1);  
    printf("Saldo Total: R$ %.2lf R$ %.2lf ", totalSaldo, totalLimite);

    gotoxy(7, 26);
    printf("Pressione uma tecla para continuar...");
    getch();
}