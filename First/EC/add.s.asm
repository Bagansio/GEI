.text
.globl main

main:
	li $t0, 0x43C5C021
	mtc1 $t0, $f0
	li $t0, 0x43C04000
	mtc1 $t0, $f4
	
	sub.s $f2, $f0, $f4
	