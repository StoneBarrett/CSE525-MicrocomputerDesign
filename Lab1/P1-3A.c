// Team 7
// Project 1 Part 3A
// Compile on Raspberry PI without errors (gcc P1-3A.c)
// Run and test program (./a.out)
// Generate assembly listing (gcc -S P1-3A.c)
// Fulfill part 3A requirements with P1-3A.s file

#include <stdio.h>
unsigned char next_char(char in) { return in + 1; }

void main() { printf("Next Character= %c\n", next_char('A')); }