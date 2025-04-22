/*Nome: Jhontan de souza.
 Data:09/11/2024.
 ObJ: criar uma função que pesquisa contas ja criadas no programa.
 Jhonatan de souza RA: 156801-2023.
 Lucas da Silva RA: 145716-2023.
*/

 #include "funcoes.h"

//função que pesquisa contas
tipoapontador_conta pesquisarConta(tipolista_conta *L, int codigo) {
    tipoitem* item = L->primeiro;

    while (item != NULL) {
        if (item->conteudo.codigo_conta == codigo) {
            return item; // Retorna o ponteiro para o item encontrado
        }
        item = item->proximo;
    }
    return NULL; // Retorna NULL se não encontrar
}