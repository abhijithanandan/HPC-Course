// An example to showcase the use of pthreads with arguments

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void *function1(void *arg) {
  int *val = (int *)arg;
  int *iptr = (int *)malloc(sizeof(int));
  for (int i = 0; i < 5; i++) {
    sleep(1);
    printf("Fun 1 Iter: %d and val = %d and ret_val = %d\n", i, *val, *iptr);
    (*val)++;
    (*iptr)++;
  }

  return iptr;
}

void function2() {
  for (int i = 0; i < 5; i++) {
    sleep(2);
    printf("Fun 2 Iter: %d\n", i);
  }

}


int main() {
  pthread_t thread_id;
  int val = 10;
  int *ret_val;
  int ret;

  ret = pthread_create(&thread_id, NULL, function1, &val);
  if (ret != 0) {
    printf("Error creating thread %d ", ret);
    return 1;
  }
  function2();

  //wait until the thread finishes
  pthread_join(thread_id, (void *)&ret_val);

  printf("val = %d and ret_val = %d\n", val, *ret_val);
  return 0;
}
