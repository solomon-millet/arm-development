#include <stdio.h>

int main(void)
{
	int a0, a1, a2;

	while (1) {
		printf("give three number:");
		if ( scanf("%d %d %d", &a0, &a1, &a2) == 3 ) {
			break;
		}
	}


	__asm__ __volatile__(
		"nop\n"

		"cmp %[a0], %[a1]\n"
		"movlt r0, %[a0]\n"
		"movlt %[a0], %[a1]\n"
		"movlt %[a1], r0\n"

		"cmp %[a0], %[a2]\n"
		"movlt r0, %[a0]\n"
		"movlt %[a0], %[a2]\n"
		"movlt %[a2], r0\n"

		"cmp %[a1], %[a2]\n"
		"movlt r0, %[a1]\n"
		"movlt %[a1], %[a2]\n"
		"movlt %[a2], r0\n"

		"nop\n"
		
		:[a0]"+&r"(a0),[a1]"+&r"(a1),[a2]"+&r"(a2)
		:
		:"r0"
	);

	printf("%d >= %d >= %d\n", a0, a1, a2);

	return 0;
}
