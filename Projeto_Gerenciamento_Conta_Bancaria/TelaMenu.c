/*Nome: Jhonatan de souza
 Data:08/11/2024
 ObJ: Funçao principal
 Lucas da Silva RA: 145716-2023
 Jhonatan de souza RA: 156801-2023
  */

 #include "funcoes.h"

// Funcao que desenha a tela inicial do sistema
void tela() {
    system("cls");
    system("color 0B");
    for (int linha = 1; linha < 29; linha++) {
        gotoxy(1, linha);
        printf("|");
        gotoxy(101, linha);
        printf("|");
    }
    gotoxy(1, 1);
    printf("+---------------------------------------------------------------------------------------------------+");
    gotoxy(1, 5);
    printf("+---------------------------------------------------------------------------------------------------+");
    gotoxy(1, 25);
    printf("+---------------------------------------------------------------------------------------------------+");
    gotoxy(1, 29);
    printf("+---------------------------------------------------------------------------------------------------+");
    gotoxy(2, 2);
    printf("UNICV");
    gotoxy(83, 2);
    printf("Estrutura de Dados");
    gotoxy(2, 3);
    printf("SISTEMA CONTROLE BANCARIO");
    gotoxy(86, 3);
    printf("Aluno: Lucas P.");
    gotoxy(86, 4);
    printf("Aluno: Jhonatan");
    gotoxy(2, 26);
    printf("MSG:");
}