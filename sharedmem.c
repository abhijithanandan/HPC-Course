// Simple program to show how processes can share memory

#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <wait.h>

#define PAGESIZE 4096

int a = 0;

int main(int argc, char *argv[]) {
  int pid;
  int *p;
  int i;

  pid = fork();
  if (pid == 0) {
    // Child processes
    a = 80;
  } else {
    // Parent process
    wait(NULL);
    // a = 90;
  }
  printf("The vlaue of a on process %d is %d \n", getpid(), a);
  return 0;
}
