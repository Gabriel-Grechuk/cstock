# CSTOCK
O cstock é um programa criado com o objetivo de ser pequeno, rápido e versátil; rodando dentro de ambientes com suporte ao padrão POSIX, podendo ser ligado a pipelines de dados em um shell UNIX, executado standalone como um aplicativo GUI ou até mesmo enviando informações pela rede para outros programas em formato JSON através de API Rest.

Cstock deve ser capaz de:

-   Cadastrar produtos;
-   Excluir produtos;
-   Dar entrada de produtos;
-   Retirada de produtos;
-   Listar todos os produtos cadastrados;
-   Buscar e mostrar produto por nome;
-   Buscar e mostrar produto por código;

A base de dados pode ser um arquivo JSON, XML ou um banco de dados SQLITE. A localização pode ser passada por linha de comando, o conteúdo do arquivo de dados pode ser enviado para o cstock através de um stream, ou ele pode acessar a base de dados de algum outro cstock rodando na mesma rede. Caso não seja especificado, o programa vai procurar dentro da pasta padrão (_~/.local/cstock/database_)

## BUILD
Requerientos:
* CMake 3.0
* gcc

No momento, qualquer versão do C e do gcc conseguem compilar o cstock.
Basta rodar em um terminal:

    ./build.sh

ou

    ./build.sh --build

E pronto, está compilado na pasta "build".

### Clean

    ./build.sh --clean

Para limpar os arquivos de build.

### Install
Função não implementada. Não temos uma versão estável do programa e
e installar ele no ambiente do usuário pode ser perigoso.

Quando tivermos um sistema já funcional, o comando para instala-lo será

    ./build.sh --install

### Uninstall
Como o cstock ainda não pode ser instalado, não foi implementada uma ação para
desistala-lo, mas qunado a implementarmos será

    ./build.sh  --uninstall


## USO
### Listar todos os produtos

    cstock -l

### Buscar produto pelo nome

    cstock -s NOME

### Buscar item pelo código

    cstock -c CÓDIGO

### Cadastro de um novo produto

    cstock -C -n NOME -q QUANTIDADE

### Excluir um produto

Pelo nome

    cstock -E -n NOME

Pelo código

    cstock -E -c CÓDIGO

### Entrada de produto
Pelo nome

    cstock -A -n NOME -q QUANTIDADE
    
Pelo código

    cstock -A -c CÓDIGO -q QUANTIDADE

### Retirada de produto
Pelo nome

    cstock -R -n NOME -q QUANTIDADE

Pelo código

    cstock -R -c CODIGO -q QUANTIDADE


