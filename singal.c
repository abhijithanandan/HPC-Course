#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// alter the behavior of the process when a sinal is received is raised
void handler(int signo) {
  write(STDOUT_FILENO, "I won't die!\n", signo);
}

int main() {
  // run the handler whenerver SIGINT is raised
  signal(SIGINT, handler);
  // run the handler whenerver SIGTERM is raised
  signal(SIGTERM, handler);
  while (1) {
    printf("This process with pid %d will run forever.\n", getpid());
    sleep(1);
  }
  return 0;
}
