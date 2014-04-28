/*
  Gerar um vetor c/ um tamnaho aleatorio (max 20) com numeros 
  aleatorios sem repeticao .
  Ordenar este vetor usando algum algoritmo de ordenacao (qlqr um)
  Depois pesquisar repetidamente número neste vetor usando busca binaria 
  e busca sequencial otimizada
*/



#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int v[], int n) { 
  int i, j, chave; 
  for(j=1; j<n; j++) {
       chave = v[j];
       i = j-1; 
       while(i >= 0 && v[i] > chave){ 
               v[i+1] = v[i];
               i--; 
       } 
        v[i+1] = chave; 
     }
 } 

int pesq_seq_otimizada(int busca, int *vetor,int tamanho){
    if (busca==vetor[tamanho])
       return 1;
    if(vetor[tamanho-1]<busca)
       return 0;
    return pesq_seq_otimizada(busca,vetor,tamanho-1);
}

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

int busca_bin(int busca, int *vetor, int tamanho){
     int comeco=0, meio=0;
     int final=tamanho; 
     int acha=0;
     while((comeco<=final) && (acha==0)){
        int meio=(comeco+final)/2;
        if(busca==vetor[meio]){
          acha=1;
        }  
        else{
          if (busca<vetor[meio]){
             final=meio-1;
          }
          else{
             comeco=meio+1;
          }
        }
     }
     return acha;
}

int main(){
    srand(time(NULL));
    /*especifica a rand a geracao dos numeros em funçao do tempo, nao prevendo a
    sim que sejam gerados MUITOS numeros iguais*/
    int tamanho = rand() % 20 + 1; //gera tamanho aleatorio de ate 20
    int vetor[tamanho];
    printf(" Gerado numeros no vetor de %d elementos.\n",tamanho);

    preencheVetor(vetor,tamanho);
    insertionSort(vetor,tamanho);
    
    printf("\n\n Vetor Ordenado:\n");
    for(int i=0;i<tamanho;i++){
        printf(" %d\n",vetor[i]);
    }
    
    int num,op,denovo=0;
    do{
      printf("\n\n Digite um elemento para busca: ");
      scanf("%d",&num);
      printf(" Tipo da busca:\n\t1- Busca Sequencial Otimizada\n\t2- Busca Binaria\n\n Selecione a opcao: ");
      scanf("%d",&op);
      switch(op){
                 case 1:
                      if(pesq_seq_otimizada(num,vetor,tamanho)){
                         printf(" VALOR ENCONTRADO\n\n");
                      }
                      else{
                         printf(" VALOR NAO ENCONTRADO\n\n");
                      }
                      break;
                 case 2:
                      if(busca_bin(num,vetor,tamanho)){
                         printf(" VALOR ENCONTRADO\n\n");
                      }
                      else{
                         printf(" VALOR NAO ENCONTRADO\n\n");
                      }
                      break;
       }
       printf(" Digite 1 para um nova busca\n Digite 0 para sair\n Escolha: ");
       scanf("%d",&denovo);
    }while(denovo);
    system("pause");
    return 0;
}
