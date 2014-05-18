/*
  funcao preenche vetor
*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void preencheVetor(int *vet, int tamanho){
    //preenche vetor
    int j,i,var = 0;
    for (i=0;i<tamanho;i++){

        do{
            vet[i] = rand() % 100 + 1;
            for(j=0; j<i;j++){
             
             if(vet[j]==vet[i]){
               var=1;
               break;
             }
             else var=0;
            } 
        }while(var);
      } 
}        

void quicksort (int v[], int primeiro, int ultimo){
  int i, j, m, aux;
  i=primeiro;
  j=ultimo;
  m=v[(i+j)/2];
  do
  {
     while (v[i] < m) 
       i++;
     while (v[j] > m) 
       j--;
     if (i<=j) {
       aux=v[i];
       v[i]=v[j];
       v[j]=aux;
       i++;
       j--;
     }     
   }while (i<=j);
   
   if (primeiro<j) 
     quicksort(v,primeiro,j);
   if (ultimo>i)
     quicksort(v,i,ultimo);
}

int main(){
    srand(time(NULL));
    /*especifica a rand a geracao dos numeros em funçao do tempo, nao prevendo a
    sim que sejam gerados MUITOS numeros iguais*/
    int tamanho = rand() % 20 + 1; //gera tamanho aleatorio de ate 20
    int vetor[tamanho];
    int denovo;
    int i;
    do{
      system("cls");
      printf(" Gerado numeros no vetor de %d elementos.\n",tamanho);
      preencheVetor(vetor,tamanho);
    
      printf("\n\n Vetor:\n");
      for(i=0;i<tamanho;i++){
        printf(" %d\n",vetor[i]);
      }
      printf("\n\n ORDENANDO VETOR PELO QUICKSORT !\n");
      quicksort(vetor,0,tamanho-1);
      printf("\nVetor ordenado: ");
      for(i=0;i<tamanho;i++){
        printf("\nposicao %d = %d",i, vetor[i]);
      }
      printf("\n\n Digite 1 para gerar outro vetor\n Digite 0 para sair\n Escolha: ");
      scanf("%d",&denovo);
    }while(denovo);
    system("pause");
    return 0;
}
