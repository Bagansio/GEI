.data

A: .word    2,-1,-1,-2, 0,
            1,-4, 0, 0, 1,
            1, 2, 8, 2,-2,
            0, 4,-2, 3, 0                                                                    

.text
.globl main
main:
	li $t0, 3	# $t0 = i = 3
	li $t6, 5

for_i:
	blt $t0, $zero, endi    # $t0 < 0
	move $t1, $zero		# $t1 = j = 0
	la $t4, A		
	move $t5, $t4
	sll $t2, $t0, 2		
	addu $t4, $t4, $t2	# $t4 = &A[0][i]
	mult $t6, $t2
	mflo $t2
	addu $t5, $t5, $t2	# $t5 = &A[i][0]
	
for_j:				# $t2 = tmp
	ble $t0, $t1, endj
	lw $t2, 0($t5)		# A[i][j]
	bne $t2, $zero, endif
	#sll $t2, $t2, 2	no cal ja que si arribem aqui A[i][j] = 0 -> 0*4 = 0
	lw $t2, 0($t4)
	# addu $t2, $t2, $t3	no cal ja que podem carregar directament A[j][i] a tmp perque 0 + A[j][i] = A[j][i]

endif:				# No cal fer l'else perque $t2 = tmp = A[i][j]
	sw $t2, 0($t4)
	addiu $t4, $t4, 20
	addiu $t5, $t5, 4
	addiu $t1, $t1, 1
	b for_j
endj:

	addiu $t0, $t0, -1
	b for_i
endi:
      jr  $ra 

