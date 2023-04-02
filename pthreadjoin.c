#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* function1(void *arg) {
  for(int i = 0; i < 10; i++) {
    // do something
    sleep(1);
    printf("Hello from is function 1, iter = %d\n", i+1);
  }

  return NULL;
}

void function2(void) {
  for(int i = 0; i < 5; i++) {
    // do something
    sleep(1);
    printf("Hello from is function 2, iter = %d\n", i+1);
  }
}

int main(void) {

  pthread_t newthread;

  pthread_create(&newthread, NULL, (void *)function1, NULL);
  function2();

  pthread_join(newthread, NULL);
  return 0;
}
