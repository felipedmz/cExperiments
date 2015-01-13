#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ordena_por_contagem(int vet[], int ord[], int n){
    int i,j,p;

    for(i=0;i<n;i++){
        p=0;
        for(j=0;j<n;j++)
            if (vet[i]>vet[j]) p++;
        ord[p]=vet[i];
    }
    for(i=0;i<n;i++){
        if(ord[i]==0)
            ord[i]=ord[i-1];
    }
} 

int main(){
    srand(time(NULL));
    int tamanho = rand() % 10 + 1;
    int vetor[tamanho];
    int aux[tamanho];
    printf("Gerado numeros no vetor de %d elementos.\n",tamanho);

    for (int i=0;i<tamanho;i++){
        vetor[i]=rand()%10+1;
    }
    for (int i=0;i<tamanho;i++){
        aux[i]=0;
    }
    ordena_por_contagem(vetor,aux,tamanho);   
    
    printf("\n\nVetor NAO Ordenado:\n");
    for(int i=0;i<tamanho;i++){
        printf("%d\n",vetor[i]);
    }
     
    printf("\n\nVetor Ordenado:\n");
    for(int i=0;i<tamanho;i++){
        printf("%d\n",aux[i]);
    }
    printf("\n\n");
     
    printf("\n\n");
    system("pause");
    return 0;
}
