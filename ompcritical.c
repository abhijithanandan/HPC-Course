#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int x;
  x = 0;

  #pragma omp parallel shared(x)
  {
    // Try commeting out the pragma omp critical and see what happens
    #pragma omp critical
    {
      x = x + 1;
    } /* end of parallel region */
  }

  printf("x = %d\n" , x);
  return 0;
}
