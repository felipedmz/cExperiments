//Programa pra remover os espaços da string

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


void RetiraBrancos(char* c);

int main(){
    
    char string[30];
    
    printf ("Digite uma sentença(maximo 30 letras): ");
    fflush(stdin);
    gets(string);
    printf("\n\n");
    printf ("String digitada: %s\n\n", string);
    RetiraBrancos(string);
    
    getch();
    return 0;
}

void RetiraBrancos(char* c){
     int i = 0, j = 0;
     char* final = (char*)malloc(sizeof(c));
     
     while (j < strlen(c)) {
         if (c[i] != ' ') {
            final[j] = c[i];
            j++;
         }
         i++;    
     }

     printf("\nA String sem espaços: %s", final);
}
    
