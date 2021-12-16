//Math Subroutine
//Team 7
.text

.global add
add:
    //add r1 to r0
    ADD r0,r1
    MOV pc,lr

.global sub
sub:
    //Subtract r1 from r0
    SUB r0,r1
    MOV pc,lr

.global mul
mul:
    //Multiply registers r0 and r1 together, save result in r0
    MUL r0,r0,r1
    MOV pc,lr

.global div
div:
    //Subtract Divisor from Dividend
    SUB r0,r1 
    //Increment Quotient
    ADD r4,r4,#1
    //Test if Divisor can be subtracted from Dividend again
    CMP r0,r1
    BPL div

    //Move Remainder into remainder pointer
    CMP r0,#0
    RSBLT r0,r0,#0 
    STR r0,[r2]
   
    //Return quotient from function and clear register
    MOV r0,r4
    MOV r4,#0

    MOV pc,lr
.end
