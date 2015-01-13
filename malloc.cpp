#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v;
    v=(int*) malloc(40*sizeof(v)); // reserva 10* v ou seja 40 bytes
    printf("Espaco reservado: %d\n\n",v); // mostra qto de espaço da memoria foi reservado
    system("pause");
    return (0);
}
