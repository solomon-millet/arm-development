#include <stdio.h>

/*
	ldr, ldrh, ldrb

	ldm   --> load mul

	increase, decrease   	-> i, d
	after,    before	-> a, b

	ldmia, ldmib, ldmda, ldmdb


	ldmia r3!, {r0, r1, r2}
*/

int main(void)
{
	int ar[] = {9527, 3856, 7788};
	int a0, a1, a2;

	__asm__ __volatile__(
		"nop\n"

		"mov r0, %[ar]\n"

		"ldmia r0!, {r1, r2, r3}\n"

		"mov %[a0], r1\n"
		"mov %[a1], r2\n"
		"mov %[a2], r3\n"

		"nop\n"
		
		:[a0]"=&r"(a0),[a1]"=&r"(a1),[a2]"=&r"(a2)
		:[ar]"r"(ar)
		:"r0","r1","r2","r3"
	);

	printf("a0 : %d\n", a0);
	printf("a1 : %d\n", a1);
	printf("a2 : %d\n", a2);

	return 0;
}
