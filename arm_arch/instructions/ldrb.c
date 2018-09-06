#include <stdio.h>

/*
   ldr, ldrh, ldrb
 */

int main(void)
{
	int v = 0x95273856;
	int a0, a1, a2, a3;

	__asm__ __volatile__(
		"nop\n"

		"mov r0, %[addv]\n"
		"ldrb %[a0], [r0],#1\n"
		"ldrb %[a1], [r0],#1\n"
		"ldrb %[a2], [r0],#1\n"
		"ldrb %[a3], [r0]\n"


		"nop\n"

		:[a0]"=&r"(a0),[a1]"=&r"(a1),[a2]"=&r"(a2),[a3]"=&r"(a3)
		:[addv]"r"(&v)
		:"r0"
	);

	printf("a0 : %#x\n",a0);
	printf("a1 : %#x\n",a1);
	printf("a2 : %#x\n",a2);
	printf("a3 : %#x\n",a3);

	return 0;
}
