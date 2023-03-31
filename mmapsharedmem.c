// Simple program to show how processes can share memory

#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>
#include <sys/mman.h>

#define PAGESIZE 4096

int a = 0;

int main(int argc, char *argv[]) {
  int pid;

  uint8_t *shared_a = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  *shared_a = 0;

  pid = fork();
  if (pid == 0) {
    // Child processes
    a = 2;
    *shared_a = 2;
  } else {
    // Parent process
    wait(NULL);
    // a = 90;
  }
  printf("The vlaue of a on process %d is %d \n", getpid(), a);
  printf("The vlaue of shared_a on process %d is %d \n", getpid(), *shared_a);
  return 0;
}
