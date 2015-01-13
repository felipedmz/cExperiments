#include<stdio.h>
#include<stdlib.h>

int soma_rec(int a, int b){
    int resultado=0;
    if(a==0)
        return 0;
    if(a==b)
        return resultado=a+b;
    return resultado=a+soma_rec(a-1,b);
}

int main(){
    int A,B,TOTAL;
    printf("Digite o intervalo dos valores\n");
    printf("De A = ");
    scanf("%d",&A);
    printf(" ate B= ");
    scanf("%d",&A);
    printf("\nINTERVALO COMPUTADO");
    TOTAL=soma_rec(A,B);
    printf("\n\nA soma de todos os numeros nesse intervalo e: %d\n\n", TOTAL);
    system("pause");
    return 0;
}
