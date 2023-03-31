// A simple program to print the contents of a named pipe

#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main() {
  int fd = open("mypipe", O_RDONLY);
  char c;

  while (read(fd, &c, 1) > 0) {
    printf("%c", toupper(c));
  }
  close(fd);
  return 0;
}
