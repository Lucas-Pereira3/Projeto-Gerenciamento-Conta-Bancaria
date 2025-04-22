/*Nome: Lucas Da Silva
 Data:24/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */

#include "funcoes.h"

// Funcao para receber a data do movimento (formato dd/mm/aaaa)
char* le_movimento_data() {
    static char data[11];
    gotoxy(41, 18);
    scanf("%s", data);
    return data;
}