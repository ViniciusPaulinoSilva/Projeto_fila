
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
  time_t atual;
  time(&atual);
  no *novo = (no*)malloc(sizeof(no));
  if (novo == NULL)
  {
    printf("Heap overflow");
    return;
  }
  if(*inicio == NULL)
  {
    novo -> criado = atual;
    novo -> prox = NULL;
    *inicio = novo;
    *fim = novo;
    return;
  }
  novo->criado = atual;
  novo->prox = NULL;
  (*fim)->prox = novo;
  (*fim) = novo;
  //time(&fim -> criado);
}

void deleta(no **inicio, int *maximo, int *minimo, int *media_geral)
{
  no* aux = *inicio;
  time_t remocao;
  time(&remocao);
  int tempo = difftime(remocao, (*inicio)->criado);
  *media_geral += tempo;
  if(tempo < *minimo)
  {
    *minimo = tempo;
  }
  if(tempo > *maximo)
  {
    *maximo = tempo;
  }
  (*inicio) = (*inicio)->prox;
  free(aux);
}
int main()
{
  system("cls");
  setlocale(LC_ALL, "portuguese");

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


  while(difftime(atual, inicial) <= duration)
  {
    printf("\nTempo decorrido: %d", (int)difftime(atual, inicial));
    printf("\n\nFila 1: ");
    for (int i = 0; i < count1; i++)
    {
      printf(" ---###--- ");
    }
    printf("\n\nFila 2: ");
    for (int i = 0; i < count2; i++)
    {
      printf(" ---###--- ");
    }
    printf("\n\nFila 3: ");
    for (int i = 0; i < count3; i++)
    {
      printf(" ---###--- ");
    }
    if((int)difftime(atual, inicial) % remov == 0 && (int)difftime(atual,inicial) != 0)
    {
      if (count1 > 0)
      {
        if ((int)difftime(atual, inicio1->criado) >= remov)
        {
          deleta(&inicio1, &max, &min, &media_geral);
          count1--;
        }
      }
      if (count2 > 0)
      {
        if ((int)difftime(atual, inicio2->criado) >= remov)
        {
          deleta(&inicio2, &max, &min, &media_geral);
          count2--;
        }
      }
      if (count3 > 0)
      {
        if ((int)difftime(atual, inicio3->criado) >= remov)
        {
          deleta(&inicio3, &max, &min, &media_geral);
          count3--;
        }
      }
      //chama função de remover;
      //soma tempo em variavel media_geral;
      // verifica se o tempo é menor ou maior q a max e a min;
    }
    if((int)difftime(atual, inicial) % insert == 0 && (int)difftime(atual, inicial) != 0)
    {
      if (count1 == 0)
      {
        insere(&inicio1, &fim1);
        count1++;
        countall++;
      }
      else if (count2 == 0)
      {
        insere(&inicio2, &fim2);
        count2++;
        countall++;
      }
      else if (count3 == 0)
      {
        insere(&inicio3, &fim3);
        count3++;
        countall++;
      }
      else if (count1 < count2)
      {
        if (count1 < count3)
        {
          insere(&inicio1, &fim1);
          count1++;
          countall++;
        }
        else
        {
          insere(&inicio3, &fim3);
          count3++;
          countall++;
        }
      }
      else if (count2 < count3)
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
    Sleep(1000);
    system("cls");
    time(&atual);
    // printa filas e tempo q o programa esta sendo executado
  }
  printf("\n\ncount all: %d\n\nMÉDIA GERAL: %.2f\n\n", countall, (float)(media_geral / countall));
  // printa tempos de espera
}
