
/******************************************************
/                                                     /
/   Nomes: Gabriel Yamamoto, Vinicius Silva           /
/             RAs: 19241611, 18713529                 /
/                                                     /
/*****************************************************/

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
  struct fila *prox;
};

void insere(no **inicio, no **fim)
{
  printf("fds");
  time_t atual;
  time(&atual);
  if((no*)inicio == NULL)
  {
    no *Novo = (no*)malloc(sizeof(no));
    Novo -> criado = atual;
    Novo -> prox = NULL;
    no* inicio = Novo;
    no* fim = Novo;
    printf("Inserido fila vazia");
    return;
  }
  no *Novo = (no*) malloc(sizeof(no));
  Novo->criado = atual;
  Novo->prox = NULL;
  (*fim)->prox = Novo;
  (*fim) = Novo;
  //time(&fim -> criado);
}

void deleta(no **inicio, int *maximo, int *minimo, int *media_geral)
{
  no* Aux = *inicio;
  time_t remocao;
  time(&remocao);
  int tempo = difftime(remocao,(*inicio) -> criado);
  *media_geral += tempo;
  if(tempo < *minimo)
  {
    *minimo = tempo;
  }
  if(tempo > *maximo)
  {
    *maximo = tempo;
  }
  (*inicio) = (*inicio) -> prox;
  free(Aux);
}
int main()
{
  system("cls");
  setlocale(LC_ALL, "portuguese");
  printf("teste");

  no *fila1 = NULL;
  no *fila2 = NULL;
  no *fila3 = NULL;
  int duration = 60;
  int insert = 5;
  int remov = 10;
  time_t atual;
  time(&atual);
  time_t inicial;
  time(&inicial);
  no *inicio1 = fila1;
  no *fim1 = fila1;
  no *inicio2 = fila2;
  no *fim2 = fila2;
  no *inicio3 = fila3;
  no *fim3 = fila3;
  int media_geral = 0;
  int min = 9999;
  int max = 0;
  int count1 = 0;
  int count2 = 0;
  int count3 = 0;
  int countall = 0;


  while(difftime(inicial, atual) != duration)
  {
    printf("\n%d", (int)difftime(inicial, atual));
    if((int)difftime(inicial, atual) % insert == 0)
    {
      if(count1 == 0)
      {
        printf("teste");
        insere(&inicio1, &fim1);
        count1++;
        countall++;
      }
      else if(count2 == 0)
      {
        insere(&inicio2, &fim2);
        count2++;
        countall++;
      }
      else if(count3 == 0)
      {
        insere(&inicio3, &fim3);
        count3++;
        countall++;
      }
      if(count1 < count2)
      {
        if(count1 < count3)
        {
          insere(&inicio1, &fim1);
          count1++;
          countall++;
        }
        else
        {
          insere(&inicio3, &fim3);
          count2++;
          countall++;
        }
      }
      else
      {
        if (count2 < count3)
        {
          insere(&inicio2, &fim2);
          count2++;
          countall++;
        }
        else
        {
          insere(&inicio3, &fim3);
          count3++;
          countall++;
        }
      }
      //chama função de inserir na menor fila
    }
    // if((int)difftime(inicial, atual) % remov == 0)
    // {
    //   if(inicio1 -> criado >= remov)
    //   {
    //     deleta(&inicio1, &max, &min, &media_geral);
    //     count1--;
    //   }
    //   if(inicio2 -> criado >= remov)
    //   {
    //     deleta(&inicio2, &max, &min, &media_geral);
    //     count2--;
    //   }
    //   if(inicio3 -> criado >= remov)
    //   {
    //     deleta(&inicio3, &max, &min, &media_geral);
    //     count3--;
    //   }
    // //chama função de remover;
    // //soma tempo em variavel media_geral;
    // // verifica se o tempo é menor ou maior q a max e a min;
    // }
    Sleep(1000);
    time(&atual);
    // printa filas e tempo q o programa esta sendo executado
  }
  // printa tempos de espera
}
