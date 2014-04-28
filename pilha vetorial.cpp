#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define N 3 //constante do tamanho da pilha criado para facilitar os IFS

struct pilha {
       int topo;
       float vet[N]; //define a piha com o tamanho da constante
};

typedef struct pilha Pilha;
typedef enum {FALSE,TRUE} Bool;

Pilha* pilha_cria(void);
bool pilha_vazia(Pilha* p);
void pilha_push(Pilha* p, float v);
void pilha_pop(Pilha* p);
void pilha_imprime(Pilha* p);

int main(){
    
    Pilha* p=NULL;
    int op;
    char resp;
    float valor;
    
    do{
           system("cls");
           printf("==PILHAS VETORIAIS >> FELIPE==\n\n");
           printf("Escolha uma opcao:\n");
           printf("1 - Cria a pilha\n");
           printf("2 - Testa se a pilha esta vazia\n");
           printf("3 - Adiciona um elemento a pilha\n");
           printf("4 - Retira um elemento da pilha\n");
           printf("5 - Exibe a pilha\n");
           printf("6 - SAIR [X]\n\n");
           printf("Escolha: ");
           scanf("%d",&op);
           switch(op){
              case 1:
                   p=pilha_cria();
                   printf("Pilha criada no endereco %p",p);
                   break;
              case 2:
                   if(pilha_vazia(p)){
                     printf("A pilha esta VAZIA");
                   }
                   else{
                     printf("A pilha NAO ESTA VAZIA");
                   }
                   break;
              case 3:
                   printf("Digite um valor real:"); 
                   scanf("%f",&valor);
                   pilha_push(p,valor);
                   break;
              case 4:
                   pilha_pop(p);
                   break;
              case 5:
                   pilha_imprime(p);
                   break;
              case 6:
                   exit(1);
           }
           printf("\n\nDeseja continuar? (s/n) :");
           scanf("%s",&resp);
    }
    while(resp=='s');
    getch();
}

Pilha * pilha_cria(void){
      Pilha* p=(Pilha*) malloc(sizeof(Pilha)); //reserva o espaço para a pilha
      p->topo=0; //inicializa o topo
      return p;
}

bool pilha_vazia(Pilha* p){
     if(p!=NULL){ //se a pilha EH diferente de NULL ou seja SE EXISTE
        if(!p->topo){ //verifica se o topo NAO existe
          return TRUE; //se TOPO NAO EXISTE retorna PILHA VAZIA=TRUE
        }
        else{
          return FALSE;//se TOPO EXISTE retorna PILHA VAZIA= FALSE
        }
     }
     else{
        return TRUE;// se a pilha Eh IGUAL a NULL entao PILHA VAZIA = TRUE
     }
     
     /*Resumindo a função soh nao retornara TRUE , ou seja pilha vazia se P diferente de NULL 
     ou seja se a pilha existir, e se o topo existir */
}

void pilha_push(Pilha* p, float v){
     if(p->topo==N){
       printf("Overflow ! Pilha cheia.");
       getch();//espera digitação do user
       exit(1);//volta ao menu
     }
     p->vet[p->topo]=v; //coloca o valor na pilha na posição correspondente ao topo
     p->topo++; //incrementa o topo
}

void pilha_pop(Pilha* p){
     if(pilha_vazia(p)){ //verifica se a pilha esta vazia por meio da funçao pilha_vazia
       printf("Pilha Vazia!");
       exit(1); //se verdadeiro printa a msg e retorna ao menu
     }
     p->vet[p->topo]=0; //anula o elemento do topo
     p->topo--; //decrementa o topo
}

void pilha_imprime(Pilha* p){
     int i;
     for(i=p->topo-1;i>=0;i--){ 
       printf("%.2f\n",p->vet[i]);
     }
}
     /*começa o i abaixo do topo pois o topo nao contem valor, vai decrementando 
     ateh chegar em 0, ou seja, o inicoi da pilha*/


