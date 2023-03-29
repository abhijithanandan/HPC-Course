// Simple program to demonstrate process fork() pid

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  fork();
  printf("Hello World from process with pid %d\n", getpid());

  return 0;
}
