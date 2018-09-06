#include <stdio.h>

/*
   	ldr, ldrh, ldrb
 	str, strh, strb
 */

int main(void)
{
	int ar[3] = { 0 };

	__asm__ __volatile__(
		"nop\n"

		"mov r0, %[ar]\n"

		"ldr r1, =0x9527\n" //ldr伪指令的用法
		"str r1, [r0], #4\n"

		"ldr r1, =0x3856\n" //ldr伪指令的用法
		"str r1, [r0], #4\n"
	
		"ldr r1, =0x7788\n" //ldr伪指令的用法
		"str r1, [r0]\n"

		"nop\n"

		:
		:[ar]"r"(ar)
		:"r0","r1"
	);

	for (int i = 0; i < 3; i++) {
		printf("ar[%d] = %#x\n",i, ar[i]);
	}

	return 0;
}
