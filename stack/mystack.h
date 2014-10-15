#include <stdlib.h>
#include <math.h>

#ifndef MYSTACK
#define MYSTACK

struct mystack
{
    struct mystackval* last = NULL;
    double pop();
    int push(double a);
    void delall();
};

struct mystackval;

#endif // MYSTACK
