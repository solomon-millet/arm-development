#include <stdio.h>

int main(void)
{

    int v0 = 0, v1 = 0;
    int a0 = 9527, b0 = 7788;

    __asm__ __volatile__(
        "nop\n"

        "mov %[v0], %[a0]\n"
        "mov %[v1], %[b0]\n"

        "nop\n"

        :[v0]"=r"(v0),[v1]"=r"(v1) 
        :[a0]"r"(a0),[b0]"r"(b0)
    );

    printf("v0 : %d\n", v0);
    printf("v1 : %d\n", v1);

    return 0;
}