# Máquina Virtual Baseada em Pilha – Etapa 1

## Objetivo
Implementação de um interpretador interativo (REPL – Read-Eval-Print Loop) em C, para uma máquina virtual que utiliza estrutura de pilha.

## Grupo
* ADRYELE PEREIRA DA SILVA
* CRISTIAN COSTA CRUZ
* DARLISON DE SOUSA SANTOS PIRES
* DAVID LUCAS SA CORDEIRO
* FABYO HUNTER COSTA SA
* FLAVIO ARAGAO TENORIO DE BRITTO
* JOAO GUILHERME OLIVEIRA MARQUES

## Conteúdo do Projeto
Este repositório contém o código-fonte para a Etapa 1 do projeto de Máquina Virtual Baseada em Pilha. Os arquivos principais são:
* `main.c`: Contém a função `main` e o loop REPL.
* `interpret.c`: Implementa a lógica do interpretador, processando comandos e manipulando a pilha.
* `interpret.h`: Arquivo de cabeçalho para as funções do interpretador.
* `stack.c`: Implementa as operações da estrutura de dados pilha (push, pop, etc.).
* `stack.h`: Arquivo de cabeçalho para as funções da pilha.

## Instruções de Compilação e Uso

### Pré-requisitos
* Um compilador C (como GCC).

### Compilação
Para compilar o projeto, navegue até o diretório raiz do repositório no terminal e execute o seguinte comando:

```bash
gcc main.c interpret.c stack.c -o repl_mvp -Wall -std=c99
