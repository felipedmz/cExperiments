/*
  funcao de bubble sort contruido recursivamente
*/

#include <stdio.h>
#include <stdlib.h>

int bubble_rec(int busca, int vetor[],int tamanho){
    if (busca==vetor[tamanho])
       return 1;
    else if(tamanho==0)
       return 0;
    return bubble_rec(busca,vetor,tamanho-1);
}

int main(){
    int v[5],b;
    printf("Complete o vetor[5] com valores inteiros\n");
    for(int i=0;i<5;i++){
            printf("\ndigite o valor [%d]: ",i+1);
            scanf("%d",&v[i]);
    }
    printf("\nVetor completo !\n\n");
    printf("Digite o valor a ser buscado: ");
    scanf("%d",&b);
    if (bubble_rec(b,v,5)){
       printf("\nVALOR ENCONTRADO");          
    }
    else{
       printf("\nVALOR NAO ENCONTRADO");
    }
    printf("\n\n\n");
    system("pause");
    return 0;
}
