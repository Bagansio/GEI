	.data
vec:	.word 0,0,0,0
v_sum:	.word	0,0			# 0,0 en el caso que no sea cierto
	
	.text
	.globl main
main:
	addiu $sp, $sp, -8
	sw $s0, 0($sp)
	sw $ra, 4($sp)
	
	la $a0, vec
	jal feed_vec
	
	la $a0, vec
	jal suma
	
	la $a0, vec
	move $a1, $v0
	move $s0, $v0
	jal bool
	
	beq $v0, $zero, end
	la $t0, v_sum
	sw $v0, 0($t0)
	sw $s0, 4($t0)	
end:
	lw $s0, 0($sp)
	lw $ra, 4($sp)
	jr $ra
	
		
	
feed_vec:			#funcion que me rellena los vec
	li $t0, 4
whilef:
	beq $t0, $zero endf
	li $v0, 5
	syscall
	sw $v0, 0($a0)
	addiu $a0, $a0, 4
	addiu $t0, $t0, -1
	b whilef
endf:
	jr $ra
	
	
	
suma:				#funcion que me devuelve la suma de los elementos del vec
				# $a0 = &vec
	li $t0,4
	move $v0, $zero
whiles:
	beq $t0, $zero, ends
	lw $t1, 0($a0)
	addu $v0, $v0, $t1
	addiu $a0, $a0, 4
	addiu $t0, $t0, -1
	b whiles
ends:
	jr $ra


bool:				#funcion que me devuelve true or false si hay un elemento que equivale a la suma del vec
				# $a0 = &vec	,	$a1 = suma
	li $t0, 4
	move $v0, $zero
	
whileb:
	bne $v0, $zero,endb
	beq $t0, $zero, endb

	lw $t1, 0($a0)
	addiu $a0, $a0, 4
	addiu $t0, $t0, -1
	beq $t1, $a1, if
	b whileb
if:
	addiu $v0, $v0, 1
	b whileb
endb:
	jr $ra
