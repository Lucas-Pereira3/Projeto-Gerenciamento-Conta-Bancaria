/*Nome: Lucas Da Silva
 Data:08/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */

 // Incluindo a biblioteca


#include "funcoes.h"

// Move o cursor para a posicao (x, y) na tela do console
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Funcao principal
int main() {
    tipolista_conta L = {NULL, NULL};
    tipolista_movimentacao M = {NULL, NULL};
    int opcao;

     // Carregar dados ao iniciar
    carregarContas(&L);
    carregarMovimentacoes(&M);

//  Repete ate que a opcao de sair seja escolhida
    do {
        tela();
        gotoxy(35, 6);
        printf("MENU PRINCIPAL\n");
        gotoxy(33, 13);
        printf("1. Cadastro de Contas\n");
        gotoxy(33, 15);
        printf("2. Movimentacao Financeira\n");
        gotoxy(33, 17);
        printf("3. Sair\n");
        gotoxy(7, 26);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        // Inicia switch para processar a opcao escolhida
        switch (opcao) {

            // Cadastro de Contas
            case 1: {
                int subOpcao;
        do{       
                tela();
                gotoxy(35, 6);
                printf("CADASTRO DE CONTAS\n");
                gotoxy(33, 11);
                printf("1. Cadastrar Contas Bancarias no Final\n");
                gotoxy(33, 12);
                printf("2. Cadastrar Contas Bancarias no Inicio\n");
                gotoxy(33, 13);
                printf("3. Cadastrar Contas Bancarias na Posicao\n");
                gotoxy(33, 14);
                printf("4. Remover Contas Bancarias no Final\n");
                gotoxy(33, 15);
                printf("5. Remover Contas Bancarias no Inicio\n");
                gotoxy(33, 16);
                printf("6. Remover Contas Bancarias na Posicao\n");
                gotoxy(33, 17);
                printf("7. Alteracao de Contas Bancarias\n");
                gotoxy(33, 18);
                printf("8. Consultar Contas Bancarias\n");
                gotoxy(33, 19);
                printf("9. Retornar ao Menu Anterior\n");
                gotoxy(7, 26);
                printf("Escolha uma opcao: ");
                scanf("%d", &subOpcao);

                // Inicia switch para processar a sub-opcao escolhida
                switch (subOpcao) {
                    case 1:
                        CadastrarContaFinal(&L);
                        break;
                    case 2:
                        CadastrarContaInicio(&L);
                        break;
                    case 3:
                        CadastrarContaPosicao(&L);
                        break;
                    case 4:
                        removerContaFinal(&L);
                        break;
                    case 5:
                        removerContaInicio(&L);
                         break;
                    case 6:
                        removerContaPosicao(&L);
                        break;
                    case 7:
                        alterarConta(&L);
                        break;
                    case 8:
                        ConsultarContas(&L);
                        break;
                    case 9:
                        break;
                    default:
                        gotoxy(7, 26); 
                        printf("Opcao invalida!\n");
                        getch();
                }
        }while (subOpcao != 9);
                break;
            }

            // Movimentacao Financeira
            case 2: {
                int movOpcao;
            do{
                
                tela();
                gotoxy(35, 6);
                printf("TELA DE MOVIMENTACAO FINANCEIRA:\n");
                gotoxy(33, 12);
                printf("1. Movimentacao de Debito e Credito\n");
                gotoxy(33, 14);
                printf("2. Transferencia entre Contas Bancarias\n");
                gotoxy(33, 16);
                printf("3. Consulta Movimentacao Bancarias\n");
                gotoxy(33, 18);
                printf("4. Retornar ao Menu Anterior\n");
                gotoxy(7, 26);
                printf("Escolha uma opcao: ");
                scanf("%d", &movOpcao);

                // Inicia switch para processar a opcao de movimentacao
                switch (movOpcao) {
                    case 1:
                        cadastroMovimentacao(&L, &M);
                        break;
                    case 2:
                        transferirEntreContas(&L, &M);
                        break;
                    case 3:
                        consultarMovimentacao(&L, &M);
                        break;
                    case 4:
                        break;
                    default:
                        gotoxy(7, 26);
                        printf("Opcao invalida!\n");
                        getch();
                }
            }while (movOpcao !=4);
                break;
            }
            case 3:
                salvarContas(&L);
                salvarMovimentacoes(&M);
                gotoxy(7, 26);
                printf("Saindo do sistema...\n");
                break;
            default:
                gotoxy(7, 26);
                printf("Opcao invalida!\n");
                getch();
        }
    } while (opcao != 3);

    return 0;
}