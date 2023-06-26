#include "file.h"

size_t file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  fseek(file, 0, SEEK_SET);
  return size;
}

char *file_read() {
  FILE *file = fopen("test.asm", "r");
  size_t size = file_size(file);
  char *buffer = (char*)malloc(size);
  size_t count = fread(buffer, 1, size, file);
  if(count != size) {
    printf("something wrong during reading file");
    exit(1);
  }
  return buffer;
}
