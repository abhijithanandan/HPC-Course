#include <stdint.h>
#include <stdio.h>
#include <sys/mman.h>

#define PAGESIZE 4096

int main() {
  // The pagesize is alaways a multiple of 4096 irrespective of what you set it
  // to. So even if we specify the start address it may only give the page that
  // contains that address. The PORT_* defines protect the memory from being
  // accessed The MAP_* defines the type of memory mapping, how it is shared
  // among different processes. The last part is for memeory mapped file I/O

  uint8_t *first = mmap((void *)0xFEEDBEEF, 4*PAGESIZE, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  uint8_t *second = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  printf("First: %p\n", first);
  printf("Second: %p\n", second);

  return 0;
}
