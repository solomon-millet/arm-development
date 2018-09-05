#include <stdio.h>

int main(void)
{

    int v0 = 0, v1 = 0;

    __asm__ __volatile__(
        "nop\n"

        "mov %0, #200\n"
        "mov %1, #111\n"

        "nop\n"

        :"=r"(v0),"=r"(v1) 
    );

    printf("v0 : %d\n", v0);
    printf("v1 : %d\n", v1);

    return 0;
}