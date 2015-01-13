#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define N 3

struct pilha {
    int topo;
    float vet[N];
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
    }while(resp=='s');
    getch();
}

Pilha * pilha_cria(void){
    Pilha* p=(Pilha*) malloc(sizeof(Pilha));
    p->topo=0;
    return p;
}

bool pilha_vazia(Pilha* p){
    if(p!=NULL){
        if(!p->topo){
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
    else{
        return TRUE;
    }
}

void pilha_push(Pilha* p, float v){
    if(p->topo==N){
        printf("Overflow ! Pilha cheia.");
        getch();
        exit(1);
    }
    p->vet[p->topo]=v;
    p->topo++;
}

void pilha_pop(Pilha* p){
    if(pilha_vazia(p)){
        printf("Pilha Vazia!");
        exit(1);
    }
    p->vet[p->topo]=0;
    p->topo--;
}

void pilha_imprime(Pilha* p){
    int i;
    for(i=p->topo-1;i>=0;i--){ 
       printf("%.2f\n",p->vet[i]);
    }
}
