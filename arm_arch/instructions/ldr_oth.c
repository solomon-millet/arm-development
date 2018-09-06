#include <stdio.h>

/*
	ldr 作为伪指令的用法一
	将常量放进寄存器:

	ldr register, =const
*/

int main(void)
{
	__asm__ __volatile__(
		"nop\n"
		"ldr r0, =0xf00f\n"  //0xff00 -> 0xff000000
		"nop\n"

	);

	return 0;
}
