#include <stdio.h>

int main(void)
{
	int val, bit;
	int rel;

	printf("give a hex value and a number:");
	scanf("%x %d", &val, &bit);


	__asm__ __volatile__(
		"nop\n"

		"tst %[val], %[bit]\n"
		"moveq %[rel], #1\n"
		"movne %[rel], #0\n"	

		"nop\n"
		
		:[rel]"=&r"(rel)
		:[val]"r"(val),[bit]"r"(bit)
		:"r0"
	);

	printf("rel : %d\n", rel);

	return 0;
}
