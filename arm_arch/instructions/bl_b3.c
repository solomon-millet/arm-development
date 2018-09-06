#include <stdio.h>

void func(void)
{
	printf("who are you?\n");
} //mov pc, lr

int main(void)
{
	__asm__ __volatile__(
		"nop\n"
		"mov lr, pc\n"
		"ldr pc, =func\n"
		//"bl func\n"
		"nop\n"
	);

	printf("come back...\n");

	return 0;
}
