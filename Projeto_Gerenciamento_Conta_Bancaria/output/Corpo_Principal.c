 /*nome:
   
 */
 
 // Incluindo a biblioteca
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

#include "funções.h"


// Funcao principal
int main() {
    int opcao;

 //  Um loop que sera executado até que a opcao de sair seja escolhida
    do {
        tela();
        gotoxy(35, 6);
        printf("MENU PRINCIPAL\n");
        gotoxy(10, 10);
        printf("1. Cadastro de Contas\n");
        gotoxy(10, 12);
        printf("2. Movimentacao Financeira\n");
        gotoxy(10, 14);
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
                printf("Submenu Cadastro de Contas:\n");
                gotoxy(10, 8);
                printf("1. Cadastrar Contas Bancarias no Final\n");
                gotoxy(10, 10);
                printf("2. Cadastrar Contas Bancarias no Inicio\n");
                gotoxy(10, 12);
                printf("3. Cadastrar Contas Bancarias na Posicao\n");
                gotoxy(10, 14);
                printf("4. Remover Contas Bancarias no Final\n");
                gotoxy(10, 16);
                printf("5. Remover Contas Bancarias no Inicio\n");
                gotoxy(10, 18);
                printf("6. Remover Contas Bancarias na Posicao\n");
                gotoxy(10, 20);
                printf("7. Alteracao de Contas Bancarias\n");
                gotoxy(10, 22);
                printf("8. Consultar Contas Bancarias\n");
                gotoxy(10, 24);
                printf("9. Retornar ao Menu Anterior\n");
                gotoxy(7, 26);
                printf("Escolha uma opcao: ");
                scanf("%d", &subOpcao);

// Inicia switch para processar a sub-opcao escolhida
                switch (subOpcao) {
                    case 1:
                        CadastrarContaFinal();
                        break;
                    case 2:
                        CadastrarContaInicio();
                        break;
                    case 3:
                        
                        break;
                    case 4:
                        
                        break;
                    case 5:

                         break;
                    case 6:

                        break;
                    case 7:

                        break;
                    case 8:
                        ConsultarConta();
                        break;
                    case 9:
                        break;
                    default: 
                        printf("Opcao invalida!\n");
                }
            }while(subOpcao != 9);
                break;
            }
        
            // Movimentacao Financeira
            case 2: {
                int movOpcao;

                gotoxy(35, 5);
                printf("TELA DE MOVIMENTACAO FINANCEIRA:\n");
                gotoxy(10, 10);
                printf("1. Registrar Entrada\n");
                gotoxy(10, 12);
                printf("2. Registrar Saida\n");
                gotoxy(10, 14);
                printf("3. Consultar Movimentacao\n");
                gotoxy(7, 26);
                printf("Escolha uma opcao: ");
                scanf("%d", &movOpcao);

// Inicia switch para processar a opcao de movimentacao
                switch (movOpcao) {
                    case 1:
                       
                        break;
                    case 2:
                        
                        break;
                    case 3:
                        
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;
            }
            case 3:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 3);

    return 0;
}