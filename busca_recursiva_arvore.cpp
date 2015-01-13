#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct arv
{
    int info;
    struct arv* esq;
    struct arv* dir;
} Arv;

Arv *abb_cria()
{
    return NULL;
}

int abb_vazia(Arv* a)
{
    return(a==NULL);
}    
      
Arv *abb_insere(Arv* a,int c)
{
    Arv *p,*q,*r;
    p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = p->dir = NULL;
     
    if (abb_vazia(a)){
        a=p;
    }
    else{
        q=a;
        while(q!=NULL)
        {
            r=q;
            if(c < q->info)
                q=q->esq;
            else
                q=q->dir;
        }
        if(c < r->info)
            r->esq=p;
        else
            r->dir=p;
    }
    return a;
}

Arv* abb_retira(Arv *r, int v)
{
    if (r==NULL) return NULL;
    printf("\n%d",r->info);
    if(r->info > v)
        r->esq = abb_retira(r->esq, v);
    else if (r->info < v)
        r->dir = abb_retira(r->dir, v);
    else {
        if (r->esq ==NULL && r->dir ==NULL) { // no sem filhos
            free(r);
            r=NULL;
        } 
        else if (r->esq ==NULL) { //filho a direita            
            Arv *t = r;
            r=r->dir;
            free(t);
        }
        else if( r->dir ==NULL) { //filho a esquerda
            Arv *t=r;
            r=r->esq;
            free(t);
        }
        else { //tem 2 filhos     
            Arv *f=r->esq;
            while (f->dir != NULL) f=f->dir;
            r->info =f->info;
            f->info=v;
            r->esq=abb_retira(r->esq,v);
        }
    }
    return r;                           
}

void abb_imprime1(Arv* a)
{
    if(!abb_vazia(a)){
        printf("%d ", a->info);
        abb_imprime1(a->esq);
        abb_imprime1(a->dir);
    }
}

void abb_imprime2(Arv* a)
{
    if(!abb_vazia(a)){
        abb_imprime2(a->esq);
        printf("%d ", a->info);
        abb_imprime2(a->dir);
    }
}

void abb_imprime3(Arv* a)
{
    if (!abb_vazia(a)){
        abb_imprime3(a->esq);
        abb_imprime3(a->dir);
        printf("%d ", a->info);
    }                
}

Arv* balanceia (int v[], int primeiro, int ultimo, Arv *a)
{
    int i, j, m, aux;
    i=primeiro;
    j=ultimo;
    m=(i+j)/2;
    a=abb_insere(a,v[m]);
    printf("%d - inserido\n");
    if (primeiro<m) 
        a=balanceia(v,primeiro,m-1, a);
    if (ultimo>m)
        a=balanceia(v,m+1,ultimo, a);
    return a;    
}

Arv* abb_busca(Arv *a, int v)
{
    if (abb_vazia(a)) return NULL;
    if (a->info > v) return abb_busca(a->esq,v);
    else 
        if (a->info < v) return abb_busca (a->dir, v);
    return a;
}    

int buscaArvore(Arv *a, int v){
    if (abb_vazia(a))
        return 0;
    if(a->info > v) 
        return buscaArvore(a->esq,v);
    else 
        if (a->info < v) 
            return buscaArvore (a->dir, v);
    return 1;
}

int main()
{
    int i,t,num;
    Arv *a=abb_cria();
    int vet[]={1,2,3,4,5,6,7,8,9,10};
    t=10;
    a=balanceia(vet,0,t-1,a);
  
    printf("\n\nDigite um valor a ser buscado: ");
    int valor;
    scanf("%d",&valor);
  
    if(buscaArvore(a, valor))
        printf("VALOR ENCONTRADO !");
    else
        printf("VALOR NAO ENCONTRADO !");
  
    printf("\n\n");
    system("pause");
    return 0;
}