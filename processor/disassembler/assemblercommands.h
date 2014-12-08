#ifndef ASSEMBLERCOMMANDS
#define ASSEMBLERCOMMANDS
enum Commands
 {
    PUSH = 1,
    ADD = 1000,
    MUL = 1001,
    OUT = -2,
    END = 0,
    POP = -1,
    SUB = 1003,
    DIV = 1002,
    PUSHX = 100,
    MOV = 500,
    MOVX = 501,
    CMP = -500,
    CMPX = -501,
    POPX = -100,
    JNE = 10000,
    JE = 10001,
    JL = 10002,
    JB = 10003,
    JMP = 10004
 };
#endif
