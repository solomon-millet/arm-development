#include <stdio.h>

int main(void)
{
    int a0 = 9527, b0 = 7788;

    printf("a0 : %d\n", a0);
    printf("b0 : %d\n", b0);

    __asm__ __volatile__(
        "nop\n"

        "mov r0, %[a0]\n"
        "mov %[a0], %[b0]\n"
        "mov %[b0], r0\n"

        "nop\n"

        :[a0]"+r"(a0),[b0]"+r"(b0)
    );a

    printf("a0 : %d\n", a0);
    printf("b0 : %d\n", b0);

    return 0;
}