	.data

A:	.word 3,5,7
punter:	.word	0

	.text
	.globl main
main:
	la $t0, A
	la $t1, punter
	addiu $t0, $t0, 8
	sw $t0, 0($t1)
	
	lw $s0, 0($t0)
	addiu $s0, $s0, 2
	
	lw $t1, -8($t0)
	addu $s0, $s0, $t1
	
	sw $s0, -4($t0)  
	
	li $v0, 1
	move $a0, $s0
	syscall
	
	jr $ra
	
	
#EXERCICI 1.6
	#la $s1, vec
	#sll $t0, $s2, 2
	#addu $s1, $s1, $t0
	#lw $s1, 0($s1)