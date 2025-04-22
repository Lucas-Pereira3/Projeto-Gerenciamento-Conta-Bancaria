/*Nome: Jhontan de souza.
 Data:09/11/2024.
 ObJ: criar uma função que cadastra em posições destro da lista
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"

//
void CadastrarContaPosicao(tipolista_conta *L) {
    int resposta = 0;

    do {
        Reg_conta* novaConta = (Reg_conta*)malloc(sizeof(Reg_conta));
        tipoitem* novoItem = NULL;

        // Loop para garantir que o código da conta seja único
        do {
            tela();
            telaContaBancaria();
            gotoxy(34, 4);
            printf("CADASTRAR CONTA EM POSICAO");
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
                    free(novaConta);  // Libera a memória ao sair do cadastro
                    return; // Sai da função, encerrando o cadastro
                } else {
                    continue; // Continua o loop de cadastro
                }
            }

            novoItem = pesquisarConta(L, novaConta->codigo_conta);
            if (novoItem != NULL) {
                gotoxy(7, 26);
                printf("Codigo da conta ja cadastrado!");
                getch();  // Aguarda uma tecla para continuar
            }
        } while (novoItem != NULL);

        if (novaConta->codigo_conta == 0) {
            continue; // Se o código for 0, continua pedindo o código
        }

        // Coletando informações da nova conta
        gotoxy(24, 9);
        getchar(); 
        fgets(novaConta->banco, 50, stdin);
        gotoxy(24, 11);
        fflush(stdin); 
        fgets(novaConta->agencia, 10, stdin);
        gotoxy(24, 13);
        fflush(stdin); 
        fgets(novaConta->numero_conta, 20, stdin);

        // Tipo de conta
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
                printf("                                            ");
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

        // Pergunta ao usuário em qual posição deseja inserir a conta
        gotoxy(7, 26);
        printf("                                                                            ");
        gotoxy(7, 26);
        printf("Digite qual a posicao: ");
        int posicao;
        scanf("%d", &posicao);

        // Pergunta ao usuário se deseja gravar os dados
        gotoxy(7, 26);
        printf("                                                                        ");
        gotoxy(7, 26);
        printf("Deseja gravar os dados? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);

        if (resposta == 1) {
            tipoitem* novoItem = (tipoitem*)malloc(sizeof(tipoitem));

            // Cópia da nova conta para o novo item
            novoItem->conteudo = *novaConta;

            // Inserção na lista conforme a posição escolhida
            if (posicao == 1) {  // Inserir no início
                novoItem->proximo = L->primeiro;
                L->primeiro = novoItem;
                if (L->ultimo == NULL) {
                    L->ultimo = novoItem; // Se a lista estava vazia
                }
            } else {
                tipoitem* temp = L->primeiro;
                int count = 1;

                // Verifica se a posição é válida
                while (temp != NULL && count < posicao - 1) {
                    temp = temp->proximo;
                    count++;
                }

                // Se temp for NULL ou a posição for maior que o número de itens, insere no final
                if (temp == NULL && count != posicao - 1) {
                    gotoxy(7, 27);
                    printf("Posicao invalida! A lista nao tem tantas contas.\n");
                    free(novoItem);  // Libera a memória do novo item
                    continue;  // Volta ao início do loop
                } else {
                    // Se a posição for válida, insere a conta no local especificado
                    novoItem->proximo = temp->proximo;
                    temp->proximo = novoItem;

                    // Se a conta foi inserida no final, atualiza o último item da lista
                    if (novoItem->proximo == NULL) {
                        L->ultimo = novoItem;
                    }
                }
            }

            gotoxy(7, 27);
            printf("Conta cadastrada com sucesso!");
        }

        // Libera a memória da conta temporária após a inserção
        free(novaConta);

        // Pergunta se deseja cadastrar outra conta
        gotoxy(7, 26);
        printf("Deseja cadastrar outra conta? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);
    } while (resposta == 1);  // Repete o loop se a resposta for 1 (Sim)
}