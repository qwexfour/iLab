#include "mystack.h"

/*
struct mystack
{
    struct mystackval* last = NULL;
    int pop();
    void push(int a);
    void delall();
};
*/
struct mystackval
{
    int value;
    struct mystackval* previous = NULL;
};


void mystack::push(int a)
{

    struct mystackval* newEl = (struct mystackval*)calloc(1, sizeof(struct mystackval));
    struct mystackval* before;
    if (last != NULL)
    {
        before = last;
    }
    else
        before = NULL;

    last = newEl;
    newEl->value = a;
    newEl->previous = before;
}



int mystack::pop()
{
    int result;
    struct mystackval* newLast;
    if (last == NULL)
        result = STACK_IS_EMPTY;
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









