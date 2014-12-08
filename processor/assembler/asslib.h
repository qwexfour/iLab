#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef ASSLIB
#define ASSLIB

int assemblation( FILE*, FILE*, long[], int );//Arguments: input, output file pointer, array of labels with its number of elements. Return 1 if succeed, 0 if not succeed
int getCodeOfCommand( int*, char* );
int getRegOrVal( FILE*, int* );
int getLabel( FILE*, int* );
int fillLabels( FILE*, long** );//Arguments:FILE*(input), pointer to NULL labels array pointer. Return number of elements in the array, or 0 if no elements 


#endif
