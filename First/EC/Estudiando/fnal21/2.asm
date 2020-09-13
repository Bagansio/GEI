	.text
	.globl main
main:
	li $t0,  0x40100001
	mtc1 $t0, $f0
	li $t0, 0x3FC00000
	mtc1 $t0, $f4
	mul.s $f2, $f0, $f4