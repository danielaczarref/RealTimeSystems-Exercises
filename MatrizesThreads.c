#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define QT_MATRIZ 4
#define QT_THREAD 16

int matriz1[QT_MATRIZ][QT_MATRIZ];
int matriz2[QT_MATRIZ][QT_MATRIZ];
int resMatriz[QT_MATRIZ][QT_MATRIZ];

int count = 0;

void *multiplicaMatriz(void *arg)
{
  int count2 = count++;

  for (int i = count2 * QT_MATRIZ; i < (count2 + 1) * QT_MATRIZ; i++)
  {
    printf("\nTeste 1: %d", count2 * QT_MATRIZ);
    printf("\nTeste 2: %d", (count + 1) * QT_MATRIZ);
    for (int j = 0; j < QT_MATRIZ; j++)
    {
      for (int k = 0; k < QT_MATRIZ; k++)
      {
        resMatriz[i][j] += matriz1[i][k] * matriz2[k][j];
      }
    }
  }
}

int main()
{
  for (int i = 0; i < QT_MATRIZ; i++)
  {
    for (int j = 0; j < QT_MATRIZ; j++)
    {
      matriz1[i][j] = rand() % 10;
      matriz2[i][j] = rand() % 10;
    }
  }

  printf("Primeira matriz: \n");
  for (int i = 0; i < QT_MATRIZ; i++)
  {
    for (int j = 0; j < QT_MATRIZ; j++)
    {
      printf("%d \n", matriz1[i][j]);
    }
  }

  printf("\nSegunda matriz: \n");
  for (int i = 0; i < QT_MATRIZ; i++)
  {
    for (int j = 0; j < QT_MATRIZ; j++)
    {
      printf("%d \n", matriz2[i][j]);
    }
  }

  pthread_t threads[QT_THREAD];

  for (int i = 0; i < QT_THREAD; i++)
  {
    int *p;
    pthread_create(&threads[i], NULL, multiplicaMatriz, (void *)(p));
  }

  printf("\nMultiplicacao de matriz 1 e matriz 2:\n\n");
  for (int i = 0; i < QT_MATRIZ; i++)
  {
    for (int j = 0; j < QT_MATRIZ; j++)
    {
      printf("%d \n", resMatriz[i][j]);
    }
  }
}