#include <stdlib.h>

#ifndef MYSTACK
#define MYSTACK

const int STACK_IS_EMPTY = -32222;

struct mystack
{
    struct mystackval* last = NULL;
    int pop();
    void push(int a);
    void delall();
};
#endif // MYSTACK
