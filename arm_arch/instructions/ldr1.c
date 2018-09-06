#include <stdio.h>

/*
	ldr, ldrh, ldrb

	ldrex, ldrhex, ldrbex
*/

int main(void)
{
    	int ar[] = {9527, 7788, 1956};  //ar[2] --> *(ar + 2)
	int a0, a1, a2;

    __asm__ __volatile__(
        "nop\n"
	
	"mov r0, %[ar]\n"

	"ldr %[a0], [r0]\n"
	"ldr %[a1], [r0,#4]\n"  //
	"ldr %[a2], [r0,#8]\n"  //
	

        "nop\n"

        :[a0]"=&r"(a0),[a1]"=&r"(a1),[a2]"=&r"(a2)
        :[ar]"r"(ar)
        :"r0"
    );

    printf("a0 : %d\n",a0);
    printf("a1 : %d\n",a1);
    printf("a2 : %d\n",a2);
   

    return 0;
}
