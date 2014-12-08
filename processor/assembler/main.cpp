#include<stdio.h>
#include"asslib.h"




int main()
{
    FILE* input,* output;
    long* labels = NULL;
    int numberOfLabels = 0;
    input = fopen("sourcecode.txt","r");
    output = fopen("bincode.txt","wb");
    numberOfLabels = fillLabels( input, &labels );
    assemblation( input, output, labels, numberOfLabels );
    fclose(input);
    fclose(output);
    return 0;
}

