#include <stdio.h>

int main(void)
{
	int l, r;
	int sum = 0;

	while (1) {
		printf("give two number:");
		scanf("%d %d", &l, &r);
		if (l <= r) {
			break;
		}
	}
	

	__asm__ __volatile__(

		"mov r0, %[l]\n"

		"for:\n"
			"cmp r0, %[r]\n"
			"bgt end\n"
			"add %[sum], r0\n"
			"add r0, #1\n"
		"b for\n"

		"end:\n"

		:[sum]"+&r"(sum)
		:[l]"r"(l),[r]"r"(r)
	);

	printf("sum : %d\n", sum);

	return 0;
}
