#include <stdio.h>

int main(void)
{
	int val0, val1;
	int rel;

	printf("give two number:");
	scanf("%d %d", &val0, &val1);


	__asm__ __volatile__(
		"nop\n"

		"teq %[val0], %[val1]\n"
		"moveq %[rel], #1\n"
		"movne %[rel], #0\n"	

		"nop\n"
		
		:[rel]"=&r"(rel)
		:[val0]"r"(val0),[val1]"r"(val1)
		:"r0"
	);

	printf("rel : %d\n", rel);

	return 0;
}
