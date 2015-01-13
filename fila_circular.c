#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define P(x) printf("%s", x)

typedef struct{
    int* vetFila;
    int comprimentoDoVetor;
    int tamanhoFila;
    int fim;
} Fila;

Fila* criaFila(int tamanho);
void insereFila(Fila* f, int v);
int removeFila(Fila* f);
void mostraFila(Fila* f);
int filaVazia(Fila* f);

int main(){
    Fila* f;
    int tam, op;
     
    P("Informe o tamanho da fila circular: ");
    scanf("%d", &tam);
     
    f = criaFila(tam);
     
    do{
        system("cls");
        P("Escolha uma das opcoes abaixo --\n");
        P("\t1. Inserir um elemento na fila circular;\n");
        P("\t2. Remover um elemento da fila circular;\n");
        P("\t3. Fila vazia ?\n");
        P("\t4. Mostrar a fila circular;\n");
        P("\t5. Sair.\n");
        P("Resposta escolhida: ");
        scanf("%d", &op);
          
        switch(op){
            case 1:{
                int valor;
                  
                P("Digite o valor a ser inserido na fila circular: ");
                scanf("%d", &valor);
                    
                insereFila(f, valor);
            }
            break;           
            case 2: {
                if(filaVazia(f))
                    P("Fila vazia.\n");
                else
                    printf("Valor removido: %d.\n", removeFila(f));
                    getch();
            }
            break;
            case 3: {
                if(filaVazia(f))
                    P("Fila vazia.\n");
                else
                    P("Fila nao esta vazia.\n");
                    getch();
            }
            break;
            case 4: mostraFila(f);
            break;
            case 5: exit(0);
            break;
            default : {
                P("Opcao invalida.\n");
                getch();
            }
            break;
        }
    }while(op != 5);
    getch();
    return 0;
}

Fila* criaFila(int tamanho){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->vetFila = (int*)malloc(tamanho * sizeof(int));
    f->inicio = 0;
    f->fim = -1;
    f->tamanhoFila = 0;
    f->comprimentoDoVetor = tamanho;
     
    return f;
}

void insereFila(Fila* f, int v){
    if(f->tamanhoFila < f->comprimentoDoVetor){
        if(f->fim == f->comprimentoDoVetor - 1){
            f->fim = 0;
            f->vetFila[f->fim] = v;
        }
        else
            f->vetFila[++(f->fim)] = v;
            f->tamanhoFila++;
        }
    else{
        P("Fila cheia!\n");
        getch();
    }
}

int removeFila(Fila* f){
    int removido;
     
    if(!filaVazia(f)){
        removido = f->vetFila[f->inicio]; 
        
        if(f->inicio == f->comprimentoDoVetor - 1)
            f->inicio = 0;
        else
            f->inicio++;
        f->tamanhoFila--;
    }
     
    return removido;
}

void mostraFila(Fila* f){
    int i, cont;
    if(!filaVazia(f)){
        i = f->inicio;
          
        for(cont = 0; cont < f->tamanhoFila; cont++){
            printf("%d - ", f->vetFila[i]);
            i = (i + 1) % f->comprimentoDoVetor;
        }          
    }
    else
        P("Fila vazia!");
    getch();
}

int filaVazia(Fila* f){
    return (f->tamanhoFila == 0);
}
