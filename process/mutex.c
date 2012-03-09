#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t mutex;
static int data[5];

void *read_data_process(void *arg)
{
  int i;

  pthread_mutex_lock(&mutex);
  for (i = 0; i < 5; i++)
    printf("read: data[%d]=%d\n", i, data[i]);
  pthread_mutex_unlock(&mutex);
  pthread_exit(0);
}

void *write_data_process(void *arg)
{
  int i;

  pthread_mutex_lock(&mutex);
  for (i = 0; i < 5; i++)
    {
      data[i] = 2 * i;
      printf("write: data[%d]=%d\n", i, data[i]);
  }
  pthread_mutex_unlock(&mutex);
  pthread_exit(0);
}

int main(void)
{
  pthread_t thread1;
  pthread_t thread2;

  pthread_mutex_init(&mutex, NULL);
  pthread_create(&thread1, NULL, write_data_process, NULL);
  pthread_join(thread1, NULL);
  sleep(1);
  pthread_create(&thread2, NULL, read_data_process, NULL);
  pthread_join(thread2, NULL);
  return (0);
}
