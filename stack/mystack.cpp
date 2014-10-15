#include "mystack.h"

/*
struct mystack
{
    struct mystackval* last = NULL;
    double pop();
    int push(double a);
    void delall();
};
*/
struct mystackval
{
    double value;
    struct mystackval* previous = NULL;
};


int mystack::push(double a)
{

    struct mystackval* newEl = (struct mystackval*)calloc(1, sizeof(struct mystackval));
    struct mystackval* before;
    if (newEl == NULL)
        return 0;
    before = last;
    last = newEl;
    newEl->value = a;
    newEl->previous = before;
    return 1;
}



double mystack::pop()
{
    double result;
    struct mystackval* newLast;
    if (last == NULL)
        result = NAN;
    else
    {
        result =  last->value;
        newLast = last->previous;
        free(last);
        last = newLast;
    }
    return result;
}


void mystack::delall()
{
    struct mystackval* newLast;
    while (last != NULL)
    {
        newLast = last->previous;
        free(last);
        last = newLast;
    }
}









