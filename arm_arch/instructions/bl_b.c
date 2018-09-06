#include <stdio.h>

int main(void)
{
	int val;

	__asm__ __volatile__(
		"nop\n"
			"b lable0\n"
		"pc:\n"
			"mov %[val], #200\n"
			"b lable1\n"
		"lable0:\n"
			"b pc\n"
		"lable1:\n"
			"b end\n"
		"nop\n"
		"end:\n"
			"mov %[val], #88\n"
		
		:[val]"=&r"(val)
	);

	printf("val : %d\n", val);

	return 0;
}
