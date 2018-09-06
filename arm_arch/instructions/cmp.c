#include <stdio.h>

int main(void)
{
	int a0, a1;
	int val;

	while (1) {
		printf("give two number:");
		if ( scanf("%d %d", &a0, &a1) ==2 ) {
			break;
		}
	}


	__asm__ __volatile__(
		"nop\n"

		"cmp %[a0], %[a1]\n"

		"movgt %[val], #1\n"
		"movlt %[val], #-1\n"
		"moveq %[val], #0\n"

		"nop\n"
		
		:[val]"=&r"(val)
		:[a0]"r"(a0),[a1]"r"(a1)
		:"r0"
	);

	printf("val : %d\n", val);

	return 0;
}
