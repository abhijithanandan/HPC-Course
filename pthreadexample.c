#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* function1(void *arg) {
  while(1) {
    // do something
    sleep(1);
    printf("Hello from is function 1\n");
  }

  return NULL;
}

void function2(void) {
  while(1) {
    // do something
    sleep(2);
    printf("Hello from is function 2\n");
  }
}

int main(void) {

  pthread_t newthread;

  pthread_create(&newthread, NULL, (void *)function1, NULL);
  function2();

  return 0;
}
