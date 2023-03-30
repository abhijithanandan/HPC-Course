// Simple program to demonstrate the use of the zombie process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Declare true
#define true 1

int main()
{
  while (true) {
    if (fork() == 0) {
      printf("Child process started ...... and is done! \n");
      return 0;
    } else {
      printf("Parent process started ...... \n");
      printf("Parent just won't die ......!!! \n");
      sleep(2);
    }
  }
}
