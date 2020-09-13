	.data
	
cadena:	.byte	-1,-1,-1,-1,-1,-1
	.align 2
vec:	.word	5,6,8,9,1

	.text
	.globl main
main:
	move	$s0, $zero		# i = 0
	la $t0, cadena
	la $t1, vec			
	addiu $t1, $t1, 16		# vec = $t1
	
while: 	
	li	$t5,5
	bge 	$s0, $t5, fi
	
	lb $t2, 0($t1)
	addiu $t2, $t2, '0'
	sb $t2, 0($t0)
	
	addiu $t0, $t0, 1		# cadena[i++]
	addiu $t1, $t1, -4		# vec[i--]
	addiu $s0, $s0, 1
	b while
fi:
	sb $zero, 0($t0)
	
	li $v0, 4
	la $a0, cadena
	syscall
	
	jr $ra
	