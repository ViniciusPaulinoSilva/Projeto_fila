
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

typedef struct fila no;

struct fila
{
    time_t criado;
    int count;
    struct fila *prox;
};

int main()
{
    setlocale(LC_ALL, "portuguese");
    no *fila1 = (no*)malloc(sizeof(no));
    no *fila2 = (no*)malloc(sizeof(no));
    no *fila3 = (no*)malloc(sizeof(no));
    time_t duration;
    time_t insert;
    time_t remov;
    time_t inicio;
    no *inicio1 = fila1;
    no *fim1 = fila1;
    no *inicio2 = fila2;
    no *fim2 = fila2;
    no *inicio3 = fila3;
    no *fim3 = fila3;
    int media_geral = 0
    int min = 9999;
    int max = 0;

    while(difftime(duration,inicio!=0)){
        if(duration%insert==0){
            //chama função de inserir na menor fila
        }
        if(duration%remov==0){
            //chama função de remover;
            //soma tempo em variavel media_geral;
            // verifica se o tempo é menor ou maior q a max e a min;
        }
        Sleep(1000);
        //printa filas e tempo q o programa esta sendo executado
    }
    //printa tempos de espera
}
