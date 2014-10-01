#include "func.h"
#include <math.h>
#include <stdio.h>

int solution(double a, double b, double c, double* x)
{
    double d;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                return INFINITE_ROOTS;
            else
                return 0;
        }
        else
        {
            x[0] = (-1) * c / b;
            if (x[0] == -0)
                x[0] = 0;
            return 1;

        }
    }
    else
    {
        d = b * b - 4 * a * c;
        if (d == 0)
        {
            x[0] = -b / (2 *a);
            return 1;
        }
        else if (d > 0)
        {
            x[0] = (-b - sqrt(d)) / (2 * a);
            x[1] = (-b + sqrt(d)) / (2 * a);
            return 2;
        }
        else return 0;
    }
}


void output(int numberOfSol, double* x)
{
    switch (numberOfSol)
    {
    case INFINITE_ROOTS:
        printf("Infinite roots");
        break;
    case 0:
        printf("No roots");
        break;
    case 1:
        printf("x = %lg", x[0]);
        break;
    case 2:
        printf("x1 = %lg, x2 = %lg", x[0], x[1]);
        break;
    }
}
