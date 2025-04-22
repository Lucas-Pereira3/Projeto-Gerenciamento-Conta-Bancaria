/*Nome: Jhontan de souza.
 Data:09/11/2024.
 ObJ: criar uma função que cadastra contas no Inicio da lista
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"

void ConsultarContaPorCodigo(tipolista_conta *L) {
    tipoitem* item;
    int codigo, encontrado, resposta;

    do {
        tela();  
        telaContaBancaria(); 
        gotoxy(34, 4);
        printf("CONSULTAR CONTAS POR POSICAO"); 

        gotoxy(7, 26);
        printf("Digite 0 para sair\n");

        // Solicitar código da conta
        gotoxy(5, 7);
        printf("Codigo da Conta..: ");
        scanf("%d", &codigo);

        // Se o código for 0, sai da função
        if (codigo == 0) {
            return;
        }

        // Inicializar a busca e resetar a variável encontrado
        encontrado = 0;
        item = L->primeiro;  // Resetar o ponteiro para o início da lista

        // Buscar pela conta com o codigo informado
        while (item != NULL) {
            if (item->conteudo.codigo_conta == codigo) {
                tela();  
                telaContaBancaria(); 

                // Exibe os dados da conta encontrada
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

                encontrado = 1;
                break;  
            }
            item = item->proximo;
        }

        // Se a conta nao for encontrada
        if (!encontrado) {
            gotoxy(7, 27);
            printf("Conta com codigo %d nao encontrada.\n", codigo);
        }

        // Perguntar se o usuario quer consultar outra conta
        gotoxy(7, 26);
        printf("Deseja Consultar outra conta? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);

        // Caso a resposta seja invalida, repete a solicitacao
        while (resposta != 1 && resposta != 2) {
            gotoxy(7, 26);
            printf("Resposta invalida! Digite 1 para Sim ou 2 para Nao.\n");
            gotoxy(7, 26);
            printf("Deseja Consultar outra conta? (1-Sim / 2-Nao): ");
            scanf("%d", &resposta);
        }

    } while (resposta == 1);  // Continua o loop se a resposta for 1 (Sim)
}