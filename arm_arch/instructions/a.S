
a.out:     file format elf32-littlearm


Disassembly of section .init:

00008290 <_init>:
    8290:	e92d4008 	push	{r3, lr}
    8294:	eb00001d 	bl	8310 <call_gmon_start>
    8298:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

0000829c <.plt>:
    829c:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
    82a0:	e59fe004 	ldr	lr, [pc, #4]	; 82ac <_init+0x1c>
    82a4:	e08fe00e 	add	lr, pc, lr
    82a8:	e5bef008 	ldr	pc, [lr, #8]!
    82ac:	00008d54 	.word	0x00008d54
    82b0:	e28fc600 	add	ip, pc, #0
    82b4:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82b8:	e5bcfd54 	ldr	pc, [ip, #3412]!	; 0xd54
    82bc:	e28fc600 	add	ip, pc, #0
    82c0:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82c4:	e5bcfd4c 	ldr	pc, [ip, #3404]!	; 0xd4c
    82c8:	e28fc600 	add	ip, pc, #0
    82cc:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82d0:	e5bcfd44 	ldr	pc, [ip, #3396]!	; 0xd44

Disassembly of section .text:

000082d4 <_start>:
    82d4:	e3a0b000 	mov	fp, #0
    82d8:	e3a0e000 	mov	lr, #0
    82dc:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    82e0:	e1a0200d 	mov	r2, sp
    82e4:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
    82e8:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
    82ec:	e59fc010 	ldr	ip, [pc, #16]	; 8304 <_start+0x30>
    82f0:	e52dc004 	push	{ip}		; (str ip, [sp, #-4]!)
    82f4:	e59f000c 	ldr	r0, [pc, #12]	; 8308 <_start+0x34>
    82f8:	e59f300c 	ldr	r3, [pc, #12]	; 830c <_start+0x38>
    82fc:	ebffffee 	bl	82bc <_init+0x2c>
    8300:	ebffffea 	bl	82b0 <_init+0x20>
    8304:	00008414 	.word	0x00008414
    8308:	00008380 	.word	0x00008380
    830c:	000083ac 	.word	0x000083ac

00008310 <call_gmon_start>:
    8310:	e59f3014 	ldr	r3, [pc, #20]	; 832c <call_gmon_start+0x1c>
    8314:	e59f2014 	ldr	r2, [pc, #20]	; 8330 <call_gmon_start+0x20>
    8318:	e08f3003 	add	r3, pc, r3
    831c:	e7932002 	ldr	r2, [r3, r2]
    8320:	e3520000 	cmp	r2, #0
    8324:	012fff1e 	bxeq	lr
    8328:	eaffffe6 	b	82c8 <_init+0x38>
    832c:	00008ce0 	.word	0x00008ce0
    8330:	00000018 	.word	0x00000018

00008334 <__do_global_dtors_aux>:
    8334:	e59f3010 	ldr	r3, [pc, #16]	; 834c <__do_global_dtors_aux+0x18>
    8338:	e5d32000 	ldrb	r2, [r3]
    833c:	e3520000 	cmp	r2, #0
    8340:	03a02001 	moveq	r2, #1
    8344:	05c32000 	strbeq	r2, [r3]
    8348:	e12fff1e 	bx	lr
    834c:	00011024 	.word	0x00011024

00008350 <frame_dummy>:
    8350:	e59f0020 	ldr	r0, [pc, #32]	; 8378 <frame_dummy+0x28>
    8354:	e92d4008 	push	{r3, lr}
    8358:	e5903000 	ldr	r3, [r0]
    835c:	e3530000 	cmp	r3, #0
    8360:	08bd8008 	popeq	{r3, pc}
    8364:	e59f3010 	ldr	r3, [pc, #16]	; 837c <frame_dummy+0x2c>
    8368:	e3530000 	cmp	r3, #0
    836c:	08bd8008 	popeq	{r3, pc}
    8370:	e12fff33 	blx	r3
    8374:	e8bd8008 	pop	{r3, pc}
    8378:	00010f14 	.word	0x00010f14
    837c:	00000000 	.word	0x00000000

00008380 <main>:
#include <stdio.h>

int main(void)
{
    8380:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
    8384:	e28db000 	add	fp, sp, #0
	__asm__ __volatile__(
    8388:	e320f000 	nop	{0}
    838c:	e59f0014 	ldr	r0, [pc, #20]	; 83a8 <main+0x28>
    8390:	e320f000 	nop	{0}
		"ldr r0, =0xf00f\n"  //0xff00 -> 0xff000000
		"nop\n"

	);

	return 0;
    8394:	e3a03000 	mov	r3, #0
}
    8398:	e1a00003 	mov	r0, r3
    839c:	e28bd000 	add	sp, fp, #0
    83a0:	e8bd0800 	pop	{fp}
    83a4:	e12fff1e 	bx	lr
    83a8:	0000f00f 	.word	0x0000f00f

000083ac <__libc_csu_init>:
    83ac:	e92d45f8 	push	{r3, r4, r5, r6, r7, r8, sl, lr}
    83b0:	e59f5050 	ldr	r5, [pc, #80]	; 8408 <__libc_csu_init+0x5c>
    83b4:	e59fa050 	ldr	sl, [pc, #80]	; 840c <__libc_csu_init+0x60>
    83b8:	e1a06000 	mov	r6, r0
    83bc:	e1a07001 	mov	r7, r1
    83c0:	e1a08002 	mov	r8, r2
    83c4:	ebffffb1 	bl	8290 <_init>
    83c8:	e59f3040 	ldr	r3, [pc, #64]	; 8410 <__libc_csu_init+0x64>
    83cc:	e065a00a 	rsb	sl, r5, sl
    83d0:	e08f3003 	add	r3, pc, r3
    83d4:	e1b0a14a 	asrs	sl, sl, #2
    83d8:	e0835005 	add	r5, r3, r5
    83dc:	08bd85f8 	popeq	{r3, r4, r5, r6, r7, r8, sl, pc}
    83e0:	e3a04000 	mov	r4, #0
    83e4:	e4953004 	ldr	r3, [r5], #4
    83e8:	e1a00006 	mov	r0, r6
    83ec:	e1a01007 	mov	r1, r7
    83f0:	e1a02008 	mov	r2, r8
    83f4:	e2844001 	add	r4, r4, #1
    83f8:	e12fff33 	blx	r3
    83fc:	e154000a 	cmp	r4, sl
    8400:	3afffff7 	bcc	83e4 <__libc_csu_init+0x38>
    8404:	e8bd85f8 	pop	{r3, r4, r5, r6, r7, r8, sl, pc}
    8408:	ffffff0c 	.word	0xffffff0c
    840c:	ffffff10 	.word	0xffffff10
    8410:	00008c28 	.word	0x00008c28

00008414 <__libc_csu_fini>:
    8414:	e12fff1e 	bx	lr

Disassembly of section .fini:

00008418 <_fini>:
    8418:	e92d4008 	push	{r3, lr}
    841c:	e8bd8008 	pop	{r3, pc}
