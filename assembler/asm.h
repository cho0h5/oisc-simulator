#define Z 127
#define NEXT (m->code_counter + 1)

void make_subleqs(char *buffer);
struct memory *create_memory();
void read_token(char*, char**, char**);
char read_num(char**, char**);

char ins_var(struct memory*);
void ins_var_reduce(struct memory*);
char ins_const(struct memory*, char);
void ins_jmp(struct memory*, char);
void ins_add(struct memory*, char, char);
void ins_mov(struct memory*, char, char);
void ins_beqz(struct memory*, char, char);
void ins_sub(struct memory*, char, char);
void ins_bnez(struct memory*, char, char);
void ins_bge(struct memory*, char, char, char);
void ins_blt(struct memory*, char, char, char);
void ins_bgt(struct memory*, char, char, char);
void ins_ble(struct memory*, char, char, char);
void ins_beq(struct memory*, char, char, char);
void ins_bne(struct memory*, char, char, char);
void ins_end(struct memory*);
void ins_mul(struct memory*, char, char);

void add_label(struct memory*, char);

/*
char TOKENS[][6] = {
  "jmp",   //       c
  "add",   // a, b
  "mov",   // a, b
  "beqz",  //    b, c
  "sub",   // a, b
  "bnez",  //    b, c
  "bge",   // a, b, c
  "blt",   // a, b, c
  "bgt",   // a, b, c
  "ble",   // a, b, c
  "beq",   // a, b, c
  "bne",   // a, b, c
  "end",   // 
  "mul",   // a, b
  "var",
  "const", // C
};
*/

struct memory {
  char mem[128];
  char code_counter;
  char data_counter;
  struct {
    char label_name[128];
    char label_addr[128];
    char label_counter;
  };
};


