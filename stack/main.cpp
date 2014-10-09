#include <stdio.h>
#include "mystack.h"

int main()
{
    int i;
    struct mystack st;
    for (i = 0; i < 10; i++)
        st.push(i);
    for (i = 0; i < 5; i++)
        printf("%i ",st.pop());
    printf("\n");


    for (i = 0; i < 10; i++)
        st.push(i);
    for (i = 0; i < 16; i++)
        printf("%i ",st.pop());
    printf("\n");


    st.delall();
    st.push(123);
    printf("%i ",st.pop());
    printf("%i ",st.pop());
    return 0;
}
