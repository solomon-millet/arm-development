#include <stdio.h>

int main(void)
{
	union {
		unsigned int a;
		unsigned char b;
	}v = {.a = 0x95273856};

	if (v.b == 0x56) {
		printf("little-endian.\n");
	} else if (v.b == 0x95) {
		printf("big-endian.\n");
	}

	return 0;
}
