// Team 7
// project 1 Part 3B
// Compile (gcc P1-3B.c P1-3BASM.s)
// Run the program (./a.out)
// Generate ASM (gcc -S P1-3B.c P1-3BASM.s)
// Open equivalent Assembly file 'P1-3B.s' and fulfill requirements

#include <stdio.h>
unsigned char next_char(char in);
void main() { printf("Next Character= %c\n", next_char('A')); }