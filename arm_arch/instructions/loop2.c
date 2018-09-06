#include <stdio.h>

size_t westrlen(const char *s)
{
	size_t ret = 0;

	__asm__ __volatile__(
		
		"mov r0, %[s]\n"

		"loop:\n"	
			"ldrb r1, [r0], #1\n"
			"cmp r1, #0\n"
			"beq end\n"
			"add %[ret], #1\n"
		"b loop\n"

		"end:\n"

		:[ret]"+&r"(ret)
		:[s]"r"(s)
		:"r0","r1"
	);

	return ret;
}

int main(void)
{
#define SZ 1024
	char buf[SZ];

	printf("give a string:");
	fgets(buf, SZ, stdin);

	printf("your string has %dBytes.\n", westrlen(buf));

	return 0;
}
