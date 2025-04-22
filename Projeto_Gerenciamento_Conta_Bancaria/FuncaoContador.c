/*Nome: Jhontan de souza.
 Data:09/11/2024.
 ObJ: criar uma função que conta e mostra a quantidade de contas ja cadastradas.
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"
 

 //função que indica e adiciona contas bancarias

 int contador(tipolista_conta *L) {
    int count = 0;
    tipoapontador_conta item = L->primeiro;

    while (item != NULL) {
        count++;
        item = item->proximo;
    }
    return count; // Retorna a contagem de contas
}