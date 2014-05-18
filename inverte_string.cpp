/* Programa que inverte string digitada pelo usuário */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
char original[30];
int tamanho,i,j;
i=0;
j=0;
fflush(stdin);
printf("Digite a palavra a ser invertida: ");
scanf("%s",&original);
tamanho=strlen(original);
j=tamanho-1;
char inversa[tamanho];
inversa[tamanho]='\0';
for(i=0;original[i]!='\0';i++){//para inverter
 inversa[j]=original[i];  
 if (j == 0) break;                      
 j-=1;                    
}

printf("\nA inversa: %s  original: %s \n\n",inversa,original);
system ("pause");
return 0;
}    
