// A simple script to do vector addition with openmp

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[])
{
  int n, i;

  double *x, *y;

// Get input array size
  
  n = atoi(argv[1]);

  x = (double *) malloc(n*sizeof(double));

  y = (double *) malloc(n*sizeof(double));

// Initialize x and y arrays

  for (i = 0; i < n; i++) {
      x[i] = 1.0;
      y[i] = 2.0;
    }

  // Serial version
  // Compute the wall time

  double start = omp_get_wtime();

  for (i = 0; i < n; i++) {
      x[i] = x[i] + y[i];
    }

  double end = omp_get_wtime();

  printf("Time taken: %f seconds for serial run \n", end - start);


  // Parallel version
  // Compute the wall time

  start = omp_get_wtime();

  #pragma omp parallel for private(i) shared(x,y)
  for (i = 0; i < n; i++) {
      x[i] = x[i] + y[i];
    }

  end = omp_get_wtime();

  printf("Time taken: %f seconds parallel run \n", end - start);

  free(x);
  free(y);

  printf("Done!");

  return 0;
}
