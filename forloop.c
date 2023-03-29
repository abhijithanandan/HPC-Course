// A simple for loop example with openmp

#include <omp.h>
#include <stdio.h>

#define N 1000

#define CHUNKSIZE 100

int main(int argc, char *argv[]) {

  int i, chunk;

  float a[N], b[N], c[N];

  // Some initializations
  chunk = CHUNKSIZE;

  for (i = 0; i < N; i++)
    a[i] = b[i] = i * 1.0;

    // Do some work on the data

#pragma omp parallel shared(a, b, c, chunk) private(i)

  {

#pragma omp for schedule(static, chunk) nowait

    for (i = 0; i < N; i++)
      c[i] = a[i] + b[i];
  }

  // Print the results

  for (i = 0; i < N; i++)
    printf("%f ", c[i]);

  return 0;
}
