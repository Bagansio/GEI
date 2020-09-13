main:
	la $t2, M
	la $t3, I
	li $t0, 0
	li $t1, 100
	move $t2, $t6
for: bge $t0, $t1, fifor
	lw $t4, 0($t3)
	mult $t4, $t1
	mflo $t5
	addu $t5, $t4, $t5
	sll $t5, $t5, 2
	addu $t5, $t5, $t2
	lw $t4, 0($t6)
	sw $t4, 0($t5)
	addiu $t6, $t6, 404
	addiu $t3, $t3, 4
	addiu $t0, $t0, 1
	b for
fifor: jr $ra