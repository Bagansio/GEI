

	.text
	
func:
	addiu $sp, $sp, -16
	sw $ra, 4($sp)
	sw $s0, 8($sp)
	sw $s1, 12($sp)
	
	move $s0, $a0
	move $s1, $a1
	sw $zero, 0($sp)
	li $v0, 0	# x = 0
	li $a1, 0	# y = 0
while:
	bge $v0, $s1, endwhile
	move $a0, $s0
	jal sub1
	
	move $a0, $v0
	jal sub2
	b while
endwhile: