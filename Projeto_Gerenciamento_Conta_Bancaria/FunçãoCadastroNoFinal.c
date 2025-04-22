/*Nome: Jhontan de souza.
 Data:09/11/2024.
 ObJ: criar uma função que cadastra contas no final da lista
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"


void CadastrarContaFinal(tipolista_conta *L) {
    int resposta = 0;
    do {
        Reg_conta* novaConta = (Reg_conta*)malloc(sizeof(Reg_conta)); // Aloca memoria para nova conta
        tipoitem* novoItem = NULL;

        do {
            tela();
            telaContaBancaria();
            gotoxy(34, 6);
            printf("CADASTRAR CONTA NO FINAL");
            gotoxy(67, 6);
            printf("              ");
            gotoxy(7, 26);
            printf("Digite 0 para sair\n");
            gotoxy(24, 7);
            scanf("%d", &novaConta->codigo_conta);

            if (novaConta->codigo_conta == 0) {
                gotoxy(7, 26);
                printf("Deseja cadastrar outra conta? (1-Sim / 2-Nao): ");
                scanf("%d", &resposta);
                if (resposta == 2) {
                    free(novaConta);  // Libera a memória alocada
                    return;  // Sai da função sem cadastrar a conta
                } else {
                    continue;  // Volta ao início do loop para continuar o cadastro
                }
            }

            // Verifica se o código da conta já existe
            novoItem = pesquisarConta(L, novaConta->codigo_conta);
            if (novoItem != NULL) {
                gotoxy(7, 26);
                printf("Codigo da conta ja cadastrado!\n");
                getch();  // Aguarda o usuário pressionar uma tecla
                // Não libera a memória aqui, pois vamos continuar com o loop
            }

        } while (novoItem != NULL);  // Continua pedindo o código até ser único

        if (novaConta->codigo_conta == 0) {
            continue;  // Se o código for 0, volta ao início do loop
        }

        // Coleta as informações da nova conta
        gotoxy(24, 9);
        getchar();  // Limpa o buffer de entrada
        fgets(novaConta->banco, 50, stdin);
        gotoxy(24, 11);
        fflush(stdin);
        fgets(novaConta->agencia, 10, stdin);
        gotoxy(24, 13);
        fflush(stdin);
        fgets(novaConta->numero_conta, 20, stdin);

        // Seleção do tipo de conta
        do {
            gotoxy(07, 26);
            printf("Utilizar: 1=Corrente / 2=Poupanca / 3=Cartao Credito");
            gotoxy(24, 15);
            fflush(stdin);
            fgets(novaConta->tipo_conta, 20, stdin);
            if (novaConta->tipo_conta[0] == '1') {
                gotoxy(24, 15);
                printf("1-Corrente");
            } else if (novaConta->tipo_conta[0] == '2') {
                gotoxy(24, 15);
                printf("2-Poupanca");
            } else if (novaConta->tipo_conta[0] == '3') {
                gotoxy(24, 15);
                printf("3-Cartao Credito");
            } else {
                gotoxy(7, 26);
                printf("                                                        ");
                gotoxy(7, 26);
                printf("Tipo de Conta invalido");
                getch();
                gotoxy(52, 15);
                printf("  ");
            }
        } while (novaConta->tipo_conta[0] != '1' && novaConta->tipo_conta[0] != '2' && novaConta->tipo_conta[0] != '3');

        gotoxy(24, 17);
        fflush(stdin);
        scanf("%lf", &novaConta->vl_saldo);
        gotoxy(24, 19);
        fflush(stdin);
        scanf("%lf", &novaConta->vl_limite);

        // Define o status como 1 (ativo) automaticamente
        novaConta->status = 1;

        // Exibe o valor de status automaticamente na tela
        gotoxy(24, 21);
        printf("%d", novaConta->status);

        // Pergunta ao usuário se deseja gravar os dados
        gotoxy(7, 26);
        printf("                                                           ");
        gotoxy(7, 26);
        printf("Deseja gravar os dados? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);

        if (resposta == 1) {
            tipoitem* novoItem = (tipoitem*)malloc(sizeof(tipoitem));
            novoItem->conteudo = *novaConta; // Atribui a conta ao novo item
            novoItem->proximo = NULL;

            // Adiciona o item no final da lista
            if (L->primeiro == NULL) {
                L->primeiro = novoItem;
                L->ultimo = novoItem;
            } else {
                L->ultimo->proximo = novoItem;
                L->ultimo = novoItem;
            }

            gotoxy(7, 27);
            printf("Conta cadastrada com sucesso!\n");
        }

        free(novaConta);  // Libera a memória de novaConta

        // Pergunta se deseja cadastrar outra conta
        gotoxy(7, 26);
        printf("                                                              ");
        gotoxy(7, 26);
        printf("Deseja cadastrar outra conta? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);
    } while (resposta == 1);  // Repete o loop se a resposta for 1 (Sim)
}