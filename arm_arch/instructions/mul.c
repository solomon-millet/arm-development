#include <stdio.h>

int main(void)
{
    int a0 = 3;

    __asm__ __volatile__(
        "nop\n"

        "mov r0, #75\n"
    
        "mul %[a0], r0, r0\n"

        "nop\n"

        :[a0]"+&r"(a0)
        :
        :"r0"
    );

    printf("a0 : %d\n",a0);
   

    return 0;
}
