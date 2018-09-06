#include <stdio.h>

/*
   	ldr, ldrh, ldrb
 	str, strh, strb
 */

int main(void)
{
	unsigned int ar = 0; //ar = 0x95273856;

	__asm__ __volatile__(
		"nop\n"

		"mov r0, %[addar]\n"

		"mov r1, #0x56\n"
		"strb r1, [r0],#1\n"

		"mov r1, #0x38\n"
		"strb r1, [r0],#1\n"

		"mov r1, #0x27\n"
		"strb r1, [r0],#1\n"

		"mov r1, #0x95\n"
		"strb r1, [r0]\n"

		"nop\n"

		:
		:[addar]"r"(&ar)
		:"r0","r1"
	);

	printf("ar = %#x\n",ar);

	return 0;
}
