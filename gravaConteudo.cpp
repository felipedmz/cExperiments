/*
  funcao que grava conteudo do vetor num arquivo preenche vetor
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

void gravaConteudo(int *v, int tamanho){
     FILE *fp;
     fp=fopen("arquivo.txt","wt");
     if(fp==NULL){
        printf("\n\n ERRO NA ABERTURA DO ARQUIVO ");
        exit(1);
     }
     for(int i=0;i<tamanho;i++)
        fprintf(fp,"%d\n",v[i]);
     printf("\n\n --CONTEUDO GRAVA NO ARQUIVO: \"arquivo.txt\"--");
     fclose(fp);
}

int main(){
    srand(time(NULL));
    /*especifica a rand a geracao dos numeros em funçao do tempo, nao prevendo a
    sim que sejam gerados MUITOS numeros iguais*/
    int tamanho = rand() % 20 + 1; //gera tamanho aleatorio de ate 20
    int vetor[tamanho];
    int denovo;
    do{
      system("cls");
      printf(" Gerado numeros no vetor de %d elementos.\n",tamanho);
      preencheVetor(vetor,tamanho);
    
      printf("\n\n Vetor:\n");
      for(int i=0;i<tamanho;i++){
        printf(" %d\n",vetor[i]);
      }
      gravaConteudo(vetor,tamanho);
      printf("\n\n Digite 1 para gerar outro vetor\n Digite 0 para sair\n Escolha: ");
      scanf("%d",&denovo);
    }while(denovo);
    system("pause");
    return 0;
}
