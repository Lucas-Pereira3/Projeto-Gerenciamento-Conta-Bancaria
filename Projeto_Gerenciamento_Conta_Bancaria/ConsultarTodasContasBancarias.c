/*Nome: Lucas Da Silva
 Data:18/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */

 #include "funcoes.h"

 // Funcao para consultar todas as contas
 void ConsultarTodasContaBancarias(tipolista_conta *L) {


    // Verifica se a lista de contas esta vazia
    if (L->primeiro == NULL) {
        gotoxy(7, 26);
        printf("Lista esta vazia. Nenhuma conta para consultar.");
        getch();
        return;
    }
    // Ponteiro para percorrer a lista de contas
    tipoitem* item = L->primeiro;

    while (item != NULL) {
    tela();
    telaContaBancaria();
    gotoxy(39, 4);
    printf("CONSULTA DE CONTAS ");
    gotoxy(24, 7);
    printf("%d", item->conteudo.codigo_conta);
    gotoxy(24, 9);
    printf("%s", item->conteudo.banco);
    gotoxy(24, 11);
    printf("%s", item->conteudo.agencia);
    gotoxy(24, 13);
    printf("%s", item->conteudo.numero_conta);
    gotoxy(24, 15);
    printf("%s", item->conteudo.tipo_conta);
    // Verifica o tipo de conta e exibe a descricao correta
    if (item->conteudo.tipo_conta[0] == '1'){
    gotoxy(24, 15);
    printf("1-Corrente");
    } else if (item->conteudo.tipo_conta[0] == '2'){
    gotoxy(24, 15);
    printf("2-Poupanca");
    } else if (item->conteudo.tipo_conta[0] == '3'){
    gotoxy(24, 15);
    printf("3-Cartao credito");
    } 
    gotoxy(24, 17);
    printf("%.2lf", item->conteudo.vl_saldo);
    gotoxy(24, 19);
    printf("%.2lf", item->conteudo.vl_limite);

     item->conteudo.status = 1;

    gotoxy(24, 21);  
    printf("%d", item->conteudo.status);
    
    // Solicita ao usuario que pressione uma tecla para continuar para a proxima conta
    gotoxy(7, 26);
    printf("Pressione uma tecla para continuar...");
    getch();
    item = item->proximo;
    }
  
}