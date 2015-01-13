#include <stdlib.h>
#include <stdio.h>
#include<conio.h>

typedef struct pilha Pilha;

Pilha* pilha_cria (void);
void pilha_push (Pilha* p, float v);
float pilha_pop (Pilha* p);
int pilha_vazia (Pilha* p);
void pilha_libera (Pilha* p);
void pilha_imprime (Pilha* p);

struct lista{
    float info;
    struct lista* prox;
};
typedef struct lista Lista;

struct pilha{
    Lista* prim;
};

int main(){
    
    Pilha* p = NULL;
    int op,teste;
    float x;
    char resp;
    
    do {
        system("cls");
        printf("\t |--:: IMPLEMENTANDO PILHA com LISTA ENCADEADA ::--|\n\n");
        printf("\tDigite 1 para criar pilha.\n");
        printf("\tDigite 2 para testar pilha.\n");
        printf("\tDigite 3 para incrementar elementos na pilha.\n");
        printf("\tDigite 4 para remover elementos na pilha.\n");
        printf("\tDigite 5 para exibir a pilha.\n");
        printf("\tDigite 6 para liberar espaco da pilha.\n");
        printf("\tDigite 7 para sair.\n\n");
        printf("Escolha: ","\n");
     
        scanf("%d",& op);
        if( op !=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 && op!=7) {
            printf("\nOpcao invalida!\n");
        }
        else{ 
            switch (op) {
                case 1 :
                    p = pilha_cria();
                    printf("Pilha criada no endereco %p! \n\n", p);
                    break;
                case 2 : 
                    if (pilha_vazia(p))
                        printf("Pilha Vazia!");
                    else
                        printf("Pilha nao vazia!");
                    break;
                case 3 :
                    printf("Digite um valor real: ");
                    scanf("%f",&x);
                    pilha_push(p,x);
                    break;
                case 4 :
                    x = pilha_pop(p);
                    break;
                case 5 :
                   pilha_imprime(p);
                    break;
                case 6 :
                   pilha_libera(p);
                   printf("\nTudo Liberado!!");
                    break;
                case 7 :
                    exit(1);
            }     
        }   
        printf("\nDeseja continuar??(s/n): ","\n");
        scanf("%s", & resp);
    }while (resp == 's');
    getch();
    return 0;
}

Pilha* pilha_cria (void) {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

int pilha_vazia (Pilha* p) {
    return (p->prim==NULL);
}

void pilha_push(Pilha* p, float v) {
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}

float pilha_pop (Pilha* p) { 
    Lista* t;
    float v;
    if (pilha_vazia(p)) {
        printf("Pilha Vazia.\n");
        exit(1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    return v;
}

void pilha_imprime (Pilha* p) {
    Lista* q;
    for (q = p->prim; q!=NULL; q=q->prox){
        printf("%.3f\n", q->info);
    }
}

void pilha_libera (Pilha* p) {
    Lista* q = p->prim;
    while (q != NULL) {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}
