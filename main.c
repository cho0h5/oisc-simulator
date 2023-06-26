#include <stdio.h>

#define MEM_SIZE 128

void init_mem();
void check_mem();
void run();

char mem[MEM_SIZE];

int main() {
  init_mem();
  run();

  return 0;
}

void run() {
  char pc = 0;
  char a, b, c;

  while(pc >= 0) {
    printf(" pc: %d\n", pc);
    a = mem[pc + 0];
    b = mem[pc + 1];
    c = mem[pc + 2];

    mem[b] = mem[b] - mem[a];
    if(mem[b] <= 0) pc = c;
    else pc += 3;

    check_mem();
  }
}

void check_mem() {
  printf("%3s: %3d\n", "a", mem[121]);
  printf("%3s: %3d\n", "b", mem[122]);
  printf("\n");
}

void init_mem() {
  mem[ 0] = 127;
  mem[ 1] = 127;
  mem[ 2] = 3;
  mem[ 3] = 121;
  mem[ 4] = 121;
  mem[ 5] = 6;
  mem[ 6] = 123;
  mem[ 7] = 127;
  mem[ 8] = 9;
  mem[ 9] = 127;
  mem[10] = 121;
  mem[11] = 12;
  mem[12] = 127;
  mem[13] = 127;
  mem[14] = 15;
  mem[15] = 122;
  mem[16] = 122;
  mem[17] = 18;
  mem[18] = 124;
  mem[19] = 127;
  mem[20] = 21;
  mem[21] = 127;
  mem[22] = 122;
  mem[23] = 24;
  mem[24] = 127;
  mem[25] = 127;
  mem[26] = 27;
  mem[27] = 125;
  mem[28] = 125;
  mem[29] = 30;
  mem[30] = 121;
  mem[31] = 127;
  mem[32] = 33;
  mem[33] = 127;
  mem[34] = 125;
  mem[35] = 36;
  mem[36] = 120;
  mem[37] = 121;
  mem[38] = 39;
  mem[39] = 127;
  mem[40] = 127;
  mem[41] = 42;
  mem[42] = 126;
  mem[43] = 126;
  mem[44] = 45;
  mem[45] = 122;
  mem[46] = 127;
  mem[47] = 48;
  mem[48] = 127;
  mem[49] = 126;
  mem[50] = 51;
  mem[51] = 127;
  mem[52] = 127;
  mem[53] = 54;
  mem[54] = 121;
  mem[55] = 127;
  mem[56] = 60;
  mem[57] = 127;
  mem[58] = 127;
  mem[59] = 66;
  mem[60] = 127;
  mem[61] = 127;
  mem[62] = 63;
  mem[63] = 127;
  mem[64] = 121;
  mem[65] = 81;
  mem[66] = 127;
  mem[67] = 127;
  mem[68] = 69;
  mem[69] = 126;
  mem[70] = 127;
  mem[71] = 72;
  mem[72] = 127;
  mem[73] = 122;
  mem[74] = 75;
  mem[75] = 120;
  mem[76] = 121;
  mem[77] = 78;
  mem[78] = 127;
  mem[79] = 127;
  mem[80] = 51;
  mem[81] = 127;
  mem[82] = 127;
  mem[83] = -1;

  mem[120] = 1;	// C1
  mem[121] = 0;	// a
  mem[122] = 0;	// b
  mem[123] = 7;	// C7
  mem[124] = 11;	// C11
  mem[125] = 0;	// T1
  mem[126] = 0;	// T2
  mem[127] = 0;	// Z
}
