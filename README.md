# CSTOCK
Controle de estoque via terminal com padrão POSIX.

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

