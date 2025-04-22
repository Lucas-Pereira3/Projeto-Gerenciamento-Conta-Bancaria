/*Nome: Jhontan de souza.
 Data:24/11/2024.
 ObJ: criar uma função que conta e mostra a quantidade de contas ja cadastradas.
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"

char* le_movimento_tipo() {
    static char tipo[15]; // Buffer para armazenar o tipo de movimentação
    int opcaoTipo;

    do {
        gotoxy(7, 26);
        printf("Escolha o tipo de movimentacao: (1-Debito / 2-Credito)");
        gotoxy(41, 19);
        scanf("%d", &opcaoTipo);
        

        // Define o tipo de movimentacao com base na opcao escolhida
        if (opcaoTipo == 1) {
            strcpy(tipo, "Debito");
            gotoxy(41, 19);
            printf("Debito       "); // Espacos extras para limpar residuo
        } else if (opcaoTipo == 2) {
            strcpy(tipo, "Credito");
            gotoxy(41, 19);
            printf("Credito      ");
        } else {
            gotoxy(7, 26);
            printf("Opcao invalida! Tente novamente.");
            getch(); // Aguarda o usuario antes de limpar a mensagem
        }
    } while (opcaoTipo != 1 && opcaoTipo != 2); // Continua ate que uma opcao valida seja selecionada

    return tipo; // Retorna o tipo escolhido
}
