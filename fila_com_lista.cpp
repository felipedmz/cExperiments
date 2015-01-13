#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct fila Fila;
typedef struct lista Lista;

Fila* fila_cria (void);
void fila_insere (Fila* f, float v);
float fila_retira (Fila*f);
int fila_vazia (Fila* f);
void fila_libera (Fila* f);
void fila_imprime (Fila* f);

struct lista {
    float info;
    struct lista* prox;
};
struct fila {
    Lista* ini;
    Lista* fim;
};

int main(){
    
    Fila* p = NULL;
    int op;
    float x;
    char resp;
    
    do {
        system("cls");
        printf("\t |--:: IMPLEMENTANDO FILA com LISTA ::--|\n\n");
        printf("\tDigite 1 para criar fila.\n");
        printf("\tDigite 2 para testar fila.\n");
        printf("\tDigite 3 para incrementar elementos na fila.\n");
        printf("\tDigite 4 para remover elementos na fila.\n");
        printf("\tDigite 5 para exibir a fila.\n");
        printf("\tDigite 6 para liberar espaco da fila.\n");
        printf("\tDigite 7 para sair.\n\n");
        printf("Escolha: ","\n");
     
        scanf("%d",& op);
        if( op !=1 && op!=2 && op!=3 && op!=4 && op!=5 && op!=6 && op!=7) {
            printf("\nOpcao invalida!\n");
        }
        else{ 
            switch (op) {
                case 1 :
                    p = fila_cria();
                    printf("Pilha criada no endereco %p! \n\n", p);
                    break;
                case 2 : 
                    if (fila_vazia(p))
                        printf("Pilha Vazia!");
                    else
                        printf("Pilha nao vazia!");
                    break;
                case 3 :
                    printf("Digite um valor real: ");
                    scanf("%f",&x);
                    fila_insere(p,x);
                    break;
                case 4 :
                    x = fila_retira(p);
                    break;
                case 5 :
                    fila_imprime(p);
                    break;
                case 6 :
                    fila_libera(p);
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

Fila* fila_cria (void) {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere (Fila* f, float v) {
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = v;
    n->prox = NULL;
    if (f->fim != NULL){
        f->fim->prox = n;
    }
    else{
        f->ini = n;
    }
    f->fim = n;
}

float fila_retira (Fila* f) {
    Lista* t;
    float v;
    if (fila_vazia(f)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini==NULL) {
        f->fim = NULL;
    }
    free(t);
    return v;
}

int fila_vazia (Fila* f) {
    return (f->ini == NULL);
}

void fila_libera (Fila* f) {
    Lista* q = f->ini;
    while(q != NULL) {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

void fila_imprime (Fila* f) {
    Lista* q;
    for (q = f->ini; q != NULL; q = q->prox) {
        printf("%.2f\n" , q->info);
    }
}
