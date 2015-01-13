#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct lista{
    int info;
    struct lista*prox;
}Lista;

Lista* lista_cria();
Lista* lista_insere(Lista* l, int i);
void lista_imprime(Lista* l);
int lista_vazia(lista* l);
Lista* lista_busca(Lista* l, int v);
Lista* lista_retira(Lista*l, int v);
void lista_libera(Lista* l);
Lista* montaLista(FILE *arq, Lista *l);
int achaTamanho(Lista* l);
void montaVetor(Lista* l, int *vetor);

int main(){
    Lista* l;
   
    char resp;
    do {
        l=lista_cria();
        system("cls");
        printf("LENDO CONTEUDO DO ARQUIVO: arquivo.txt");
        FILE* arq;
        arq=fopen("arquivo.txt","rt");
        if(arq==NULL){
            printf("\n\n--ERRO NA LEITURA DO AUQUIVO--");
            exit(1);
            system("pause");
        }
        l=montaLista(arq, l);
        printf("\n\nLista criada !");
        lista_imprime(l);
        int tamvetor=achaTamanho(l);
        printf("\n\nCRIANDO VETOR.......Tamanho da lista= %d\n", tamvetor);
        int vetor[tamvetor];
        montaVetor(l, vetor);
        printf("\n\nVetor criado!");
        for(int i=0;i<tamvetor;i++){
            printf("\n posicao %d = %d",i,vetor[i]);
        }
        printf("\n\nDeseja continuar??(s/n): ");
        scanf("%s", & resp);
    }while (resp == 's');
    system("pause");
    return 0;
}

Lista* montaLista(FILE *arq, Lista *l){
    Lista* p=l;;
    int num;
    while(fscanf(arq,"%d",&num)!=EOF){ 
        p=lista_insere(p,num);
    }
    return p;
}

int achaTamanho(Lista* l){
    Lista* p;
    int cont=0;
    for(p=l;p!=NULL;p=p->prox){
        cont++;
    }
    return cont;
}

void montaVetor(Lista* l, int *vetor){
    Lista* p;
    int pos=0;
    for(p=l;p!=NULL;p=p->prox){
        vetor[pos]=p->info;
        pos++;
    }
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
    printf("\nConteudo da lista:\n");
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
