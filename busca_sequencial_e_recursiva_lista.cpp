#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct lista{
    int info;
    struct lista*prox;
} Lista;

Lista* lista_cria();
Lista* lista_insere(Lista* l, int i);
void lista_imprime(Lista* l);
int lista_vazia(lista* l);
Lista* lista_busca(Lista* l, int v);
Lista* lista_retira(Lista*l, int v);
void lista_libera(Lista* l);
int busca_seq_lista_rec(Lista* p, int busca);

int main(){
    Lista* l;
    l=lista_cria();
    int op;
    int x;
    char resp;
    int num= rand()%30+1;
    do {
        system("cls");
        srand(time(NULL));
        printf("Gerando elementos da lista: \n");
        for(int i=0;i<num;i++)
            l=lista_insere(l,(rand()%100+1));
        lista_imprime(l); 
        printf("\n Digite o elemento para busca: ");
        scanf("%d",&x);
        if(busca_seq_lista_rec(l,x)){
            printf(" VALOR ENCONTRADO !\n");
        }
        else{
            printf(" VALOR NAO ENCONTRADO !\n");         
        }
        printf("\nDeseja continuar??(s/n): \n");
        scanf("%s", & resp);
    }while (resp == 's');
    system("pause");
    return 0;
}

Lista* lista_cria(void){
    return NULL;       
}

Lista* lista_insere(Lista* l, int i){
    Lista* novo= (Lista*) malloc(sizeof(Lista));
    novo->info=i;
    novo->prox=l;
    return novo;
}

void lista_imprime(Lista* l){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox)
       printf(" info = %d\n", p->info);
}

int lista_vazia(lista* l){
    return l==NULL;
}

Lista* lista_busca(Lista* l, int v){
    Lista* p;
    for(p=l;p!=NULL;p=p->prox){
        if(p->info=v)
            return p;
    }
    return NULL;
}

Lista* lista_retira(Lista*l, int v){
    Lista* ant=NULL;
    Lista* p=l;
   
    while(p!=NULL && p->info!=v){
        ant=p;
        p=p->prox;
    }
   
    if(p==NULL)
        return l;
      
    if(ant==NULL){
        l=p->prox;
    }
    else{
        ant->prox=p->prox;
    }
   
    free(p);
    return l;
}

void lista_libera(Lista* l){
    Lista* p=l;
    while(p!=NULL){
        Lista* t=p->prox;
        free(p);
        p=t;
    }
}

int busca_seq_lista_rec(Lista* p, int busca){
    if (busca==p->info)
        return 1;
    if (p->prox==NULL)
        return 0;
    return busca_seq_lista_rec(p=p->prox,busca);
}
