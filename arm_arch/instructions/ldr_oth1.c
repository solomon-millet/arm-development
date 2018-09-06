#include <stdio.h>

/*
	ldr 作为伪指令的用法一
	将常量放进寄存器:

	ldr register, =const
*/

__asm__ (
	"ar:\n"
		".word 0x9527, 0x7788, 0x3856\n"
);

int main(void)
{
	int a0, a1, a2;

	__asm__ __volatile__(
		"nop\n"
	
		"ldr r0, =ar\n"

		"ldr %[a0], [r0], #4\n"
		"ldr %[a1], [r0], #4\n"
		"ldr %[a2], [r0]\n"

		"nop\n"

		:[a0]"=&r"(a0),[a1]"=&r"(a1),[a2]"=&r"(a2)
		:
		:"r0"

	);

	printf("a0 = %#x\n", a0);
	printf("a1 = %#x\n", a1);
	printf("a2 = %#x\n", a2);

	return 0;
}
