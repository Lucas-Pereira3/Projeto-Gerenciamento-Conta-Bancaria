/*Nome: Jhontan de souza.
 Data:24/11/2024.
 ObJ: criar uma função que conta e mostra a quantidade de contas ja cadastradas.
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"

// Funcao para receber o favorecido do movimento
char* le_movimento_favorecido() {
    static char favorecido[50];
    gotoxy(41, 20);
    scanf(" %s", favorecido);
    return favorecido;
}