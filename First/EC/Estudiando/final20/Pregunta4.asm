	.data
a: .word 0xC27f8000
b: .word 0xc07c8000
c: .float 1.0

	.text
	.globl main
main:
	la $t0, a
	lwc1 $f0, 0($t0)
	la $t0, b
	lwc1 $f2, 0($t0)
	add.s $f6, $f0, $f2

