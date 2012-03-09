#include <stdio.h>
#include <pthread.h>

void *work(void *arg)
{
  int i;

  /* pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL); */
  for (i = 0; i < 5; i++)
    {
      printf("Thread %s: %d\n", (char *)arg, i);
      sleep(1);
    }
  pthread_exit(0);
}

int main(void)
{
  pthread_t thread1;
  pthread_t thread2;
  pthread_attr_t pattr;

  pthread_attr_init(&pattr);
  /* pthread_attr_setdetachstate(&pattr, PTHREAD_CREATE_DETACHED); */
  pthread_create(&thread1, &pattr, work, "1");
  pthread_create(&thread2, &pattr, work, "2");
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  /* pthread_cancel(thread2); */
  return (0);
}
