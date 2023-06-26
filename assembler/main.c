#include <stdio.h>

#include "file.h"
#include "asm.h"

int main() {
  char *buffer = file_read();

  // printf("%s\n", buffer);

  make_subleqs(buffer);

  return 0;
}
