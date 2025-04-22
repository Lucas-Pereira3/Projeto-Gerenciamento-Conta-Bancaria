/*Nome: Lucas Da Silva
 Data:18/11/2024
 ObJ: Funçao para consultar as informacao da conta
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */


#include "funcoes.h"

 // Funcao para consultar contas
void ConsultarContas(tipolista_conta *L) {
    int consultaOpcao;
    do {
        tela();
        gotoxy(35, 4);
        printf("CONSULTA DE CONTAS BANCARIAS\n");
        gotoxy(33, 10);
        printf("1. Consulta Geral Contas Bancarias\n");
        gotoxy(33, 12);
        printf("2. Consultar por Codigo Contas Bancarias\n");
        gotoxy(33, 14);
        printf("3. Consulta Ordem Codigo Contas Bancarias\n");
        gotoxy(33, 16);
        printf("4. Consultar Ordem Alfabetica Contas Bancarias\n");
        gotoxy(33, 18);
        printf("5. Retornar ao Menu Anterior\n");
        gotoxy(7, 26);
        printf("Escolha uma opcao: ");
        scanf("%d", &consultaOpcao);

        // Inicia switch para processar a opcao escolhida
        switch (consultaOpcao) {
            case 1:
                ConsultarTodasContaBancarias(L);
                break;
            case 2:
                ConsultarContaPorCodigo(L);
                break;
            case 3:
                OrdenarContasPorCodigo(L);
                break;
            case 4:
                OrdenarContasPorAlfabeto(L);
                break;
            case 5:
                break;  
            default:
                gotoxy(7, 26);
                printf("Opcao invalida!\n");
                getch();  
        }
    } while (consultaOpcao != 5);  
}