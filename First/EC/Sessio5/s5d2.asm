	.data	
V1:     .space  64
M:      .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
        .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
V2:     .word   -5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10

	.text
	.globl main
main:
	li $t0, 0		# $t0 = k
	li $t1, 4
	li $t2, 16

for_k:
	bge $t0, $t1, endk
	li $t3, 0		# $t3 = i
	la $s0, V1
for_i:
	bge $t3, $t2, endi
	li $t4, 0		# $t4 = tmp
	li $t5, 0		# $t5 = j
	
	sll $t6, $t0,4		#k * 4
	la $t7, M		# M[0][0]
	la $t9, V2		# v2[0]
	addu $t7, $t7, $t6	# M[0][k*4]
	addu $t9, $t9, $t6	# v2[k*4]
	li $t6, 64	
	mult $t6, $t3		# 64*i
	mflo $t6
	addu $t7, $t7, $t6	# M[i][k*4]
	
for_j:					
	bge $t5, $t1, endj
	lw $t6, 0($t7)			# M[i][k*4+j]
	lw $t8, 0 ($t9)			# V2[k*4+j]
	mult $t6,$t8			
	mflo $t6
	addu $t4, $t4, $t6
	addiu $t9,$t9, 4
	addiu $t7, $t7, 4
	addiu $t5, $t5, 1
	b for_j
endj:
	lw $t8, 0($s0)
	addu $t8, $t8, $t4		# V1[i] += tmp
	sw $t8, 0($s0)
	addiu $s0, $s0, 4
	addiu $t3, $t3, 1
	b for_i
endi:
	addiu $t0, $t0, 1
	b for_k
endk:
	jr $ra
	