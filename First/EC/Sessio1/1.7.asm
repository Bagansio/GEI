	.data
	
fib:	.space 40

	.text
	.globl main
	
main:

	li $s0, 2		# i = 2
	la $t0, fib		# $t0 = &fib[0]
	li $t1, 1	
	sw $zero, 0($t0)	# fib[0] = 0
	sw $t1, 4($t0)		# fib[1] = 1
	
while:
	slti $t3, $s0, 10	
	beq $t3, $zero, fi
	
	lw $t1, 0($t0)
	lw $t2, 4($t0)
	addu $t1, $t1, $t2
	
	sw $t1, 8($t0)
	
	addiu $s0, $s0, 1
	addiu $t0, $t0, 4
	b while
fi:
	jr $ra
	