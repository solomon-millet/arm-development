#include <stdio.h>

int main(void)
{
	unsigned int curr, pc, nn;

	__asm__ __volatile__(
		"nop\n"
			"ldr %[curr], =pc\n"
		"pc:\n"
			"mov %[pc], pc\n"
		"lable0:\n"
			"ldr %[nn], =lable1\n"
		"lable1:\n"
			"nop\n"

		"nop\n"
		
		:[curr]"=&r"(curr),[pc]"=&r"(pc),[nn]"=&r"(nn)
	);

	printf("curr : %#x\n", curr);
	printf("pc : %#x\n", pc);
	printf("nn : %#x\n", nn);

	return 0;
}
