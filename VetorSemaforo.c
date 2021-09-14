#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>
#include <time.h>

#define QT_THREAD 4
#define TERMOS 100
#define NUMERO 27

typedef struct
{
  int idx, length;
} thread_arg, *ptr_thread_arg;

pthread_t threads[QT_THREAD];
thread_arg arguments[QT_THREAD];

sem_t semaforo;

int resultado;

int vetor[TERMOS];

void *buscaVetor(void *arg)
{
  ptr_thread_arg argument = (ptr_thread_arg)arg;
  double somaLocal = 0;
  int endidx;
  endidx = argument->idx + argument->length;
  for (int i = argument->idx; i < endidx; i++)
  {
    if (vetor[i] == NUMERO)
    {
      somaLocal++;
    }
  }
  printf("Soma local: %lf\n", somaLocal);
  sem_wait(&semaforo);
  resultado += somaLocal;
  sem_post(&semaforo);
}

int main()
{
  clock_t tInicio, tFim, t;
  sem_init(&semaforo, 0, 1);
  resultado = 0;
  int length = TERMOS / QT_THREAD;
  int remainder = TERMOS % QT_THREAD;
  tInicio = clock();

  for (int i = 0; i < TERMOS; i++)
  {
    vetor[i] = rand() % 100;
  }

  for (int i = 0; i < QT_THREAD; i++)
  {
    arguments[i].idx = i * length;
    arguments[i].length = length;
    if (i == (QT_THREAD - 1))
    {
      arguments[i].length += remainder;
    }
    pthread_create(&threads[i], NULL, buscaVetor, &arguments[i]);
  }

  for (int i = 0; i < QT_THREAD; i++)
  {
    pthread_join(threads[i], NULL);
  }

  printf("Vetor: \n");
  for (int i = 0; i < TERMOS; i++)
  {
    printf("%d \n", vetor[i]);
  }

  sem_destroy(&semaforo);
  tFim = clock();
  t = tFim - tInicio;

  printf("\nQuantidade de vezes que o número 27 apareceu: %d \n", resultado);
  printf("Ticks gastos: %d. Tempo gasto: %Lf s\n", (int)t, (long double)(t / CLOCKS_PER_SEC));
}