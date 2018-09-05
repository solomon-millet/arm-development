






__asm__ __volatile__(
nop	{0}

mov	r0, r3
mov	r6, r0

mov	r1, r2
mov	r5, r1

mov	r2, r1
mov	r4, r2

nop	{0}

str	r6, [fp, #-36]	; 0x24
str	r5, [fp, #-40]	; 0x28
str	r4, [fp, #-44]	; 0x2c

:[v0]"=r"(v0),[v1]"=r"(v1),[v2]"=r"(v2)
:[a0]"r"(a0),[b0]"r"(b0),[c0]"r"(c0)
);

