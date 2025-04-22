/*Nome: Lucas Da Silva
 Data:08/11/2024
 ObJ: Funçao principal
 Jhonatan de souza RA: 156801-2023
 Lucas da Silva RA: 145716-2023
  */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>

 #ifndef FUNCOES_H
 #define FUNCOES_H

 // Define uma estrutura chamada 'Conta' para representar uma conta bancaria e 
typedef struct {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    int status;
} Reg_conta;

// Declara um tipo de ponteiro 'tipoapontador' para 'tipoitem'.
typedef struct tipoitem *tipoapontador_conta;

// Define uma estrutura chamada 'tipoitem' para os nós da lista encadeada.
typedef struct tipoitem {
    Reg_conta conteudo;
    tipoapontador_conta proximo;
} tipoitem;

// Define uma estrutura para uma lista encadeada que contem nos do tipo 'tipoitem'.
typedef struct {
    tipoapontador_conta primeiro;
    tipoapontador_conta ultimo;
} tipolista_conta;

 // Define uma estrutura chamada 'Movimentacao' para registros de transacaes.
typedef struct Movimentacao {
    int sequencial;
    int codigoConta; 
    char dt_Movimento[11]; 
    char tp_movimentacao[15];
    char ds_favorecido[50]; 
    float vl_movimento; 
    float vl_saldo;  
} Reg_movimentacao;

typedef struct tipoitem_movimentacao *tipoapontador_movimentacao;

typedef struct tipoitem_movimentacao {
    Reg_movimentacao conteudo;
    tipoapontador_movimentacao proximo;
    tipoapontador_movimentacao anterior; 
} tipoitem_movimentacao;

typedef struct {
    tipoapontador_movimentacao primeiro;
    tipoapontador_movimentacao ultimo;
} tipolista_movimentacao;

// Move o cursor para a posicao (x, y) na tela do console
void gotoxy(int x, int y);

// Funcao que desenha a tela inicial do sistema
void tela();

// Funcao que exibe o formulario para dados da conta bancaria
void telaContaBancaria();

// Funcao para pesquisar uma conta na lista de contas
tipoapontador_conta pesquisarConta(tipolista_conta *L, int codigo);

// Funcao que conta o numero total de contas na lista
int contador(tipolista_conta *L);

// Funcao para cadastrar uma conta no Final
void CadastrarContaFinal(tipolista_conta *L);

// Funcao para cadastrar no Inicio
void CadastrarContaInicio(tipolista_conta *L);

// Funcao para cadastrar em uma posicao
void CadastrarContaPosicao(tipolista_conta *L);

// Funcao para remover conta no final
void removerContaFinal(tipolista_conta *L);

//Funcao para remover conta no Inicio
void removerContaInicio(tipolista_conta *L);

// Funcao para remover conta em uma posicao
void removerContaPosicao(tipolista_conta *L);

// Funcao para alterar conta
void alterarConta(tipolista_conta *L);

// Funcao para consultar conta
void ConsultarContas(tipolista_conta *L);

// Funcao Consultar todas contas bancarias
void ConsultarTodasContaBancarias(tipolista_conta *L);

//Funcao Consultar contas por codigo
void ConsultarContaPorCodigo(tipolista_conta *L);

// Funcao tela consulta contas bancarias
void telaConsultaContas();

// Funcao para consultar contas de forma ordenadas por codigo
void OrdenarContasPorCodigo(tipolista_conta *L);

// Funcao para consultar contas de forma ordenadas por ordem alfabetica
void OrdenarContasPorAlfabeto(tipolista_conta *L);

// Funcao tela de transacao bancaria
void Tela_Transacao();

// Funcao tela cadastro de movimentacao
void TelaCadastroMovimentacao();

// Funcao tela de consulta movimentacao
void TelaConsultaMovimentacao();

// Funcao para receber a data do movimento (formato dd/mm/aaaa)
char* le_movimento_data();

// Funcao para receber o tipo de movimento (Debito ou Credito)
char* le_movimento_tipo();

// Funcao para receber o favorecido do movimento
char* le_movimento_favorecido();

// Funcao para receber o valor do movimento
float le_movimento_valor();

// Funcao para cadastrar movimentacao
void cadastroMovimentacao(tipolista_conta *L, tipolista_movimentacao *M);

// Funcao para fazer tranferencias entre contas bancarias
void transferirEntreContas(tipolista_conta *L, tipolista_movimentacao *M);

// Funcao para consultar transferencias e movimentacao
void consultarMovimentacao(tipolista_conta *L, tipolista_movimentacao *M);

// Funcao para salvar contas .DAT
void salvarContas(tipolista_conta *L);

// Funcao para carregar contas
void carregarContas(tipolista_conta *L);

// Funcao para salvar Movimentacao
void salvarMovimentacoes(tipolista_movimentacao *M);

// Funcao para carregar Movimentacao
void carregarMovimentacoes(tipolista_movimentacao *M);


#endif