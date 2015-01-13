#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define N 3

typedef struct pilha Pilha;
typedef enum{FALSE, TRUE} Bool;

Pilha* pilha_cria(void);
void pilha_push(Pilha* p, float v);
float pilha_pop(Pilha* p);
bool pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);
void pilha_imprime(Pilha* p);

struct pilha{
    int n;
    float vet[N];
};

int main() {
    Pilha* p=NULL;
    int op;
    float x;
    char resp;
    
    do{
        system("cls");
        printf("\t --Implementando de Pilha Sequencial--\n\n");
        printf("\t 1 - Para criar a pilha.\n");
        printf("\t 2 - Para incrementar elementos na pilha.\n");
        printf("\t 3 - Para remover elementos da pilha.\n");
        printf("\t 4 - Para testar a pilha.\n");
        printf("\t 5 - Para exibir a pilha.\n");
        printf("\t 6 - Para sair.\n\n");

        scanf("%d",&op);
        switch (op) {
            case 1:
                p=pilha_cria();
                printf("Pilha criada no endereço %p!",p);
                break;
            case 2:
                printf("Digite um valor real:");
                scanf("%f",&x);
                pilha_push(p,x);
                break;
            case 3:
                x=pilha_pop(p);
                break;
            case 4:{
                if(pilha_vazia(p))
                    printf("Pilha esta vazia ou nao existe!");
                else
                    printf("Pilha nao esta vazia!");
                }
                break;
            case 5:
                pilha_imprime(p);
                break;
            case 6:
                exit(1);
        }
        printf("\nQuer continuar? (s/n)\n\n");
        scanf("%s",&resp);
    }while (resp=='s');
    getch();
}     

Pilha* pilha_cria (void){
    Pilha* p=(Pilha*) malloc(sizeof(Pilha));
    p->n=0;
    return p;
}

void pilha_push(Pilha* p, float v){
    if (p->n==N){
        printf("Overflow na pilha !!!\n");
        getch();
        exit(1);
    }
    p->vet[p->n]=v ;
    p->n++;
}

float pilha_pop(Pilha* p){
    if (pilha_vazia(p)){
        printf("Pilha Vazia\n");
        exit(1);
    }
    p->vet[p->n]=0;
    p->n--;
}

bool pilha_vazia(Pilha* p){
    if (p!=NULL){
        if(!p->n){
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

void pilha_imprime(Pilha* p){
    int i;
    for(i=p->n-1;i>=0;i--){
        printf("%f\n",p->vet[i]);
    }
}
