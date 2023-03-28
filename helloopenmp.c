// A simple hello world program using OpenMP

#include <stdio.h>
#include <omp.h>

int main(void)
{
  printf("Hello World from main thread\n");

  #pragma omp parallel
  printf("Hello World from thread %d of %d. \n", omp_get_thread_num(), omp_get_num_threads());

  printf("Hello again from main thread");
  return 0;
}
