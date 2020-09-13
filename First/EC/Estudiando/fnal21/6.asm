	.data
a:	.byte 'A'
b:	.float 1.5
c:	.half -2,-1,7
d:	.word 0x10010004
	.align 3
e:	.dword -1

	.text
	.globl main
main:

	la $t0, c
	lh $t1, 2($t0)
	lh $t2, 4($t0)
	sll $t2, $t2, 4
	xor $t0, $t1, $t2
	