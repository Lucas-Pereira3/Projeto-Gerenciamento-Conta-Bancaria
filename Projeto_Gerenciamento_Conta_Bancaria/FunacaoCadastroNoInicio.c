/*Nome: Jhontan de souza.
 Data:09/11/2024.
 ObJ: criar uma função que cadastra contas no Inicio da lista
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"

void CadastrarContaInicio(tipolista_conta *L) {
    int resposta = 0;

    do {
        Reg_conta* novaConta = (Reg_conta*)malloc(sizeof(Reg_conta));  // Aloca espaço para nova conta
        tipoitem* novoItem = NULL;  // Inicializa o ponteiro para item da lista

        // Loop para capturar o código da conta
        do {
            tela();
            telaContaBancaria();
            gotoxy(34, 4);
            printf("CADASTRAR CONTA NO INICIO");
            gotoxy(67, 6);
            printf("              ");
            gotoxy(7, 26);
            printf("Digite 0 para sair\n");
            gotoxy(24, 7);
            scanf("%d", &novaConta->codigo_conta);
            
            // Verifica se o usuário digitou 0 para sair
            if (novaConta->codigo_conta == 0) {
                // Pergunta se o usuário deseja cadastrar outra conta
                gotoxy(7, 26);
                printf("Deseja cadastrar outra conta? (1-Sim / 2-Nao): ");
                scanf("%d", &resposta);
                if (resposta == 2) {
                    free(novaConta);  // Libera a memória alocada
                    return;  // Sai da função sem cadastrar a conta
                } else {
                    continue;  // Volta para o início e começa o processo novamente
                }
            }

            novoItem = pesquisarConta(L, novaConta->codigo_conta);  // Verifica se o código já está cadastrado
            if (novoItem != NULL) {
                gotoxy(7, 26);
                printf("Codigo da conta ja cadastrado!\n");
                getch();  // Aguarda o usuário pressionar uma tecla para continuar
            }

        } while (novoItem != NULL); // Continua pedindo o código até ser válido

        // Se o código for válido, continua com o cadastro
        if (novaConta->codigo_conta == 0) {
            continue;  // Se o usuário digitou 0, ele retorna ao início do loop
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
                getchar();  // Usar getchar em vez de getch
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
        gotoxy(24, 21);

        novaConta->status = 1;

        gotoxy(24, 21);  
        printf("%d", novaConta->status);

        // Pergunta ao usuário se deseja gravar os dados
        gotoxy(7, 26);
        printf("                                                      ");
        gotoxy(7, 26);
        printf("Deseja gravar os dados? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);

        if (resposta == 1) {
            novoItem = (tipoitem*)malloc(sizeof(tipoitem));  // Aloca memória para novoItem
            novoItem->conteudo = *novaConta;  // Atribui o conteúdo da conta ao novo item
            novoItem->proximo = L->primeiro; // Aponta para o primeiro elemento

            // Atualiza a lista
            L->primeiro = novoItem;  // O novo item se torna o primeiro
            if (L->ultimo == NULL) {  // Se a lista estava vazia
                L->ultimo = novoItem; // O novo item é o último também
            }

            gotoxy(7, 27);
            printf("Conta cadastrada com sucesso!");
        }

        free(novaConta); // Libera a memória da conta temporária

        // Pergunta se deseja cadastrar outra conta
        gotoxy(7, 26);
        printf("                                                           ");
        gotoxy(7, 26);
        printf("Deseja cadastrar outra conta? (1-Sim / 2-Nao): ");
        scanf("%d", &resposta);
        gotoxy(7, 27);
      
    } while (resposta == 1);  // Se for 1, o loop continua para cadastrar outra conta
}