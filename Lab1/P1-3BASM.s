//Assembly Subroutine
//Team 7
    .section ".text"
    .global next_char
next_char:
    ADD r0,#1   //How is the ARM calling convention obeyed here?
    MOV pc,lr
    .end