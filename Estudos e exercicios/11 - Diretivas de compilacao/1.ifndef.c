#include <stdio.h>

#ifndef PI //se não definido, defina:
    #define PI 3.14567
#endif
//ifndef - diretiva de compilação

int main(){

    int value = 5; //variavel

    value = 467;

    printf("The value is %d\n", value);

    printf("PI values %f\n", (2 *PI));

    return 0;
}