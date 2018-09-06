#include <stdio.h>

int main(void)
{
	int val;

	__asm__ __volatile__(
		"nop\n"

		"mvn r0, #0x0\n"

		"cmn r0, #0x20\n"

		"movcs %[val], #1\n"
		"movcc %[val], #-1\n"

		"nop\n"
		
		:[val]"=&r"(val)
		:
		:"r0"
	);

	printf("val : %d\n", val);

	return 0;
}
