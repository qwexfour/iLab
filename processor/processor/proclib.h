#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"mystack.h"
#include"assemblercommands.h"


#ifndef PROCLIB
#define PROCLIB

int fGetCode( int**, FILE* ); //Arguments: pointer to NULL int pointer, FILE; Returns: number of elements and array of commands through pointer
int runCode( int*, int );//Arguments: array of commands, number of commands
int dumpCode( int*, int );
int safetyPop( struct mystack* );
int safetyReg( int );

#endif
