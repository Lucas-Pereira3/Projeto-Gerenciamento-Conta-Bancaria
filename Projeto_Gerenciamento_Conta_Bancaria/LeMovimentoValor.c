/*Nome: Lucas Da Silva
 Data:24/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */

#include "funcoes.h"

// Funcao para receber o valor do movimento
float le_movimento_valor() {
    float valor;
    gotoxy(41, 21);
    scanf("%f", &valor);
    return valor;
}