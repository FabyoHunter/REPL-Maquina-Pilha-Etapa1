# REPL-Maquina-Pilha - Etapa 2

**Integrantes do Grupo:**
* ADRYELE PEREIRA DA SILVA
* CRISTIAN CRUZ
* DARLISON DE SOUSA SANTOS PIRES
* DAVID LUCAS SA CORDEIRO
* FABYO HUNTER COSTA SA
* FLAVIO ARAGAO TENORIO DE BRITTO
* JOAO GUILHERME OLIVEIRA MARQUES

## Objetivo

Implementar um interpretador REPL (Read-Eval-Print Loop) para uma máquina virtual baseada em pilha em C. Esta segunda etapa foca na adição de suporte a variáveis nomeadas e operações entre elas.

## Funcionalidades da Etapa 1 (Base)

* **`push <valor>`**: Empilha um número inteiro na pilha.
* **`add`**: Desempilha dois valores, soma, e empilha o resultado.
* **`sub`**: Desempilha dois valores, subtrai o segundo do primeiro, e empilha o resultado.
* **`mul`**: Desempilha dois valores, multiplica, e empilha o resultado.
* **`div`**: Desempilha dois valores, divide o primeiro pelo segundo, e empilha o resultado (divisão inteira).
* **`print`**: Desempilha um valor e imprime no console.
* **`debug`**: Imprime o conteúdo atual da pilha.
* **`exit`**: Comando para sair do REPL.

## Funcionalidades da Etapa 2: Suporte a Variáveis

Nesta etapa, o interpretador foi expandido para incluir suporte a variáveis nomeadas, permitindo o armazenamento e a recuperação de valores através de uma lista encadeada.

### Novos Comandos / Comportamento Modificado:

* **`push <valor | nome_variável>`**:
    * Se o argumento for um número inteiro, ele é empilhado normalmente.
    * Se o argumento for o nome de uma variável existente, seu valor é buscado na memória de variáveis e empilhado.
    * **Comportamento de Erro**: Caso a variável não seja encontrada, uma mensagem de erro "Erro: Variavel '<nome>' nao encontrada." é exibida e a operação de empilhar não é realizada.

* **`pop <nome_variável>`**:
    * Desempilha um valor do topo da pilha.
    * Se a variável com o `<nome_variável>` já existir na memória, seu valor é atualizado com o valor desempilhado.
    * Se a variável não existir, uma nova variável com o nome e o valor desempilhado é criada na memória de variáveis.

* **`debug` (melhorado)**: Agora também exibe o conteúdo da memória de variáveis, além da pilha.

### Exemplo de Interação:

A seguir, um exemplo de sessão no REPL demonstrando o uso das novas funcionalidades de variáveis:
```
push 42
push 5
add
pop a
push a
push 8
sub
pop a
push 56
push 8
add
pop b
push a
push b
add
push 6
add
print
109
```
Para verificar o estado interno da MV:

```  
debug
--- Conteudo da Pilha ---
(Pilha pode estar vazia ou conter o Último resultado)
-------------------------- <-- Adicione essa linha para fechar o "Conteúdo da Pilha"
--- Variaveis ---
b = 64
a = 39
--------------------------
``` 

### Como Compilar e Executar

1.  **Navegação**: Abra o terminal/prompt de comando e navegue até o diretório `ETAPA 2` do projeto (onde os arquivos `main.c`, `interpret.c`, `stack.c`, `list.c` e seus respectivos `.h` estão localizados).
    * Exemplo no Windows CMD: `cd C:\Users\SeuUsuario\CaminhoDoProjeto\REPL-Maquina-Pilha-Etapa1-main\ETAPA 2`

2.  **Compilação**: Compile o código-fonte usando o compilador GCC:
    ```bash
    gcc -Wall -o mv main.c interpret.c stack.c list.c
    ```

3.  **Execução**: Execute a Máquina Virtual digitando o nome do executável:
    ```bash
    mv
    ```
    O REPL será iniciado e você verá o prompt `> `.
