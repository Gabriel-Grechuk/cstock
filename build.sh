#!/bin/sh

command -v cmake >/dev/null 2>&1 || { echo "CMake não está instalado. Abortando compilação."; exit 1; }
command -v gcc >/dev/null 2>&1 || { echo "GCC não está instalado. Abortando compilação."; exit 1; }

build()
{
    echo "Building..."
    mkdir -p build
    cd build
    cmake ../src
    make
    cp cstock ../
    echo "Done."
}

clean()
{
    echo "Cleaning..."
    rm -r build
    rm -r cstock
    echo "Done."
}

install()
{
    echo "Not prepared yet"
}

uninstall()
{
    echo "Not prepared yet"
}


case $1 in 
    --build)    build ;;
    --clean)    clean ;;
    --install)  install ;;
    --uninstall) uninstall ;;
    *) build ;;
esac

