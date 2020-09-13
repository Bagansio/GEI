	.data
a:	.half 0x6543
b:	.half -16
	.text
	.globl main
main:
	la $t0, a
	lh $t0, 0($t0)
	la $t1, b
	lh $t1, 0($t1)
	
	  