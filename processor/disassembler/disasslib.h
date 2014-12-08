#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef DISASSLIB

#define DISASSLIB

int disassemblation( FILE*, FILE* );//Arguments: input file pointer, output file pointer. Return 1 if succeed, 0 if not succeed
int getCommandOfCode( char*, int );

#endif
