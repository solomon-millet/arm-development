#include <stdio.h>

int main(void)
{
   int and, orr, eor;

    __asm__ __volatile__(
        "nop\n"

        "mov r0, #0x98\n"
        "and %[and], r0, #~(1 << 7)\n"
        "orr %[orr], r0, #0x7\n"
        "eor %[eor], r0, #0x89\n"
        /*
            1001 1000
            1000 1001
            -----------
            0001 0001    -> 0x11
        */

        "nop\n"

        :[and]"=&r"(and),[orr]"=&r"(orr),[eor]"=&r"(eor)
        :
        :"r0"
    );

    printf("and : %#x\n",and);
    printf("orr : %#x\n",orr);
    printf("eor : %#x\n",eor);


    return 0;
}
