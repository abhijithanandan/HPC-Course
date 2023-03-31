#include <stdio.h>
#include <unistd.h>

int main() {
  void *first = sbrk(0);
  void *second = sbrk(4096);
  void *third = sbrk(0);

  int *p = (int *)third + 1;
  *p = 0xDEAD;

  printf("First: %p\n", first);
  printf("Second: %p\n", second);
  printf("Third: %p\n", third);

  return 0;
}
