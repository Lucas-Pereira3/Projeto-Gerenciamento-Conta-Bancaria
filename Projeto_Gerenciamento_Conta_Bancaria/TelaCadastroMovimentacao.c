/*Nome: Lucas Da Silva
 Data:22/11/2024
 ObJ: Funçao para remover conta no inicio da lista
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */
#include "funcoes.h"

void TelaCadastroMovimentacao(){

    gotoxy(39, 4);
    printf("CADASTRAR MOVIMENTACAO BANCARIA");
    gotoxy(16, 8);
    printf("Sequencia Movimentacao.:");
    gotoxy(16, 9);
    printf("Codigo da Conta........:");
    gotoxy(16, 10);
    printf("Banco..................:");
    gotoxy(16, 11);
    printf("Agencia................:");
    gotoxy(16, 12);
    printf("Numero da Conta........:");
    gotoxy(16, 13);
    printf("Tipo da Conta..........:");
    gotoxy(16, 14);
    printf("Saldo..................:");
    gotoxy(16, 15);
    printf("Limite.................:");
    gotoxy(16, 16);
    printf("Total Saldo + Limite...:");
    gotoxy(2, 17);
    printf("---------------------------------------------------------------------------------------------------");
    gotoxy(16, 18);
    printf("1-Data Movimentacao....:");
    gotoxy(16, 19);
    printf("2-Tipo Movimentacao....:");
    gotoxy(16, 20);
    printf("3-Favorecido...........:");
    gotoxy(16, 21);
    printf("4-Valor Movimentacao...:");
    gotoxy(16, 22);
    printf("5-Novo Saldo...........:");
}