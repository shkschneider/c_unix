#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

static sem_t	sema;
int		the_end;

void	*thread1_process(void *arg)
{
  while (!the_end)
    {
      printf("Je t'attend !\n");
      sem_wait(&sema);
    }
  printf("OK, je sors !\n");
  pthread_exit(0);
}

void	*thread2_process(void *arg)
{
  int	i;

  for (i = 0; i < 5; i++)
    {
      printf("J'arrive %d !\n", i);
      sem_post(&sema);
      sleep(1);
    }
  the_end = 1;
  sem_post(&sema);
  pthread_exit(0);
}

int		main(int argc, char **argv)
{
  pthread_t	thread1;
  pthread_t	thread2;

  sem_init(&sema, 0, 0);
  pthread_create(&thread1, NULL, thread1_process, NULL);
  pthread_create(&thread2, NULL, thread2_process, NULL);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  return (0);
}
