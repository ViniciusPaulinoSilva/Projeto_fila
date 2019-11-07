#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

time_t duration;
time_t insere;
time_t delet;

typedef struct fila no;

struct fila
{
    time_t criado;
    int count;
    short int status;
    struct fila *prox;
};

void insert(no *head);

int main()
{
    time_t atual;
    while(difftime(duration, atual)!=60){

        no* menor;
        time_t atual;
        setlocale(LC_ALL, "portuguese");
        no *fila1 = (no*)malloc(sizeof(no));
        fila1->count = 0;
        fila1->prox = NULL;
        no *fila2 = (no*)malloc(sizeof(no));
        fila2->count = 0;
        fila2->prox = NULL;
        no *fila3 = (no*)malloc(sizeof(no));
        fila3->count = 0;
        fila3->prox = NULL;

        while(difftime(duration,insere)==2){
    if(fila1->count = 0){
        insert(fila1);
        fila1->count++;
    }

    if(fila2->count = 0){
        insert(fila2);
        fila2->count++;
    }

    if(fila3->count = 0){
    insert(fila3);
    fila3->count++;
    }

    if(fila1->count < fila2->count){

        if(fila1->count < fila3->count){

            menor = fila1;
        }else if(fila2->count < fila3->count){

                    menor = fila2;
        }       else{

                        menor = fila3;
                    }
    }
    insert(menor);
    menor->count++;
    }
 }
}

void insert(no *head)
{
    time_t atual;
    no *novo = (no*)malloc(sizeof(no));
    novo->criado = atual;
    head->prox = novo;
    system("pause");
}
