#include <stdio.h>

int main(void)
{
    int a0 = 0xff;

    __asm__ __volatile__(
        "nop\n"

        "mov r0, #0x8\n"
        "sub %[a0], %[a0], r0, lsl #4\n"

        "nop\n"

        :[a0]"+&r"(a0)
        :
        :"r0"
    );

    printf("a0 : %#x\n",a0);
   

    return 0;
}
