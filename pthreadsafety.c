// An example to count to a billion using two threads.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// The UL at the end of the number is to tell the compiler that it is an unsigned long. 
// Otherwise, it will assume it is an int and will not be able to count to a billion.
#define BIGCOUNT 1000000000UL
u_int32_t count = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *count_to_bigcount(void *arg) {
  while (count < BIGCOUNT) {
    pthread_mutex_lock(&lock);
    count++;
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t thread;

  pthread_create(&thread, NULL, count_to_bigcount, NULL);
  count_to_bigcount(NULL);
  pthread_join(thread, NULL);
  printf("Counting done and final value of count is %u\n", count);

  return 0;
}


