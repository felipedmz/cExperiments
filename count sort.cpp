/*
  Otimização do count sort, para ordenação de números iguais no vetor
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ordena_por_contagem(int vet[], int ord[], int n){
    int i,j,p;
   //determinar a posição de cada elemento do vetor quando ordenado 
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
     /*especifica a rand a geracao dos numeros em funçao do tempo, nao prevendo a
     ssim que sejam gerados MUITOS numeros iguais*/
     int tamanho = rand() % 10 + 1; //gera tamanho aleatorio de ate 100
     int vetor[tamanho];
     int aux[tamanho];
     printf("Gerado numeros no vetor de %d elementos.\n",tamanho);
     
     //gera numeros aleatorios para o vetor
     for (int i=0;i<tamanho;i++){
         vetor[i]=rand()%10+1;
     }
     
     //inicializa vetor auxiliar
     for (int i=0;i<tamanho;i++){
         aux[i]=0;
     }
     ordena_por_contagem(vetor,aux,tamanho);   
     
     //imprime vetor
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
