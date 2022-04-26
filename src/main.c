#include <stdio.h>
#include "args.h"
#include "cstock.h"

int main(int argc, char *argv[])
{
    printf("cstock\n");
    return process_args(argc, argv);
    
    return 0;
}
