#include <stdio.h>

int main(void)
{
    int a0 = 3;

    __asm__ __volatile__(
        "nop\n"

        "mvn r0, #0\n"
        "adds %[a0], %[a0], r0\n"
    
        "adc %[a0], %[a0], #1\n"

        "nop\n"

        :[a0]"+&r"(a0)
        :
        :"r0"
    );

    printf("a0 : %d\n",a0);
   

    return 0;
}
