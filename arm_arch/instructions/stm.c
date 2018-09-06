#include <stdio.h>

/*
	ldr, ldrh, ldrb

	stm   --> store mul

	increase, decrease   	-> i, d
	after,    before	-> a, b

	stmia, stmib, stmda, stmdb


	stmia r3!, {r0, r1, r2}
*/

int main(void)
{
	int ar[3] = { 0 }; //{9527, 3856, 7788};
	unsigned int p0, p1;

	__asm__ __volatile__(
		"nop\n"

		"mov r0, %[ar]\n"

		"ldr r1, =9527\n"
		"ldr r2, =3856\n"
		"ldr r3, =7788\n"

		"mov %[p0], r0\n"
		"stmia r0!, {r1-r3}\n"
		"mov %[p1], r0\n"

		"nop\n"
		
		:[p0]"=&r"(p0),[p1]"=&r"(p1)
		:[ar]"r"(ar)
		:"r0","r1","r2","r3"
	);

	for (int i = 0; i < 3; i++) {
		printf("ar[%d]: %d\n", i, ar[i]);
	}

	printf("ar : %p\n", ar);
	printf("p0 : %#x\n", p0);
	printf("p1 : %#x\n", p1);

	return 0;
}
