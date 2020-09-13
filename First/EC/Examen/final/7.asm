	.data
a:	.asciiz "AaBb"
b:	.half	266,-9
c:	.word 345
d:	.byte '3'
e:	.word 0x10010008
	.text
	.globl main
main:
	la $t0, e
	lw $t1, 0($t0)
	lh $t2, 0($t1)
	lh $t3, -2($t1)
	xor $t1, $t2,$t3