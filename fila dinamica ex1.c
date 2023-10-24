#include <stdio.h>
#include <stdlib.h>

typedef struct pilhao{

    int valor;

    struct pilhao *anterior;

}pilhao;

typedef struct toppilha
{
    pilhao *topo;
}toppilha;

typedef struct Tfila{
    int dado;
    struct Tfila *prox;
}Tfila;


typedef struct fila{
    Tfila *inicio;
    Tfila *fim;
}fila;

void criarPilha(toppilha *p){

    p->topo = NULL;

}

int pilhaVazia(toppilha *p){

    if(p->topo == NULL)
        return 1;
    else
        return 0;

}

void empilharElemento(toppilha *p, int valor){

    pilhao *novo = malloc(sizeof(pilhao));

    novo->valor = valor;
    novo->anterior = p->topo;

    p->topo = novo;

    novo=NULL;

    free(novo);

}


void mostrarPilha(toppilha *p){

    if(pilhaVazia(p) == 0){
        pilhao *aux;
        aux = p->topo;


        while (aux != NULL)
        {
            printf("\n %d", aux->valor);

            aux = aux->anterior;
        }
        printf("\n\n");

    }
    else{
        //printf("\n===Pilha vazia===\n");
    }
}

void  desempilha(toppilha *p){

    pilhao *aux;
    aux=p->topo;
    p->topo = aux->anterior;
    aux->anterior=NULL;

    free(aux);

}

//=========================================================

void createfila(fila *f){
    f->inicio =NULL;
    f->fim    =NULL;
}

int fila_vazia(fila *f){

    if(f->inicio==NULL){
        return 1; //fila vazia
    }else{
        return 0; //fila não está vazia
    }
}

void insere_fila(fila *f,int valor){

    Tfila *novo= malloc(sizeof(Tfila));
    novo->dado = valor;
    novo->prox = NULL;


  if(fila_vazia(f)==1){//primeira vez na fila
    f->inicio = novo;
    f->fim    = novo;


  }else{
    f->fim->prox = novo;
    f->fim = novo; //ajusta o ponteiro do fim

  }

    novo=NULL;
    free(novo);
}

int remove_fila(fila *f){
  int valor;

  Tfila *aux=malloc(sizeof(Tfila));

  aux=f->inicio; //aux aponta para o inicio da fila

  valor = aux->dado; //guardando o valor na variável

  f->inicio = aux->prox; //ajustando o ponteiro do inicio

  aux->prox = NULL;

  if(f->inicio==NULL){ //verifico se existe um só elemento
    f->fim=NULL;
    free(aux);
  }else{
   free(aux);
  }

  return valor;

}

void mostrar_fila(fila *f){

 Tfila *aux=malloc(sizeof(Tfila));

 aux = f->inicio;

     while(aux!= NULL){
        printf(" | %d",aux->dado);
        aux=aux->prox;

     }
   free(aux);

}

void menu(){

    fila *f= malloc(sizeof(fila));
    createfila(f);

    toppilha *pi1 = malloc(sizeof(pilhao));
    criarPilha(pi1);


 int op;  //opção recursiva

 do{
     system("cls");

     printf("\n Fila: \n");
     mostrar_fila(f);

     printf("\nPilha: \n");
     mostrarPilha(pi1);

     printf("\n\n");
     printf("1 - Enfileirar \n");
     printf("2 - Desenfileirar \n");
     printf("3 - Sair \n ");

     printf("\n\n Informe a opcao :>_");
     scanf("%d",&op);

    switch(op){

      case 1:{
         int x;
         printf("Informe o valor :");
         scanf("%d",&x);
         insere_fila(f,x);
        //insere_fila( 2a , 30)


         break;
     }


     case 2:{//remover fila
          int x;
          if(fila_vazia(f)==1){
            printf("\n nao e possivel remover ");
            printf(" ------>fila vazia!! \n");
            getch( );
          }else{
              x=remove_fila(f);
              empilharElemento(pi1, x);
              printf("\n \t valore retirado %d ",x);
              getch( );
          }
          break;

      }

     case 3:
        op=3;
    }

 }while(op != 3);
}

void criarPilha(toppilha *p);
int pilhaVazia(toppilha *p);
void empilharElemento(toppilha *p, int valor);
void mostrarPilha(toppilha *p);
void  desempilha(toppilha *p);
void createfila(fila *f);
int fila_vazia(fila *f);
void insere_fila(fila *f,int valor);
int remove_fila(fila *f);
void mostrar_fila(fila *f);
void menu();



int main()
{


    menu();


    printf("\n\n");






    return 0;
}
