#include <stdio.h>

/*
   	ldr, ldrh, ldrb
 	str, strh, strb
 */

int main(void)
{
	__asm__ __volatile__(
		"nop\n"
		"mov r0, #0xff00\n"  //0xff00 -> 0xff000000
		"nop\n"

	);

	return 0;
}
