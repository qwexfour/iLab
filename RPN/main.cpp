#include <stdio.h>
#include "stacklib.h"

int inputAndSolution();
void output();


int main()
{
    printf("Enter the RPN and put EOF at the end\n");
    output();
    return 0;
}



int inputAndSolution()
{
    struct item* RPN = NULL;
    char scanChar;
    int scanValue = 0, RPNValue = 0, nowRes = 0, flag = 0;

    create_stack(&RPN);

    scanf("%i", &scanValue);
    push_stack(&RPN, scanValue);

    while(scanf("%i", &scanValue) != EOF)
    {
        RPNValue = pop_stack(&RPN);
        flag = 1;
        while(flag)
        {
            scanChar = getchar();
            switch(scanChar)
            {
            case '+':
                nowRes = RPNValue + scanValue;
                flag = 0;
                break;
            case '-':
                nowRes = RPNValue - scanValue;
                flag = 0;
                break;
            case '*':
                nowRes = RPNValue * scanValue;
                flag = 0;
                break;
            case '/':
                nowRes = RPNValue / scanValue;
                flag = 0;
                break;
            case EOF:
                printf("ERROR: You didn't enter sign\n");
                break;
            case '\n':
                printf("ERROR: You didn't enter sign\n");
                break;
            default:
                break;
            }
        }
        push_stack(&RPN, nowRes);
    }
    nowRes = pop_stack(&RPN);
    delete_stack(&RPN);
    return nowRes;
}



void output()
{
    //printf(" ");
    printf("Equals %d", inputAndSolution());

}
