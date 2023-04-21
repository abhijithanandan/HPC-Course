#include <omp.h>
#include <stdio.h>

// Use the OMP_NUM_THREADS environment variable to set the number of threads
int main(int argc, char *argv[]) {
  int nthreads, tid;
/* Fork a team of threads giving them their own copies of variables */
#pragma omp parallel private(nthreads, tid)
  {
    /* Obtain thread number */
    tid = omp_get_thread_num();
    printf("Hello World from thread = %d \n", tid);
    if (tid == 0) {
      /* Only master thread does this */
      nthreads = omp_get_num_threads();
      printf("Number of threads = %d \n", nthreads);
    }
  }
  return 0;
}
