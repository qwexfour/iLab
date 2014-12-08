#include<stdio.h>
#include"disasslib.h"


int main()
{
	FILE* input, * output;
	input = fopen("bincode.txt","rb");
	output = fopen("sourcecode.txt","w");
	disassemblation( input, output );
	fclose(input);
	fclose(output);
	return 0;
}
