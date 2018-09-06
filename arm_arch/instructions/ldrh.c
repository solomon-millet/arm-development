#include <stdio.h>

/*
	ldr, ldrh, ldrb

	ldrex, ldrhex, ldrbex
*/

int main(void)
{
	int v = 0x95273856;
	int a0, a1;

    __asm__ __volatile__(
        "nop\n"

	"mov r0, %[addv]\n"

	"ldrh %[a0], [r0], #2\n"
	"ldrh %[a1], [r0]\n"	

        "nop\n"

        :[a0]"=&r"(a0),[a1]"=&r"(a1)
        :[addv]"r"(&v)
        :"r0"
    );

    printf("a0 : %#x\n",a0);
    printf("a1 : %#x\n",a1);
   

    return 0;
}
