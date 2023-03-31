
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// alter the behavior of the process when a sinal is received is raised
void sgehandler(int signo) {
  write(STDOUT_FILENO, "I won't die!\n", signo);
}

int main() {
  struct sigaction act;
  act.sa_handler = sgehandler;

  sigaction(SIGINT, &act, NULL);
  sigaction(SIGTERM, &act, NULL);

  while (1) {
    printf("This process with pid %d will run forever.\n", getpid());
    sleep(1);
  }
  return 0;
}
