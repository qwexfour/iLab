#include<stdio.h>
#include"proclib.h"


int main()
{
    int* commandList = NULL;
    int numberOfCommands = 0;
    FILE* input;
    input = fopen("bincode.txt","rb");
    numberOfCommands = fGetCode( &commandList, input );
    fclose( input );
    //dumpCode( commandList, numberOfCommands );
    runCode( commandList, numberOfCommands );
    return 0;
}
