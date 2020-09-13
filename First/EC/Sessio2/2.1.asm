	.text

	.globl main
main:
	li $v0, 5
	syscall		# cin >> x
	move $s0,$v0
	
	li $v0, 5
	syscall		# cin >> y
	move $s1, $v0
	
	li $t0, 1
	sllv $t0, $t0, $s0
	addiu $t0, $t0, -1
	xor $s1, $s1, $t0
	
	li $v0, 1
	move $a0, $s1
	syscall
	
	jr $ra
	