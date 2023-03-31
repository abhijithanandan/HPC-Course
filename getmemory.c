#include <stdio.h>
#include <stdlib.h>

int main() {
  for (int i = 0; i < 10; i++) {
    int *p = (int *)malloc(100000000);
    printf("Got memory at %p\n", p);
  }
}
