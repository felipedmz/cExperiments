#include <stdlib.h>
#include <stdio.h>
#include<conio.h>

typedef struct pilha Pilha;

Pilha* pilha_cria (void);
void pilha_push (Pilha* p, float v);
int pilha_vazia (Pilha* p);

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
    do
    {
        system("cls");
        printf("\t <--:: IMPLEMENTANDO PILHAS ::--> ==> FATEC <==\n\n");
        printf("\tDigite 1 para criar pilha.\n");
        printf("\tDigite 2 para testar pilha.\n");
        printf("\tDigite 3 para incrementar elementos na pilha.\n\n");
     
        scanf("%d",& op);
        switch (op) {
            case 1 :{
                p = pilha_cria();
                printf("Pilha criada no endereco %p!\n\n", p);
                break;
            }
            case 2 :{ 
                if (pilha_vazia(p))
                    printf("Pilha Vazia!");
                else
                    printf("Pilha nao esta vazia!");
                break;
            }
            case 3 :{
                printf("Digite um valor real: ");
                scanf("%f",&x);
                pilha_push(p,x);
                break;
            }
            case 5 :{
                exit(1);
            }
        }     
        printf("\nDeseja continuar?(s/n)\n\n");
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

void pilha_push(Pilha* p, float v)
{
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->prox = p->prim;
    p->prim = n;
}
