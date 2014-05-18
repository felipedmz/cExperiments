#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//PROGRAMA:  gera uma abb balanceada a partir de um vetor ordenado

typedef struct arv
{
    int info;
    struct arv* esq;
    struct arv* dir;
}Arv;

//cria arvore vazia
Arv *abb_cria()
{
      return NULL;
}

//verifica se a arvore está vazia
int abb_vazia(Arv* a)
{
    return(a==NULL);
}    
      
//insere elemento
Arv  *abb_insere(Arv* a,int c)
{
     Arv *p,*q,*r;
     p=(Arv*)malloc(sizeof(Arv));
     p->info = c;
     p->esq = p->dir = NULL;
     
     if (abb_vazia(a))//primeiro elemento da árvore
         {
           a=p;
         }
     else
     {
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

//retira elemento
Arv* abb_retira(Arv *r, int v)
{
     if (r==NULL) return NULL;
     printf("\n%d",r->info);
     if(r->info > v) r->esq = abb_retira(r->esq, v);
     else if (r->info < v) r->dir = abb_retira(r->dir, v);
          else {
               //achou o elemento 
                if ( r->esq ==NULL && r->dir ==NULL) { // no sem filhos
                     free(r);
                     r=NULL;
                     } 
                else  if (r->esq ==NULL) { //filho a direita            
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
                                     while (f->dir != NULL)f=f->dir;
                                     r->info =f->info;
                                     f->info=v;
                                     r->esq=abb_retira(r->esq,v);
                                   }
                    }
                    return r;                           
}

//travessia em pre-ordem
void abb_imprime1(Arv* a)
{
     if(!abb_vazia(a)) 
     {
         printf("%d ", a->info); //visita a raiz, arvore esquerda e arvore direita
         abb_imprime1(a->esq);
         abb_imprime1(a->dir);
     }                
}

//travessia em ordem
void abb_imprime2(Arv* a)
{
     if(!abb_vazia(a)) 
     {
         abb_imprime2(a->esq); //visita a arvore esquerda, depois a raiz e depois a arvore direita
         printf("%d ", a->info);
         abb_imprime2(a->dir);
      }                
}

//travessia em pos-ordem
void abb_imprime3(Arv* a)
{
     if (!abb_vazia(a)) 
     {
         abb_imprime3(a->esq);//visita a arvore esquerda, a arvore direita e depois a raiz
         abb_imprime3(a->dir);
         printf("%d ", a->info);
      }                
}

//operação de busca
Arv* abb_busca(Arv *a, int v)
{
     if (abb_vazia(a)) return NULL;
     if(a->info > v) return abb_busca(a->esq,v);
     else 
        if (a->info < v) return abb_busca (a->dir, v);
     return a;
}    

//criação da abb a partir de um vetor ordenado 
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

int main()
{
  int i,t,num;
  Arv *a=abb_cria();
  int vet[]={1,2,3,4,5,6,7,8,9,10};
  t=10; //tamanho do vetor
  a=balanceia(vet,0,t-1,a);
   
  printf("\nTravessia em pre-ordem\n");
  abb_imprime1(a);
    
  printf("\n\nTravessia em ordem\n");
  abb_imprime2(a);
  
  printf("\n\nTravessia em pos-ordem\n");
  abb_imprime3(a);

  printf("\n\n");
  system("pause");
  return 0;
}                                                                                        
        
