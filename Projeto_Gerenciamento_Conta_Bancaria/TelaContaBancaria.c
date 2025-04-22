/*Nome: Jhonatan de souza
 Data:08/11/2024
 ObJ: Funçao principal
 Lucas da Silva RA: 145716-2023
 Jhonatan de souza RA: 156801-2023
  */

 #include "funcoes.h"

 // Funcao que exibe o formulario para dados da conta bancaria
void telaContaBancaria() {
    gotoxy(5, 7);
    printf("Codigo da Conta..: ");
    gotoxy(5, 9);
    printf("Banco............: ");
    gotoxy(5, 11);
    printf("Agencia..........: ");
    gotoxy(5, 13);
    printf("Numero da Conta..: ");
    gotoxy(5, 15);
    printf("Tipo de Conta....: ");
    gotoxy(5, 17);
    printf("Saldo............: ");
    gotoxy(5, 19);
    printf("Limite...........: ");
    gotoxy(5, 21);
    printf("Status...........: ");
}