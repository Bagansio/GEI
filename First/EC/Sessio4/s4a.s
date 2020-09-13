	.data
signe:		.word 0
exponent:	.word 0
mantissa:	.word 0
cfixa:		.word 0x87D18A00	#0x87D18A00
cflotant:	.float 0.0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)

	la	$t0, cfixa
	lw	$a0, 0($t0)
	la	$a1, signe
	la	$a2, exponent
	la	$a3, mantissa
	jal	descompon

	la	$a0, signe
	lw	$a0,0($a0)
	la	$a1, exponent
	lw	$a1,0($a1)
	la	$a2, mantissa
	lw	$a2,0($a2)
	jal	compon

	la	$t0, cflotant
	
	swc1	$f0, 0($t0)
	li $v0, 2
	mov.s	$f12, $f0
	syscall
	
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr	$ra


descompon:
	
	slt $t1, $a0, $zero 		# signe = cf < 0
	sw $t1, 0($a1)
	sll $a0, $a0, 1			# cf = cf << 1    	 elimina el signe
	
	bne $a0, $zero, else		# si cf != 0 ir a else
	li $t1, 0			# exp = 0
	b end_comparations
else:
	li $t1 18			# exp = 18
	
while: blt $a0, $zero, end_while
	sll $a0, $a0, 1			# cf << 1		
	addi $t1, $t1, -1		# --exp
	b while
end_while:
	
	srl $a0, $a0, 8			# cf >> 8
	li $t2, 0x7FFFFF		# $t2 = 0x7FFFFF
	and $a0, $a0, $t2		# cf & 0x7FFFFF
	addi $t1, $t1, 127		# exp += 127

end_comparations:
	
	sw $t1, 0($a2) 			# *e = exp
	sw $a0, 0($a3)			# *m = cf
	jr $ra
	
compon:

	sll $a0, $a0, 31
	sll $a1, $a1, 23
	or  $v0,$a1, $a2
	or $v0, $v0, $a1
	mtc1 $v0, $f0
	jr $ra
	
	
# Comprova que el número resultant, en coma flotant, val cflotant=0xC6FA3140. 
# També pots comprovar el seu valor en decimal en el simulador. De quina manera ho consultaràs? 

# RESPOSTA: posaria 	mostra el float en decimal
	#li $v0, 2
	#mov.s	$f12, $f0
	#syscall
	
	
# Quin és el valor final de cflotant, en decimal, que dóna Mars?	
#  RESPOSTA: -32024.625

#Exercici 4.3
# DECIMAL		CFIXA		CFLOTANT
#    0		     0x0000000		0x00000000
#   -0		     0x8000000		0x00000000
#    12.75	     0x000CC00		0x414C0000


#EXERCICI 4.4
# 1) Quina condició ha de complir el valor inicial de cfixa perquè es produeixi 
# 	pèrdua de precisió en la conversió que proposa aquesta pràctica?
#RESPOSTA: tingui més xifres significatives que valors pogui contenir la mantisa -> 23

# 2) Indica un valor de cfixa per al qual es produiria pèrdua de precisió al 
#    convertir-lo, i el corresponent valor en coma flotant:
#	CFIXA				CFLOTANT
#	 0x
