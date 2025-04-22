# 💰 Sistema de Controle Bancário
Projeto desenvolvido como trabalho acadêmico para a disciplina de Estrutura de Dados na Faculdade Cidade Verde (UNICV). O sistema simula operações bancárias básicas, utilizando listas encadeadas para manipulação dinâmica de dados em linguagem C.

## Tela Cadastro de Contas:
![image](https://github.com/user-attachments/assets/a8a51f7b-b947-4425-8eb2-aa5eb3746ed5)

## Tela de Cadastrar no Final:
![image](https://github.com/user-attachments/assets/280a35c8-6f56-4279-9445-debd0620d877)

## Tela de Movimentação Financeira:
![image](https://github.com/user-attachments/assets/de587606-da97-4269-b94b-537aaff45e4d)

## Cadastrar movimentação Bancaria:
![image](https://github.com/user-attachments/assets/1fd45bfc-51d6-493c-a194-4cc7dd56bfdd)

## transferencia entre contas Bancarias:
![image](https://github.com/user-attachments/assets/30051c12-b5a2-4f3b-93ae-78842f302837)

## Consultar Moviemntação Bancaria:
![image](https://github.com/user-attachments/assets/bac1bf50-fe13-40f4-8498-7772edfe45d4)

## 🧩 Funcionalidades

- 📄 **Cadastro de Contas Bancárias**
  - Inserção de contas no início, fim ou em uma posição específica da lista.
  - Alteração e remoção de contas.
  - Validação para códigos de conta duplicados.
 
    - 💼 **Consultas**
  - Consulta de contas individualmente ou em lista.
  - Ordenação por código da conta ou por ordem alfabética do nome do banco.
  - Exibição do total de saldos e limites das contas.

- 💳 **Movimentações Financeiras**
  - Débito e crédito em contas existentes.
  - Atualização automática do saldo após movimentações.
  - Interface para futura consulta de histórico de transações.

- 🔁 **Transferências entre Contas**
  - Estrutura pronta na interface, com a lógica em fase de implementação.

## 🛠️ Tecnologias Utilizadas

- Linguagem: **C**
- Estruturas: **Listas Encadeadas Simples e Duplamente Encadeadas**
- Interface: **Console (Windows), com gotoxy() para posicionamento do cursor**
- Ambiente: Windows, compilado com **GCC**

  ## ▶️ Instruções de Compilação e Execução

1. **Pré-requisitos**
   - Git Bash ou terminal equivalente
   - GCC (ex: via MinGW no Windows)


2. **Clonando o projeto**

   ```bash
   git clone https://github.com/seu-usuario/sistema-bancario.git
   cd sistema-bancario

3. **Compilando o sistema**

  ```bash
   gcc -g *.c -o ./output/bancario.exe
  ```
4. **Executando**

  ```bash
./output/bancario.exe

