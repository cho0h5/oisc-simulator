#include <stdio.h>

#define MEM_SIZE 128

void init_mem();
void check_mem();
void run();

char mem[MEM_SIZE];

int main() {
  init_mem();
  run();
  check_mem();

  return 0;
}

void run() {
  char pc = 0;
  char a, b, c;

  while(pc >= 0) {
    a = mem[pc + 0];
    b = mem[pc + 1];
    c = mem[pc + 2];

    mem[b] = mem[b] - mem[a];
    if(mem[b] <= 0) pc = c;
    else pc += 3;
  }
}

void check_mem() {
  for(int i = 0; i < 9; i += 3) {
    printf("%3d: %3d %3d %3d\n", i, mem[i], mem[i + 1], mem[i + 2]);
  }
}

void init_mem() {
  mem[0] = 3;
  mem[1] = 4;
  mem[2] = 6;
  mem[3] = 7;
  mem[4] = 7;
  mem[5] = 7;
  mem[6] = 127;
  mem[7] = 127;
  mem[8] = -1;
}
