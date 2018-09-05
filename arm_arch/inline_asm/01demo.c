#include <stdio.h>

int main(void)
{

    asm ("nop\nnop");

    asm (
        "nop\n"
        "nop\n"
    );

    asm volatile (
        "nop\n"
        "nop\n"
    );

    __asm__ __volatile__(
        "nop\n"
        "nop\n" 
    );

    return 0;
}