#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define TAM_VETOR 100
#define QT_THREAD 4
#define NUMERO 27

int vetor[TAM_VETOR];

int count = 0;
int qtde = 0;

void *buscaVetor(void *arg)
{
  int count2 = count++;

  for (int i = count2 * TAM_VETOR; i < (count2 + 1) * TAM_VETOR; i++)
  {
    if (vetor[i] == NUMERO)
    {
      qtde++;
    }
  }
}

int main()
{
  for (int i = 0; i < TAM_VETOR; i++)
  {
    vetor[i] = rand() % 100;
  }

  printf("Vetor: \n");
  for (int i = 0; i < TAM_VETOR; i++)
  {
    printf("%d \n", vetor[i]);
  }

  pthread_t threads[QT_THREAD];

  for (int i = 0; i < QT_THREAD; i++)
  {
    int *p;
    pthread_create(&threads[i], NULL, buscaVetor, (void *)(p));
  }

  printf("\nQuantidade de vezes que o número apareceu: %d \n", qtde);
}