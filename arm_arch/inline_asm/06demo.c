#include <stdio.h>

int main(void)
{
    int a0 = 9527, b0 = 7788, c0 = 1324;
    int v0, v1, v2;

    __asm__ __volatile__(
        "nop\n"

        "mov r0, %[a0]\n"
        "mov %[v0], r0\n"

        "mov r1, %[b0]\n"
        "mov %[v1], r1\n"

        "mov r2, %[c0]\n"
        "mov %[v2], r2\n"

        "nop\n"

        :[v0]"=&r"(v0),[v1]"=&r"(v1),[v2]"=&r"(v2)
        :[a0]"r"(a0),[b0]"r"(b0),[c0]"r"(c0)
        :"r0","r1","r2"
    );

    printf("v0 : %d\n", v0);
    printf("v1 : %d\n", v1);
    printf("v2 : %d\n", v2);

    return 0;
}