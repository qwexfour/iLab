#include <stdio.h>
#include <stdlib.h>
#include "func.h"


int main()
{
    int numberOfSol = 0;
    double a, b, c, x[2];
    printf("Enter the coefficients a, b, c of the quadratic equation a * x^2 + b * x + c = 0\n");
    scanf("%lg %lg %lg", &a, &b, &c);
    numberOfSol = solution(a, b, c, x);
    output(numberOfSol, x);
    return 0;
}
