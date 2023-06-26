#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asm.h"

void make_subleqs(char *buffer) {
    struct memory *m = create_memory();
    char *front_cursor = buffer;
    char *rear_cursor = buffer;

    char token[6];

    while(1) {
        read_token(token, &front_cursor, &rear_cursor);
        // printf("[debug] %s\n", token);

        if(strcmp(token, "var") == 0) {
            ins_var(m);
        } else if(strcmp(token, "const") == 0) {
            char C = read_num(&front_cursor, &rear_cursor);
            ins_const(m, C);
        } else if(strcmp(token, "mov") == 0) {
            char a = read_num(&front_cursor, &rear_cursor);
            char b = read_num(&front_cursor, &rear_cursor);
            ins_mov(m, a, b);
        } else if(strcmp(token, "mul") == 0) {
            char a = read_num(&front_cursor, &rear_cursor);
            char b = read_num(&front_cursor, &rear_cursor);
            ins_mul(m, a, b);
        } else {
            printf("unknown token\n");
            // exit(1);
            break;
        }
        
    }
    for(int i = 0; i < 120; i += 3)
        printf("%3d: %3d %3d %3d\n", i, m->mem[i], m->mem[i+1], m->mem[i+2]);

    for(int i = 120; i < 128; i++)
        printf("mem[%d]: %d\n", i, m->mem[i]);
}

char ins_var(struct memory *m) {
    m->data_counter--;

    return m->data_counter;
}

void ins_var_reduce(struct memory *m) {
    m->data_counter++;
}

char ins_const(struct memory *m, char C) {
    m->mem[--(m->data_counter)] = C;

    return m->data_counter;
}

void ins_mov(struct memory *m, char a, char b) {
    m->mem[m->code_counter++] = Z;
    m->mem[m->code_counter++] = Z;
    m->mem[m->code_counter++] = NEXT;

    m->mem[m->code_counter++] = b;
    m->mem[m->code_counter++] = b;
    m->mem[m->code_counter++] = NEXT;

    m->mem[m->code_counter++] = a;
    m->mem[m->code_counter++] = Z;
    m->mem[m->code_counter++] = NEXT;

    m->mem[m->code_counter++] = Z;
    m->mem[m->code_counter++] = b;
    m->mem[m->code_counter++] = NEXT;
}

void ins_sub(struct memory* m, char a, char b) {
    m->mem[m->code_counter++] = a;
    m->mem[m->code_counter++] = b;
    m->mem[m->code_counter++] = NEXT;
}

void ins_mul(struct memory* m, char a, char b) {
    char C1 = ins_const(m, 1);
    char T1 = ins_var(m);
    char T2 = ins_var(m);
    ins_mov(m, a, T1);
    ins_sub(m, C1, a);
    ins_mov(m, b, T2);

    add_label(m, m->label_counter);

    ins_beqz(m, )


    ins_var_reduce(m);
    ins_var_reduce(m);
}

void add_label(struct memory *m, char label_name) {
    m->label_name[m->label_counter] = label_name;
    m->label_addr[m->label_counter] = NEXT;
    m->label_counter++;
}

struct memory *create_memory() {
    struct memory *m = (struct memory*)malloc(sizeof(struct memory));
    m->code_counter = 0;
    m->data_counter = 127;
    m->label_counter = 0;

    return m;
}

void read_token(char *token, char **front_cursor, char **rear_cursor) {
    for(; **rear_cursor != ' ' && **rear_cursor != '\n'; (*rear_cursor)++);

    size_t size = *rear_cursor - *front_cursor;

    strncpy(token, *front_cursor, size);
    token[size] = 0;

    (*rear_cursor)++;
    *front_cursor = *rear_cursor;
}

char read_num(char **front_cursor, char **rear_cursor) {
    char num[8];
    
    for(; **rear_cursor != ' ' && **rear_cursor != '\n'; (*rear_cursor)++);

    size_t size = *rear_cursor - *front_cursor;

    strncpy(num, *front_cursor, size);
    num[size] = 0;

    (*rear_cursor)++;
    *front_cursor = *rear_cursor;

    return atoi(num);
}
