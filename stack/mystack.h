#include <stdlib.h>
#include <math.h>

#ifndef MYSTACK
#define MYSTACK

struct mystack
{
    private:
        struct mystackval* last = NULL;
        long numberOfEl;
    public:
        mystack(); //i have to
        double pop();
        int push(double a);
        void delall();
        long getNumberOfEl();
};

struct mystackval;

#endif // MYSTACK
