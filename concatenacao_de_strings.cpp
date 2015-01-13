#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char st1[30], st2[30];
    int tamanho1,tamanho2,comprimento;
    int j=0;
    
    fflush(stdin);
    printf("Digite a primeira string: ");
    scanf("%s",&st1);
    printf("Digite a segunda string: ");
    scanf("%s",&st2);

    tamanho1=strlen(st1);
    tamanho2=strlen(st2);
    comprimento = tamanho1 + tamanho2;
    
    char concatenada[comprimento];
    for(int i=0;st1[i]!='\0';i++){
        concatenada[i]=st1[i];              
    }
    for(int i=tamanho1;i<=comprimento;i++){
        concatenada[i]=st2[j];                 
        j++;
    }
    
    printf("\nA String1: %s  String2: %s String concatenada: %s\n\n",st1,st2,concatenada);
    system ("pause");
    return 0;
}    
