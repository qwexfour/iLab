#include <stdio.h>
#include "mystack.h"

int main()
{
    int i;
    struct mystack st;


    printf("Number of el is %i\nEls are ", st.getNumberOfEl());
    for (i = 0; i < 10; i++)
        st.push(i);
    for (i = 0; i < 5; i++)
        printf("%lg ",st.pop());
    printf("\n");

    printf("Number of el is %i\nEls are ", st.getNumberOfEl());
    for (i = 0; i < 10; i++)
        st.push(i);
    for (i = 0; i < 16; i++)
        printf("%lg ",st.pop());
    printf("\n");

    printf("Number of el is %i\nEls are ", st.getNumberOfEl());
    st.delall();
    st.push(123);
    printf("%lg ",st.pop());
    printf("%lg ",st.pop());
    printf("Number of el is %i", st.getNumberOfEl());
    return 0;
}
