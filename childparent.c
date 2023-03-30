// Simple program to demonstrate fork() and exec() system calls

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  if (fork() == 0) {
    printf("I'm child with id %d and parent id %d \n", getpid(), getppid());
  } else {
    // Let's check the id of parent process and it's parent process
    printf("I'm parent with id %d and my parent has id %d \n", getpid(),
           getppid());
  }

  return 0;
}
