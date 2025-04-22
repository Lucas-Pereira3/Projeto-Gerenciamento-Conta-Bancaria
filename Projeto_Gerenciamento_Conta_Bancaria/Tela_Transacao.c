/*Nome: Jhonatan de souza
 Data:08/11/2024
 ObJ: Funçao principal
 Lucas da Silva RA: 145716-2023
 Jhonatan de souza RA: 156801-2023
  */

  #include "funcoes.h"

void Tela_Transacao(){


gotoxy(35, 4);
printf("TRANSFERENCIA ENTRE CONTAS BANCARIAS");
gotoxy(2, 9);
printf("-----------C O N T A  O R I G E M------------------+---------C O N T A  D E S T I N O--------------");
gotoxy(12, 10);
printf("Conta de origem:                         | Conta de destino:");
gotoxy(12, 11);
printf("Banco..........:                         | Banco...........:");
gotoxy(12, 12);
printf("Agencia........:                         | Agencia.........:");
gotoxy(12, 13);
printf("Numero da conta:                         | Numero da conta.:");
gotoxy(12, 14);
printf("Tipo da Conta..:                         | Tipo da Conta...:");
gotoxy(12, 15);
printf("Saldo..........:                         | Saldo...........:");
gotoxy(12, 16);
printf("Limite.........:                         | Limite..........:");
gotoxy(12, 17);
printf("Saldo + Limite.:                         | Saldo + Limite..:");
gotoxy(12, 18);
printf("Novo Saldo.....:                         | Novo Saldo......:");
gotoxy(2, 19);
printf("---------------------------------------------------+-----------------------------------------------");
gotoxy(27, 20);
printf("Valor a Ser Transferido:");
gotoxy(27, 21);
printf("Data Da Transferencia..:");

}
