
APP.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0008 	ldr	r0, [pc, #8]	; 18 <main+0x18>
   c:	ebfffffe 	bl	0 <UART_voidSendString>
  10:	e1a00000 	nop			; (mov r0, r0)
  14:	e8bd8800 	pop	{fp, pc}
  18:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	7261654c 	rsbvc	r6, r1, #76, 10	; 0x13000000
   4:	6e492d6e 	cdpvs	13, 4, cr2, cr9, cr14, {3}
   8:	7065442d 	rsbvc	r4, r5, sp, lsr #8
   c:	203a6874 	eorscs	r6, sl, r4, ror r8
  10:	7473754d 	ldrbtvc	r7, [r3], #-1357	; 0xfffffab3
  14:	20616661 	rsbcs	r6, r1, r1, ror #12
  18:	65666148 	strbvs	r6, [r6, #-328]!	; 0xfffffeb8
  1c:	0000007a 	andeq	r0, r0, sl, ror r0
	...

Disassembly of section .rodata:

00000000 <string_buffer2>:
   0:	7261654c 	rsbvc	r6, r1, #76, 10	; 0x13000000
   4:	6e492d6e 	cdpvs	13, 4, cr2, cr9, cr14, {3}
   8:	7065442d 	rsbvc	r4, r5, sp, lsr #8
   c:	203a6874 	eorscs	r6, sl, r4, ror r8
  10:	7473754d 	ldrbtvc	r7, [r3], #-1357	; 0xfffffab3
  14:	20616661 	rsbcs	r6, r1, r1, ror #12
  18:	65666148 	strbvs	r6, [r6, #-328]!	; 0xfffffeb8
  1c:	0000007a 	andeq	r0, r0, sl, ror r0
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	0000008d 	andeq	r0, r0, sp, lsl #1
   4:	00000004 	andeq	r0, r0, r4
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	00000038 	andeq	r0, r0, r8, lsr r0
  10:	0000c10c 	andeq	ip, r0, ip, lsl #2
  14:	00009900 	andeq	r9, r0, r0, lsl #18
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001c00 	andeq	r1, r0, r0, lsl #24
  20:	00000000 	andeq	r0, r0, r0
  24:	003c0200 	eorseq	r0, ip, r0, lsl #4
  28:	00350000 	eorseq	r0, r5, r0
  2c:	35030000 	strcc	r0, [r3, #-0]
  30:	63000000 	movwvs	r0, #0
  34:	07040400 	streq	r0, [r4, -r0, lsl #8]
  38:	0000002b 	andeq	r0, r0, fp, lsr #32
  3c:	0f080104 	svceq	0x00080104
  40:	05000000 	streq	r0, [r0, #-0]
  44:	0000003c 	andeq	r0, r0, ip, lsr r0
  48:	00001d06 	andeq	r1, r0, r6, lsl #26
  4c:	25040100 	strcs	r0, [r4, #-256]	; 0xffffff00
  50:	05000000 	streq	r0, [r0, #-0]
  54:	00000003 	andeq	r0, r0, r3
  58:	00430200 	subeq	r0, r3, r0, lsl #4
  5c:	00690000 	rsbeq	r0, r9, r0
  60:	35030000 	strcc	r0, [r3, #-0]
  64:	63000000 	movwvs	r0, #0
  68:	00590500 	subseq	r0, r9, r0, lsl #10
  6c:	00060000 	andeq	r0, r6, r0
  70:	01000000 	mrseq	r0, (UNDEF: 0)
  74:	00006905 	andeq	r6, r0, r5, lsl #18
  78:	00030500 	andeq	r0, r3, r0, lsl #10
  7c:	07000000 	streq	r0, [r0, -r0]
  80:	000000c7 	andeq	r0, r0, r7, asr #1
  84:	00000701 	andeq	r0, r0, r1, lsl #14
  88:	001c0000 	andseq	r0, ip, r0
  8c:	9c010000 	stcls	0, cr0, [r1], {-0}
	...

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0xfffffeff
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10061201 	andne	r1, r6, r1, lsl #4
  10:	02000017 	andeq	r0, r0, #23
  14:	13490101 	movtne	r0, #37121	; 0x9101
  18:	00001301 	andeq	r1, r0, r1, lsl #6
  1c:	49002103 	stmdbmi	r0, {r0, r1, r8, sp}
  20:	000b2f13 	andeq	r2, fp, r3, lsl pc
  24:	00240400 	eoreq	r0, r4, r0, lsl #8
  28:	0b3e0b0b 	bleq	f82c5c <main+0xf82c5c>
  2c:	00000e03 	andeq	r0, r0, r3, lsl #28
  30:	49002605 	stmdbmi	r0, {r0, r2, r9, sl, sp}
  34:	06000013 			; <UNDEFINED> instruction: 0x06000013
  38:	0e030034 	mcreq	0, 0, r0, cr3, cr4, {1}
  3c:	0b3b0b3a 	bleq	ec2d2c <main+0xec2d2c>
  40:	193f1349 	ldmdbne	pc!, {r0, r3, r6, r8, r9, ip}	; <UNPREDICTABLE>
  44:	00001802 	andeq	r1, r0, r2, lsl #16
  48:	3f002e07 	svccc	0x00002e07
  4c:	3a0e0319 	bcc	380cb8 <main+0x380cb8>
  50:	270b3b0b 	strcs	r3, [fp, -fp, lsl #22]
  54:	12011119 	andne	r1, r1, #1073741830	; 0x40000006
  58:	96184006 	ldrls	r4, [r8], -r6
  5c:	00001942 	andeq	r1, r0, r2, asr #18
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	0000001c 	andeq	r0, r0, ip, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e505041 	cdpcs	0, 5, cr5, cr0, cr1, {2}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	504f1900 	subpl	r1, pc, r0, lsl #18
  30:	01000602 	tsteq	r0, r2, lsl #12
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69727473 	ldmdbvs	r2!, {r0, r1, r4, r5, r6, sl, ip, sp, lr}^
   4:	625f676e 	subsvs	r6, pc, #28835840	; 0x1b80000
   8:	65666675 	strbvs	r6, [r6, #-1653]!	; 0xfffff98b
   c:	75003272 	strvc	r3, [r0, #-626]	; 0xfffffd8e
  10:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  14:	2064656e 	rsbcs	r6, r4, lr, ror #10
  18:	72616863 	rsbvc	r6, r1, #6488064	; 0x630000
  1c:	72747300 	rsbsvc	r7, r4, #0, 6
  20:	5f676e69 	svcpl	0x00676e69
  24:	66667562 	strbtvs	r7, [r6], -r2, ror #10
  28:	75007265 	strvc	r7, [r0, #-613]	; 0xfffffd9b
  2c:	6769736e 	strbvs	r7, [r9, -lr, ror #6]!
  30:	2064656e 	rsbcs	r6, r4, lr, ror #10
  34:	00746e69 	rsbseq	r6, r4, r9, ror #28
  38:	20554e47 	subscs	r4, r5, r7, asr #28
  3c:	20313143 	eorscs	r3, r1, r3, asr #2
  40:	2e322e37 	mrccs	14, 1, r2, cr2, cr7, {1}
  44:	30322031 	eorscc	r2, r2, r1, lsr r0
  48:	39303731 	ldmdbcc	r0!, {r0, r4, r5, r8, r9, sl, ip, sp}
  4c:	28203430 	stmdacs	r0!, {r4, r5, sl, ip, sp}
  50:	656c6572 	strbvs	r6, [ip, #-1394]!	; 0xfffffa8e
  54:	29657361 	stmdbcs	r5!, {r0, r5, r6, r8, r9, ip, sp, lr}^
  58:	52415b20 	subpl	r5, r1, #32, 22	; 0x8000
  5c:	6d652f4d 	stclvs	15, cr2, [r5, #-308]!	; 0xfffffecc
  60:	64646562 	strbtvs	r6, [r4], #-1378	; 0xfffffa9e
  64:	372d6465 	strcc	r6, [sp, -r5, ror #8]!
  68:	6172622d 	cmnvs	r2, sp, lsr #4
  6c:	2068636e 	rsbcs	r6, r8, lr, ror #6
  70:	69766572 	ldmdbvs	r6!, {r1, r4, r5, r6, r8, sl, sp, lr}^
  74:	6e6f6973 			; <UNDEFINED> instruction: 0x6e6f6973
  78:	35353220 	ldrcc	r3, [r5, #-544]!	; 0xfffffde0
  7c:	5d343032 	ldcpl	0, cr3, [r4, #-200]!	; 0xffffff38
  80:	636d2d20 	cmnvs	sp, #32, 26	; 0x800
  84:	613d7570 	teqvs	sp, r0, ror r5
  88:	32396d72 	eorscc	r6, r9, #7296	; 0x1c80
  8c:	2d6a6536 	cfstr64cs	mvdx6, [sl, #-216]!	; 0xffffff28
  90:	672d2073 			; <UNDEFINED> instruction: 0x672d2073
  94:	304f2d20 	subcc	r2, pc, r0, lsr #26
  98:	5c3a4400 	cfldrspl	mvf4, [sl], #-0
  9c:	455f534b 	ldrbmi	r5, [pc, #-843]	; fffffd59 <main+0xfffffd59>
  a0:	6e555c53 	mrcvs	12, 2, r5, cr5, cr3, {2}
  a4:	5f337469 	svcpl	0x00337469
  a8:	7373654c 	cmnvc	r3, #76, 10	; 0x13000000
  ac:	5f326e6f 	svcpl	0x00326e6f
  b0:	65626d45 	strbvs	r6, [r2, #-3397]!	; 0xfffff2bb
  b4:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  b8:	4c5c435f 	mrrcmi	3, 5, r4, ip, cr15
  bc:	315f4241 	cmpcc	pc, r1, asr #4
  c0:	50504100 	subspl	r4, r0, r0, lsl #2
  c4:	6d00632e 	stcvs	3, cr6, [r0, #-184]	; 0xffffff48
  c8:	006e6961 	rsbeq	r6, lr, r1, ror #18

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	5420554e 	strtpl	r5, [r0], #-1358	; 0xfffffab2
   c:	736c6f6f 	cmnvc	ip, #444	; 0x1bc
  10:	726f6620 	rsbvc	r6, pc, #32, 12	; 0x2000000
  14:	6d724120 	ldfvse	f4, [r2, #-128]!	; 0xffffff80
  18:	626d4520 	rsbvs	r4, sp, #32, 10	; 0x8000000
  1c:	65646465 	strbvs	r6, [r4, #-1125]!	; 0xfffffb9b
  20:	72502064 	subsvc	r2, r0, #100	; 0x64
  24:	7365636f 	cmnvc	r5, #-1140850687	; 0xbc000001
  28:	73726f73 	cmnvc	r2, #460	; 0x1cc
  2c:	322d3720 	eorcc	r3, sp, #32, 14	; 0x800000
  30:	2d373130 	ldfcss	f3, [r7, #-192]!	; 0xffffff40
  34:	6d2d3471 	cfstrsvs	mvf3, [sp, #-452]!	; 0xfffffe3c
  38:	726f6a61 	rsbvc	r6, pc, #397312	; 0x61000
  3c:	2e372029 	cdpcs	0, 3, cr2, cr7, cr9, {1}
  40:	20312e32 	eorscs	r2, r1, r2, lsr lr
  44:	37313032 			; <UNDEFINED> instruction: 0x37313032
  48:	34303930 	ldrtcc	r3, [r0], #-2352	; 0xfffff6d0
  4c:	65722820 	ldrbvs	r2, [r2, #-2080]!	; 0xfffff7e0
  50:	7361656c 	cmnvc	r1, #108, 10	; 0x1b000000
  54:	5b202965 	blpl	80a5f0 <main+0x80a5f0>
  58:	2f4d5241 	svccs	0x004d5241
  5c:	65626d65 	strbvs	r6, [r2, #-3429]!	; 0xfffff29b
  60:	64656464 	strbtvs	r6, [r5], #-1124	; 0xfffffb9c
  64:	622d372d 	eorvs	r3, sp, #11796480	; 0xb40000
  68:	636e6172 	cmnvs	lr, #-2147483620	; 0x8000001c
  6c:	65722068 	ldrbvs	r2, [r2, #-104]!	; 0xffffff98
  70:	69736976 	ldmdbvs	r3!, {r1, r2, r4, r5, r6, r8, fp, sp, lr}^
  74:	32206e6f 	eorcc	r6, r0, #1776	; 0x6f0
  78:	30323535 	eorscc	r3, r2, r5, lsr r5
  7c:	Address 0x0000007c is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	0000001c 	andeq	r0, r0, ip, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0xfffffdc7
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0xfffffef7
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.

