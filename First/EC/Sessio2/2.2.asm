	.data

result:	.word 0
num:	.byte ';'

	.text
	.globl main
main:
	la $t2, result
	la $t0, num
	lb $t0, 0($t0)
	li $t1, 'a'
	bltu $t0, $t1, if2
	li $t1, 'z'
	bleu $t0, $t1, then
if2:
	li $t1, 'A'
	bltu $t0, $t1, else
	li $t1, 'Z'
	bltu $t1, $t0, else
then:
	b end
else:
	li $t1, '0'
	bltu $t0, $t1, else2
	li $t1, '9'
	bltu $t1, $t0, else2
	
	li $t3, '0'
	subu $t0, $t0, $t3
	b end
else2:
	li $t0, -1
	
end:
	sw $t0, 0($t2)
	jr $ra
	